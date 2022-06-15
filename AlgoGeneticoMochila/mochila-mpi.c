#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <mpi.h>
#include <omp.h>

#define MASTER 0

void randomizeInitialPopulation(int populationSize, int numItems, int** block) {
    int blockSize = populationSize * numItems;
    int* blockInternal = *block;
    for (int i = 0; i < blockSize; i++) {
        // Cuidado com isso aqui no paralelo...
        blockInternal[i] = rand() % 2;
    }
}

void mapBlockToMatrix(int** block, int*** population, int populationSize, int numItems) {
    int* blockInternal = *block;
    int** populationInternal = *population;
    for (int i = 0; i < populationSize; i++) {
        populationInternal[i] = &blockInternal[numItems*i];
    }
}

void printPopulation(int taskId, int populationSize, int numItems, int*** population) {
    int** populationInternal = *population;
    printf("TaskId %d population:\n", taskId);
    for (int i = 0; i < populationSize; i++) {
        for (int j = 0; j < numItems; j++) {
            printf("%d ", populationInternal[i][j]);
        }
        printf("\n");
    }
}

void calculateFitness(int values[], int weights[], int** element, int numItems, int weightLimit, int* result) {
    int* elementInternal = *element;

    int totalValue = 0;
    int totalWeight = 0;
    for (int i = 0; i < numItems; i++) {
        totalValue += elementInternal[i] * values[i];
        totalWeight += elementInternal[i] * weights[i];
    }

    if (totalWeight > weightLimit) {
        totalValue = 0;
    }
    *result = totalValue;
}

void calculateFitnessArray(
    int values[], 
    int weights[], 
    int*** population,
    int populationSize,
    int numItems,
    int weightLimit,
    int** result) {
    int** populationInternal = *population;
    int* resultInternal = *result;
    for (int i = 0; i < populationSize; i++) {
        int fitness;
        calculateFitness(values, weights, &populationInternal[i], numItems, weightLimit, &fitness);
        resultInternal[i] = fitness;
    }
}

void selectParents(int** fitnessArray, int populationSize, int result[]) {
    int* fitnessArrayInternal = *fitnessArray;
    for (int i = 0; i < 2; i++) {
        int candidate1Index = rand() % populationSize;
        int candidate2Index = rand() % populationSize;

        int candidate1Fitness = fitnessArrayInternal[candidate1Index];
        int candidate2Fitness = fitnessArrayInternal[candidate2Index];
        result[i] = (candidate1Fitness > candidate2Fitness) ? candidate1Index : candidate2Index;
    }
}

void mutate(int child[], int mutationRate, int numItems) {
    int roll = rand() % 100;
    if (roll <= mutationRate) {
        int index = rand() % numItems;
        child[index] = child[index] == 0 ? 1 : 0;
    }
}

void reproduce(int parentIndexes[], int*** population, int numItems, int child1[], int child2[], int mutationRate) {
    int half = numItems/2;
    int** populationInternal = *population;
    for (int j = 0; j < numItems; j++) {
        child1[j] = (j < half)
            ? populationInternal[parentIndexes[0]][j]
            : populationInternal[parentIndexes[1]][j];
    }
    for (int j = 0; j < numItems; j++) {
        child2[j] = (j < half)
            ? populationInternal[parentIndexes[1]][j]
            : populationInternal[parentIndexes[0]][j];
    }
    mutate(child1, mutationRate, numItems);
    mutate(child2, mutationRate, numItems);
}

void makeNextGeneration(int*** populationOld, int** blockOld, int** fitnessArray, int populationSize, int numItems, int mutationRate) {
    int* blockOldInternal = *blockOld;

    int blockSize = populationSize * numItems;
    int* newBlock = (int*) malloc(sizeof(int) * blockSize);
    int maxThreads = omp_get_num_procs();
    #pragma omp parallel for schedule(static, populationSize/maxThreads)
    for (int i = 0; i < populationSize; i++) {
        int parentIndexes[2];
        selectParents(fitnessArray, populationSize, parentIndexes);
        int child1[numItems];
        int child2[numItems];
        reproduce(parentIndexes, populationOld, numItems, child1, child2, mutationRate);
        memcpy(&newBlock[i++ * numItems], child1, sizeof(int)*numItems);
        memcpy(&newBlock[i * numItems], child2, sizeof(int)*numItems);
    }
    memcpy(blockOldInternal, newBlock, sizeof(int)*blockSize);
    free(newBlock);
}

void getMaxFitness(int** fitnessArray, int populationSize, int result[]) {
    int* fitnessArrayInternal = *fitnessArray;
    int max = 0;
    int maxIndex = -1;
    for (int i = 0; i < populationSize; i++) {
        int current = fitnessArrayInternal[i];
        if (current > max) {
            max = current;
            maxIndex = i;
        }
    }
    result[0] = max;
    result[1] = maxIndex;
}

void printArray(int * arr, int numElements, char* arrName) {
    printf("%s: [", arrName);
    for(int i = 0; i < numElements; i++) {
        if (i < 9) {
            printf("%d,", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("]\n");
}

// Taken from http://benpfaff.org/writings/clc/shuffle.html
void arrayShuffle(int* array, size_t n) {
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(int argc, char** argv) {
    double start = omp_get_wtime();
    srand(time(NULL));
    int taskId, ntasks;
    MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &taskId);
	MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    // Initial parameters
    int weightLimit = 30;
    int numItems = 10;
    int populationSize = 80000;
    int maxGenerations = 100000;
    float mutationRatePercentage = 10;
    int localSearchLimit = 5000;
    int values[] = {10, 15, 19, 20, 1, 2, 5, 3, 13, 17};
    int weights[] = {1, 5, 3, 9, 4, 1, 9, 2, 6, 7};
    
    // Initial setup
    int** population = (int**) malloc(sizeof(int*) * populationSize);
    int blockSize = populationSize * numItems;
    int* block = (int*) malloc(sizeof(int) * blockSize);
    int* fitnessArray = malloc (sizeof(int) * populationSize);
    if (taskId == MASTER) {
        randomizeInitialPopulation(populationSize, numItems, &block);
    }

    int partitionSize = (populationSize/ntasks);
    int partitionBlockSize = partitionSize * numItems;
    int* popBlockRecBuffer = (int*) malloc(sizeof(int) * partitionBlockSize);
    //printPopulation(taskId, partitionSize, numItems, &population);
    
    int currentMaxFitness[2];
    int* elite = (int*) malloc(sizeof(int) * numItems);
    for (int i = 0; i < maxGenerations; i++) {
        int remainder = (i + 1) % localSearchLimit;
        if (remainder == 1) {
            MPI_Scatter(&block[0], partitionBlockSize, MPI_INT, popBlockRecBuffer, partitionBlockSize, MPI_INT, MASTER, MPI_COMM_WORLD);
            mapBlockToMatrix(&popBlockRecBuffer, &population, partitionSize, numItems);
        }

        calculateFitnessArray(values, weights, &population, partitionSize, numItems, weightLimit, &fitnessArray);
        getMaxFitness(&fitnessArray, partitionSize, currentMaxFitness);
        //printf("Current max fitness: %d at index %d\n", currentMaxFitness[0], currentMaxFitness[1]);
        memcpy(elite, population[currentMaxFitness[1]], sizeof(int) * numItems);
        makeNextGeneration(&population, &popBlockRecBuffer, &fitnessArray, partitionSize, numItems, mutationRatePercentage);
        for (int i = 0; i < numItems; i++) {
            popBlockRecBuffer[i] = elite[i];
        }
        if (remainder == 0) {
            MPI_Gather(popBlockRecBuffer, partitionBlockSize, MPI_INT, block, partitionBlockSize, MPI_INT, MASTER,  MPI_COMM_WORLD);
            arrayShuffle(block, blockSize);
        }
    }
    if (taskId == MASTER) {
        mapBlockToMatrix(&block, &population, populationSize, numItems);
        calculateFitnessArray(values, weights, &population, populationSize, numItems, weightLimit, &fitnessArray);
        getMaxFitness(&fitnessArray, partitionSize, currentMaxFitness);
        double end = omp_get_wtime();
        printArray(population[currentMaxFitness[1]], numItems, "Maximized items: ");
        printf("Max value: %d\n", currentMaxFitness[0]);
        printf("Took %f\n", end-start);
    }
    free(fitnessArray);
    free(block);
    free(population);
    free(popBlockRecBuffer);
    free(elite);
    MPI_Finalize();
	return 0;
}
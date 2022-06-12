#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

void randomizeInitialPopulation(int populationSize, int numItems, int*** population, int** block) {
    int blockSize = populationSize * numItems;
    int* blockInternal = *block;
    int** populationInternal = *population;
    for (int i = 0; i < blockSize; i++) {
        // Cuidado com isso aqui no paralelo...
        blockInternal[i] = rand() % 2;
    }
    
    for (int i = 0; i < populationSize; i++) {
        populationInternal[i] = &blockInternal[numItems*i];
    }
}

void printPopulation(int populationSize, int numItems, int*** population) {
    int** populationInternal = *population;
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

int main(int argc, char** argv) {
    srand(time(NULL));
    // Initial parameters
    int weightLimit = 20;
    int numItems = 10;
    int populationSize = 2000;
    int maxGenerations = 1000;
    float mutationRatePercentage = 1;
    int values[] = {10, 15, 19, 20, 1, 2, 5, 3, 13, 17};
    int weights[] = {1, 5, 3, 9, 4, 1, 9, 2, 6, 7};
    
    // Initial setup
    int** population = (int**) malloc(sizeof(int*) * populationSize);
    int blockSize = populationSize * numItems;
    int* block = (int*) malloc(sizeof(int) * blockSize);
    int* fitnessArray = malloc (sizeof(int) * populationSize);
    randomizeInitialPopulation(populationSize, numItems, &population, &block);
    
    int currentMaxFitness[2];
    for (int i = 0; i < maxGenerations; i++) {
        calculateFitnessArray(values, weights, &population, populationSize, numItems, weightLimit, &fitnessArray);
        getMaxFitness(&fitnessArray, populationSize, currentMaxFitness);
        //printf("Current max fitness: %d at index %d\n", currentMaxFitness[0], currentMaxFitness[1]);
        makeNextGeneration(&population, &block, &fitnessArray, populationSize, numItems, mutationRatePercentage);
    }
    printArray(population[currentMaxFitness[1]], numItems, "Maximized items: ");
    free(fitnessArray);
    free(block);
    free(population);
	return 0;
}
#include <complex>
#include <iostream>
#include <mpi.h>
#include <omp.h>

#define MASTER 0 
#define MSG_TAG 0 

using namespace std;

void logParameters(int* parameters, int taskId) {
	cout << "TaskID: ";
	cout << taskId;
	cout << " Received parameters: ";
	for (int i = 0; i< 3; i++) {
		cout << parameters[i];
		cout << " ";
	}
	cout << '\n';
}

void logMandelbrotSet(int maxRows, int maxColumns, char** mat) {
	for(int r = 0; r < maxRows; ++r) {
		for(int c = 0; c < maxColumns; ++c) {
			cout << mat[r][c];
		}
		cout << '\n';
	}
}

void calculateMandelbrot(char** mat, int sliceMinRow, int sliceMaxRow, int maxRow, int maxColumn, int maxN, int numThreads, bool multiThreads) {
	int rowsToExecute = sliceMaxRow - sliceMinRow;
	#pragma omp parallel for schedule(dynamic) num_threads(numThreads) if(multiThreads)
	for(int r = 0; r < rowsToExecute; ++r){
		for(int c = 0; c < maxColumn; ++c){
			complex<float> z;
			int n = 0;
			int offsetR = sliceMinRow + r;
			while(abs(z) < 2 && ++n < maxN)
				z = pow(z, 2) + decltype(z)(
					(float)c * 2 / maxColumn - 1.5,
					(float)offsetR * 2 / maxRow - 1
				);
			mat[r][c]=(n == maxN ? '#' : '.');
		}
	}
}

void gatherMatrix(char** scatteredMatrix, char*** gatheredMatrix, int maxRows, int maxColumns, int nTasks) {
	char *recvBuffer = (char*)malloc(sizeof(char)*maxRows*maxColumns);
	MPI_Gather(&scatteredMatrix[0][0], (maxRows/nTasks)*maxColumns, MPI_CHAR, &recvBuffer[0], (maxRows/nTasks)*maxColumns, MPI_CHAR, MASTER, MPI_COMM_WORLD);
	for (int i=0; i<maxRows;i++) {
		*gatheredMatrix[i] = &recvBuffer[maxColumns*i];
	}
	free(recvBuffer);
}

int main(int argc, char** argv){
	double starttime, endtime;
	int taskId, ntasks;
	int parameters[3];
	int numThreads = 4;
	bool multiThreads = false;
	if (argc >= 2 && strcasecmp(argv[1], "/t") == 0) {
		multiThreads = true;
	}

	if (multiThreads == true && argc >= 3) {
		numThreads = atoi(argv[2]);
	}
	starttime = MPI_Wtime();
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &taskId);
	MPI_Comm_size(MPI_COMM_WORLD, &ntasks);

	if (taskId == MASTER) {
		cin >> parameters[0]; // max_row
		cin >> parameters[1]; // max_column
		cin >> parameters[2]; // max_n;
	}

	MPI_Bcast(parameters, 3, MPI_INT, MASTER, MPI_COMM_WORLD);

	int max_row = parameters[0];
	int max_column = parameters[1];
	int max_n = parameters[2];

	logParameters(parameters, taskId);

	int rowsToExecute = max_row / ntasks; 
	int sliceMinRow = taskId * rowsToExecute;
	int sliceMaxRow = sliceMinRow + rowsToExecute; // Non inclusive
	
	// Alocação em bloco
	char **mat = (char**)malloc(sizeof(char*)*rowsToExecute);
	char *block = (char*)malloc(sizeof(char)*rowsToExecute*max_column);
	for (int i=0; i<rowsToExecute;i++) {
		mat[i]= &block[max_column*i];
	}
	calculateMandelbrot(mat, sliceMinRow, sliceMaxRow, max_row, max_column, max_n, numThreads, multiThreads);
	char** gatheredMatrix = (char**) malloc(sizeof(char*)*max_row);

	char *recvBuffer = (char*)malloc(sizeof(char)*max_row*max_column);
	MPI_Gather(&mat[0][0], (max_row/ntasks)*max_column, MPI_CHAR, &recvBuffer[0], (max_row/ntasks)*max_column, MPI_CHAR, MASTER, MPI_COMM_WORLD);
	for (int i=0; i< max_row;i++) {
		gatheredMatrix[i] = &recvBuffer[max_column*i];
	}

	int rem = max_row % ntasks;
	cout << "Residual: ";
	cout << rem;
	cout << '\n';
	if (taskId == MASTER && rem > 0) {
		calculateMandelbrot(&gatheredMatrix[max_row-rem], max_row-rem, max_row, max_row, max_column, max_n, numThreads, multiThreads);
	}

	if (taskId == MASTER) {
		endtime = MPI_Wtime();
		cout << "Runtime = ";
		cout << endtime-starttime;
		cout << '\n';
		logMandelbrotSet(max_row, max_column, gatheredMatrix);
	}
	free(mat);
	free(block);
	free(gatheredMatrix);
	free(recvBuffer);
	MPI_Finalize();
	return 0;
}



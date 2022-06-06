#include <complex>
#include <iostream>
#include <omp.h>

using namespace std;

// Usei passagem de parâmetro via arg e argv no meu script, mas estou alterando de volta para cin
// Para o professor executar da maneira original, caso queira. A versão compilada no entregável usa argc/argv.
int main(){
	int max_row, max_column, max_n;
	// max_row = atoi(argv[1]);
	// max_column = atoi(argv[2]);
	// max_n = atoi(argv[3]);

	cin >> max_row;
	cin >> max_column;
	cin >> max_n;

	char **mat = (char**)malloc(sizeof(char*)*max_row);

	for (int i=0; i<max_row;i++)
		mat[i]=(char*)malloc(sizeof(char)*max_column);

	double start  = omp_get_wtime();

	#pragma omp parallel for schedule(runtime)
    for(int r = 0; r < max_row; ++r){
        for(int c = 0; c < max_column; ++c){
            //para cada celula da matriz
            complex<float> z;
			int n = 0;
			while(abs(z) < 2 && ++n < max_n)
				z = pow(z, 2) + decltype(z)(
					(float)c * 2 / max_column - 1.5,
					(float)r * 2 / max_row - 1
				);
			mat[r][c]=(n == max_n ? '#' : '.');
		}
	}

	double end = omp_get_wtime();
	std::cout<<end-start;
	cout<< '\n';
	// for(int r = 0; r < max_row; ++r){
	// 	for(int c = 0; c < max_column; ++c)
	// 		std::cout << mat[r][c];
	// 	cout << '\n';
	// }	
}



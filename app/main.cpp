#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <cmath>


float det(float **m, int n){
    float pivote, pivote1, determinante,aux;
    for(int i = 0; i < n; i++){
        pivote = m[i][i];
        for(int j = i+1; j<n; j++){
            pivote1 = m[j][i];
            aux = pivote1/pivote;
            for(int k = 0; k < n; k++){
                m[j][k]=m[j][k]-aux*m[i][k];
            }
        }
    }

    for(int i = 0; i < n; i ++){
        determinante*=m[i][i];
    }
    return determinante;
}


int main(void){
    int n,a,b;
    float **matriz = (float **)malloc(n * sizeof(float *));

    std::cout << "Elija orden de la matriz: ";
    std::cin >> n;
    std::cout << "INF: ";
    std::cin >> a;
    std::cout << "SUP: ";
    std::cin >> b;
    for(int i = 0; i < n; i++){
        matriz[i] = (float *)malloc(n* sizeof(float *));
    }

    srand(time(NULL));

    for(int y = 0; y < n; y++){
        for(int w = 0; w<n; w++){
            matriz[y][w] = rand() * ((float)b- (float)a) / (float)RAND_MAX;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout << matriz[i][j] << " - ";
        }
        std::cout << std::endl;
    }
    float d= det(matriz,n);
    std::cout << "Determinante: " << d;
    std::cout << std::endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout << matriz[i][j] << " - ";
        }
        std::cout << std::endl;
    }

    return 0;
}
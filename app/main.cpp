#include <iostream>
#include <sys/time.h>
#include <stdlib.h>

long long determinante(long** matriz, int);


void llenarMatriz(long** matriz, int orden, int inferior, int superior);
int main(int argc, char** argv)
{
    long **matriz = NULL;
    int orden = atoi(argv[1]);
    int inferior = atoi(argv[2]);
    int superior = atoi(argv[3]);

    matriz=(long **)malloc(orden * sizeof(long *));
    for(int i = 0; i < orden; i++){
        matriz[i] = (long *)malloc(orden * sizeof(long *));
    }
    llenarMatriz(matriz, orden, inferior, superior);

    struct timeval begin, end;

    gettimeofday(&begin, 0);

    long long det = determinante(matriz, orden);

    gettimeofday(&end, 0);

    long segundos = end.tv_sec - begin.tv_sec;
    long microsegundos = end.tv_usec - begin.tv_usec;
    double elapsed = segundos + microsegundos*1e-6;

    std::cout << orden << "\t" << elapsed << std::endl;
    delete matriz;
    return 0;
}


void llenarMatriz(long** matriz, int orden, int inferior, int superior){
    srand(time(NULL));
    for(int i = 0; i < orden; i ++){
        for(int j = 0; j < orden; j ++){
            matriz[i][j] = rand() % 100;
        }
    }
}

long long determinante(long** matriz, int orden){
    int i, j, k;
    long long det;
    int factor;

    if(orden == 1){
        return matriz[0][0];
    } else if(orden == 2){
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }
    for (k = 0; k < orden-1; k++){
        for(i = k+1; i < orden; i++){
            factor = matriz[i][k]/matriz[k][k];
            for (j = k+1; j < orden; j++){
                matriz[i][j] = matriz[i][j] - factor * matriz[k][j];
            }
        }
    }
    det = 1;
    for(i = 0; i < orden; i ++){
        det = det * matriz[i][i];
    }

    return det;
    
} 



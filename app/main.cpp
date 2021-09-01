#include <iostream>
#include <sys/time.h>
#include <stdlib.h>

#define MAX 800
int determinante(int matriz[][MAX], int);


void llenarMatriz(int matriz[][MAX], int orden, int inferior, int superior);
int main(int argc, char** argv)
{
    int matriz[MAX][MAX];
    int orden = atoi(argv[1]);
    int inferior = atoi(argv[2]);
    int superior = atoi(argv[3]);
    llenarMatriz(matriz, orden, inferior, superior);

    struct timeval begin, end;

    gettimeofday(&begin, 0);

    int det = determinante(matriz, orden);

    gettimeofday(&end, 0);

    long segundos = end.tv_sec - begin.tv_sec;
    long microsegundos = end.tv_usec - begin.tv_usec;
    double elapsed = segundos + microsegundos*1e-6;

    std::cout << orden << "\t" << elapsed << std::endl;
    return 0;
}


void llenarMatriz(int matriz[][MAX], int orden, int inferior, int superior){
    srand(time(NULL));
    for(int i = 0; i < orden; i ++){
        for(int j = 0; j < orden; j ++){
            matriz[i][j] = rand() % 100;
        }
    }
}

int determinante(int matriz[][MAX], int orden){
    int det = matriz[0][0];

    for(int k = 0;k < orden-1;k++)
    {
        int l = k + 1;
        for(int i = l; i <orden; i++)
        {
            for(int j = l; j <orden; j++)
            {
                matriz[i][j] = (matriz[k][k] * matriz[i][j] - matriz[k][j] * matriz[i][k]) / matriz[k][k];
            }
            det = det * matriz[k+1][k+1];
        } 
    }
    return det;
} 



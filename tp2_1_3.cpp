#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));
    int i,j;
    int filas =15, cantidad_pares;
    int columnas = 5 + rand()%11;
    int arreglo[filas][columnas],pares[filas];
    int *ptr_arreglo = &arreglo[0][0];

    for (i=0;i<filas;i++){
        for (j=0;j<columnas;j++){
            *(ptr_arreglo+i*columnas+j)=100 + rand()%900;
            printf("%d ",*(ptr_arreglo+i*columnas+j));
        }
        printf("\n");
    }

    
    for (i=0;i<filas;i++){
        cantidad_pares=0;
        for (j=0;j<columnas;j++){
            if (*(ptr_arreglo+i*columnas+j)%2==0){
                cantidad_pares++;
            }
        *(pares+i)=cantidad_pares;    
        }   
    }

    for (i=0;i<filas;i++){
        printf("%d ",*(pares+i));
    }

    getchar();
    return 0;
}
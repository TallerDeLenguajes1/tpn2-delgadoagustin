#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int velocidad, anio, cantidad;
    char *tipo_cpu;
}compu;

compu crearPC(char *tipos);
void cargarArreglo(compu *ptr, int cantidad, char *tipos);
void mostrarArreglo(compu *ptr, int cantidad);
void pcVieja(compu *ptr,int cantidad);
void pcRapida(compu *ptr,int cantidad);

int main(){
    srand(time(NULL));
    int cantidad;
    char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    char *ptr_tipos = &tipos[0][0];
    printf("Ingresa la cantidad de PCs: ");
    scanf("%d",&cantidad);

    fflush(stdout);

    compu *arreglo = (compu*)malloc(cantidad*sizeof(compu));

    cargarArreglo(arreglo,cantidad,ptr_tipos);
    mostrarArreglo(arreglo,cantidad);
    pcVieja(arreglo, cantidad);
    pcRapida(arreglo, cantidad);



    free(arreglo);
    
    return 0;
}

compu crearPC(char *tipos){
    compu PC;
    PC.velocidad = 1+rand()%3;
    PC.anio = 2000+rand()%18;
    PC.cantidad = 1+rand()%3;
    PC.tipo_cpu = tipos+(rand()%6*10);
    return PC;
}

void cargarArreglo(compu *ptr, int cantidad, char *tipos){
    for (int i = 0; i < cantidad; i++){
        *(ptr+i)=crearPC(tipos);
        printf("%d",i);
    }
    
}

void mostrarArreglo(compu *ptr, int cantidad){
    for (int i = 0; i < cantidad; i++){
        printf("\nPC %d: \nVelocidad: %d Gherz\nAnio: %d\nNucleos: %d\nTipo: %s\n",i,(ptr+i)->velocidad,(ptr+i)->anio,(ptr+i)->cantidad,(ptr+i)->tipo_cpu);
    }
}

void pcVieja(compu *ptr,int cantidad){
    int anio=2020, aux;
    for (int i = 0; i < cantidad; i++){
        if((ptr+i)->anio<anio){
            anio = (ptr+i)->anio;
            aux = i;
        }
    }
    printf("\nPC mas vieja\nPC %d: \nVelocidad: %d Gherz\nAnio: %d\nNucleos: %d\nTipo: %s\n",aux,(ptr+aux)->velocidad,(ptr+aux)->anio,(ptr+aux)->cantidad,(ptr+aux)->tipo_cpu);
}

void pcRapida(compu *ptr,int cantidad){
    int vel=0, aux;
    for (int i = 0; i < cantidad; i++){
        if((ptr+i)->velocidad>vel){
            vel = (ptr+i)->velocidad;
            aux = i;
        }
    }
    printf("\nPC mas rapida\nPC %d: \nVelocidad: %d Gherz\nAnio: %d\nNucleos: %d\nTipo: %s\n",aux,(ptr+aux)->velocidad,(ptr+aux)->anio,(ptr+aux)->cantidad,(ptr+aux)->tipo_cpu);
}
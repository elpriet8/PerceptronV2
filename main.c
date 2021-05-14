//
//  main.c
//  
//
//  Created by Diego Prieto on 13/05/21.
//

#include <stdio.h>

#include "dataset.h"
#include "weights_module.h"
#include "perceptron_module.h"

void showArray(float **array,int filas, int cols);

int main (void){

    char datafile[] = "DatasetV2.csv";
    int columnas = 1,filas = 0;
    float learningRate = .99;
    int itn;
    
    float **array = NULL;
    float **weights = NULL;
    float *error = NULL;
    float *prediction = NULL;
        
    FILE *fp;
    
    fp = fopen(datafile, "r");
    if(fp==NULL){
        printf("Error al abrir archivo");
        exit(1);
    }
    
    printf("Iteraciones [Entero]: ");
    scanf(" %i", &itn);
    
    
    // get dataset dimensions
    getMatrixSize(&filas,&columnas,fp);
    
    // Allocate memory
    array = allocateArrayMem(&filas,&columnas);
    error = malloc((itn)*sizeof(float));
    prediction = malloc((itn)*sizeof(float));
    
    // relocate file pointer, fill dataset array
    rewind(fp);
    toFloat(array, &filas, &columnas, fp);
    fclose(fp);
    
    // Allocate memory weights array
    weights = allocateArrayMem(&filas,&columnas);
    
    // init weights array rand 0-1
    init_weights_array(filas, columnas, weights);
    
    // p2p product x1w1
    hebbian_start(learningRate, weights, array, itn, filas,columnas,error,prediction);
    
    
    // Free memory
    free(array);
    free(weights);
    free(error);
    free(prediction);
}

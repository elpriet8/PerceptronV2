//
//  results.c
//  
//
//  Created by Diego Prieto on 14/05/21.
//

#include "results.h"
#include <stdlib.h>
#include <stdio.h>

void push_error(float *error_array, int iteration, float error){
    error_array[iteration] = error;
}

void push_prediction(float *prediction_array, int iteration, float prediction){
    prediction_array[iteration] = prediction;
}

void printfToFile(float *prediction_array, float *error_array ,int size){
    
    FILE *fp1,*fp2;
    
    fp1 = fopen("errors.csv","w");
    if(fp1 == NULL){
        printf("ERROR AL GUARDAR");
        exit(1);
    }
    
    fp2 = fopen("predictions.csv","w");
    if(fp2 == NULL){
        printf("ERROR AL GUARDAR");
        exit(1);
    }
    
    for(int i = 0;i < size; i++){
        fprintf(fp1,"%i \t %f\n",i,error_array[i]);
        fprintf(fp2,"%i \t %f\n",i,prediction_array[i]);
    }
    
    
    printf("Archivo: errors.csv generado");
    fclose(fp1);
    fclose(fp2);
    
    plotError();
}

void plotError(){
    char * gnupConfig[] = {"set xrange [0:70]", "plot 'errors.csv' using 1:2 with lines title 'Error RMS'"};
    
    FILE * gnupWindow = popen ("gnuplot -persist", "w");
    for(int i=0; i < 2; i++){
        fprintf(gnupWindow, "%s \n", gnupConfig[i]);
    }
}

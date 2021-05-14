//
//  perceptron_module.c
//  
//
//  Created by Diego Prieto on 13/05/21.
//

#include "perceptron_module.h"
#include "target_array.h"
#include "results.h"

float calculate_y(float **dataset_array, float **weights_array, int fila_actual,int columnas){
    
    float y = 0;
    int x = 0;
    
    for(int f = fila_actual; f<fila_actual+7;f++){
        for(int i = 0; i < columnas; i++){
            y += dataset_array[f][i] * weights_array[f][i];
        }
    }
    
    return y;
}

float sigmoid(float y){
    return 1/(1+exp(-y));
}

float error_RMS(float learningRate, float y,int fila_actual, int columnas){
    return 1 / ( learningRate * (sqrt(pow(y-target_array[fila_actual],2))));
}

float sigmoid_derivada(float y){
    return exp(-y)/(pow(1+exp(-y),2));
}

void update_weigh(float **weights_array, float **dataset_array,float learningRate,int fila_actual,int columnas,float y,float error){
    
    for(int f = fila_actual; f<fila_actual+7;f++){
        for(int i = 0; i < columnas; i++){
            
            weights_array[f][i] = weights_array[f][i] + learningRate*(sigmoid_derivada(y))*(dataset_array[f][i]*error);
        }
    }
}

void hebbian_start(float learningRate, float **weights_array, float **dataset_array, int iterations, int filas,int columnas, float *error_array, float *predict_array){
    
    float average = 0;
    
    for(int itn = 0; itn < iterations; itn++){
        
        float y = 0;
        float rms = 0;

        for(int fila = 0; fila < filas-7; fila+=7){
        
        // Update Y
            y = calculate_y(dataset_array,weights_array,fila,columnas);

        // Get prediction
            y = sigmoid(y);
            //printf(" %f\n", y);
        
        // Get Error RMS
            rms = error_RMS(learningRate, y, fila,columnas);
        
        // Update weights
            update_weigh(weights_array,dataset_array,learningRate,fila,columnas,y,rms);
        
        // average error per batch
            average += rms;
        }
        
        push_error(error_array,itn,average/filas);
        push_prediction(predict_array,itn,y);
        //printf("Error Promedio: %f", average/filas);
        average = 0;
        //showArray(weights_array,filas,columnas);
    }
    printfToFile(predict_array, error_array, iterations);
}

void showArray(float **array,int filas, int cols){
    
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            printf(" %f,",array[i][j]);
        }
        printf("\n");
    }
    
}

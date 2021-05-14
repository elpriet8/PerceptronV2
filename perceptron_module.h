//
//  perceptron_module.h
//  
//
//  Created by Diego Prieto on 13/05/21.
//

#ifndef perceptron_module_h
#define perceptron_module_h

#include <stdio.h>
#include <math.h>
float calculate_y(float **dataset_array, float **weights_array, int fila_actual,int columnas);

float sigmoid(float y);

float error_RMS(float learningRate, float y,int fila_actual, int columnas);

float sigmoid_derivada(float y);

void update_weigh(float **weights_array, float **dataset_array,float learningRate,int fila_actual,int columnas,float y,float error);

void hebbian_start(float learningRate, float **weights_array, float **dataset_array, int iterations, int filas,int columnas, float *error_array, float *predict_array);

void showArray(float **array,int filas, int cols);

#endif /* perceptron_module_h */

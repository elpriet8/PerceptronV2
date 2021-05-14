//
//  results.h
//  
//
//  Created by Diego Prieto on 14/05/21.
//

#ifndef results_h
#define results_h

#include <stdio.h>

void push_error(float *error_array, int iteration, float error);

void push_prediction(float *prediction_array, int iteration, float prediction);

void printfToFile(float *prediction_array, float *error_arrayint, int size);

void plotError();


#endif /* results_h */

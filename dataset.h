//
//  dataset.h
//  
//
//  Created by Diego Prieto on 13/05/21.
//

#ifndef dataset_h
#define dataset_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getMatrixSize(int *filas,int *columnas,FILE *fp);
float* allocateArrayMem(int *filas,int *columnas);
float stringtofloat(char *line,int *position);
void toFloat(float **array,int *filas, int *columnas,FILE *fp);
void toArray(float **array,float *number,int *curfila,int *curcol,int *filas, int *columnas);


#endif /* dataset_h */

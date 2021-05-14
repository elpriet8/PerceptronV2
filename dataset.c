//
//  dataset.c
//  
//
//  Created by Diego Prieto on 13/05/21.
//

#include "dataset.h"

void getMatrixSize(int *filas,int *columnas,FILE *fp){
    char line[1024];
    char start = '0';
    
    while((fgets(line,sizeof(line),fp))){
        // Count Columns just once
        if(start == '0'){
            for(int i = 0;i<strlen(line);i++){
                if(line[i] == ','){
                    *columnas = *columnas + 1;
                }
            }
            start = '1';
        }
        // Add to row count
        *filas = *filas+1;
    }
}

float* allocateArrayMem(int *filas,int *columnas){
    float **array = (float**)malloc((*filas)*sizeof(float*));
    for(int i=0;i<(*filas);i++){
            array[i] = (float*)malloc((*columnas)*sizeof(float));
    }
    return array;
}

void toFloat(float **array,int *filas, int *columnas,FILE *fp){
    float num;
    char line[256];
    int curfila = 0;
    
    while((fgets(line,sizeof(line),fp))){
        int position = 0;
        for(int i=0;i<*columnas;i++){
            num = stringtofloat(line,&position);
            position++;
            toArray(array,&num,&curfila,&i,filas,columnas);
        }
        curfila++;
    }
}

float stringtofloat(char *line,int *position){
    char number[21];
    float num;
    int n= 0;
    
    for(int p=*position; p<strlen(line); p++){
        if(line[p] > 29 && line [p] <58){
        if(line[p] != ','){
            number[n]= line[p];
            n++;
        }else{
            *position = p;
            return strtof(number,NULL);
        }
        }
    }
    return strtof(number,NULL);
}

void toArray(float **array,float *number,int *curfila,int *curcol,int *filas, int *columnas){
    array[*curfila][*curcol] = *number;
}

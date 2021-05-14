//
//  weights_module.c
//  
//
//  Created by Diego Prieto on 13/05/21.
//

#include "weights_module.h"

void init_weights_array(int filas, int columnas, float **weights){
    int elems = filas*columnas;
    float num = 0;
        
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            weights[i][j] = (float)rand() / (float)((unsigned)RAND_MAX + 1);
        }
    }
}



#include "bobinas.h"
#include "tick.h"

static uint8_t *pasos;



void bobinasCreate(uint8_t *direccion){
    pasos=direccion;
    *pasos=0b0000;
}

void activoUnaBobina(uint8_t numeropaso){
    if (numeropaso>0 && numeropaso<=4){
        *pasos=1<<numeropaso-1;
    }
}

//funcion que activaria las bobinas en sentido de las agujas del reloj 
void secuenciaCW(uint8_t numeropaso){
    if (numeropaso==4){
        *pasos=0b0001;
    }
    else *pasos=1<<numeropaso;
    
}
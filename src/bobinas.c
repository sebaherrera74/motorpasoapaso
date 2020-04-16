#include "bobinas.h"
#include "tick.h"

static uint8_t *pasos;



void bobinasCreate(uint8_t *direccion){
    pasos=direccion;
    *pasos=0b0000;
}

void activoUnaBobina(uint8_t numeropaso){
     *pasos=1<<numeropaso-1;
}

void secuenciaCW(uint8_t numeropaso){
    *pasos=1<<numeropaso;
    
}
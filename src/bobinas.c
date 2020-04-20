#include "bobinas.h"
#include "tick.h"

//  Secuencia de sentido horario 
//             bobina A   bobina B   bobina C  bobina D    
// numero paso
//  paso 1         0         0         0         1 
//  paso 2         0         0         1         0
//  paso 3         0         1         0         0 
//  paso 4         1         0         0         0




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
void secuenciaCW(int veloc,uint8_t cantPasos){
    uint8_t aux=0;
    uint16_t i;
    for (i=0;i<cantPasos;i++){
        aux=(4+i)%4;
        activoUnaBobina(aux+1);
        }
        velocidadGiro(veloc);
}

//funcion que activaria las bobinas en sentido contrario de las agujas del reloj 
void secuenciaCCW(int veloc,uint8_t cantPasos){
    uint8_t aux=0;
    uint16_t i;
    for (i=0;i<=cantPasos;i++){
        aux=(4-i)%4;
        activoUnaBobina(aux+1);
        }
        velocidadGiro(veloc);
}
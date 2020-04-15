#include "bobinas.h"
#include "tick.h"

static uint8_t *pasos;
uint8_t secuenciaPasos[4][4]={
    {1,0,0,0},
	{0,1,0,0},
	{0,0,1,0},
	{0,0,0,1}
};


void bobinasCreate(uint8_t *direccion){
    pasos=direccion;
    *pasos=0b0000;
}

void activoUnaBobina(uint8_t numeropaso){
     *pasos=1<<numeropaso-1;
}

void secuenciaCW(int velocidad){
    
}
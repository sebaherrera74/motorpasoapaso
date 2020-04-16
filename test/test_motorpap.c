
/*
-Cuando se inicaliza la librería las cuatro bobinas estan sin energía 

Cuando se pone a funcionar el motor en una dirección entonces una 
de las salidas se pone en uno
-Despues de x llamadas a la funcion de tic la salida en uno cambia a la siguiente.
*/

#include "unity.h"

#include "bobinas.h"
#include "tick.h"


void setUp(void){

}

void tearDown(void){

}

void test_InicializacionBobinas(void){
    uint8_t gpioVirtuales=0xF;             //A los gpio(4) y los pongo en 1 
    bobinasCreate(&gpioVirtuales);         //funcion de creacion de las bobinas le paso la direccion de los gpio  
    TEST_ASSERT_EQUAL(0,gpioVirtuales);  

}

void test_ActivoSalidaUnaBobina(void){
    uint8_t gpioVirtuales;
    uint8_t numeroPaso=1;                   //variable numeo de pasos, son 4 pasos en el motor
                                            //unipolar en secuencia simple 

    bobinasCreate(&gpioVirtuales);   
    activoUnaBobina(numeroPaso);
    TEST_ASSERT_EQUAL(0b0001,gpioVirtuales);
}

void test_TiempoActivacionBobina(void){
    int velocidad=50;
    velocidadGiro(velocidad);
    TEST_ASSERT_EQUAL(true,velocidadGiro(velocidad));
}

void test_secuenciaClockWise(void){
    int velocidad=100;
    uint8_t numeroPaso=0;
    uint8_t gpioVirtuales;
    bobinasCreate(&gpioVirtuales);   
    activoUnaBobina(numeroPaso);
    velocidadGiro(velocidad);
    secuenciaCW(numeroPaso);
    TEST_ASSERT_EQUAL(0b0001,gpioVirtuales);    

}
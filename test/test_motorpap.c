
/*
-Cuando se inicaliza la librería las cuatro bobinas estan sin energía 

Cuando se pone a funcionar el motor en una dirección entonces una 
de las salidas se pone en uno
-Despues de x llamadas a la funcion de tic la salida en uno cambia a la siguiente.
*/

#include "unity.h"

#include "bobinas.h"


void setUp(void){

}

void tearDown(void){

}

void test_InicializacionBobinas(void){
    uint8_t gpioVirtuales=0xF;             //indica los gpio(4) y los pongo en 1 
    bobinasCreate(&gpioVirtuales);         //crea la funcion de creacion de las bobinas le paso la direccion de los gpio  
    
    TEST_ASSERT_EQUAL(0,gpioVirtuales);  

}


void test_ActivoSalidaUnaBobina(void){
    uint8_t gpioVirtuales;
    
    activoUnaBobina(4);
    TEST_ASSERT_EQUAL(8,gpioVirtuales);
}
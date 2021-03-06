
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

//Test de Inicializacion de las salidas a bobinas y puestas a cero
void test_InicializacionBobinas(void){
    uint8_t gpioVirtuales=0xF;             //A los gpio(4) y los pongo en 1 
    bobinasCreate(&gpioVirtuales);         //funcion de creacion de las bobinas le paso la direccion de los gpio  
    TEST_ASSERT_EQUAL(0,gpioVirtuales);  
}

//Test de prueba de activar las bobinas en funcion del paso 
void test_ActivoSalidaUnaBobina(void){
    uint8_t gpioVirtuales;
    uint8_t numeroPaso=4;                   //variable numeo de pasos, son 4 pasos en el motor2
                                            //unipolar en secuencia simple 

    bobinasCreate(&gpioVirtuales);   
    activoUnaBobina(numeroPaso);
    TEST_ASSERT_EQUAL(0b1000,gpioVirtuales);
}

//Test de prueba de velocidad
void test_TiempoActivacionBobina(void){
    int velocidad=50;
    velocidadGiro(velocidad);
    TEST_ASSERT_EQUAL(true,velocidadGiro(velocidad));
}

// Test Secuencia en sentido de las agujas del reloj 
void test_secuenciaClockWise(void){
    int velocidad=100;
    uint8_t cantidadPasos=2;
    uint8_t gpioVirtuales;
    bobinasCreate(&gpioVirtuales);   
    secuenciaCW(velocidad,cantidadPasos); //funcion secuencia sentido agujas del reloj
    TEST_ASSERT_EQUAL(0b0010,gpioVirtuales);    

}
//Test Secuencia en sentido inverso 
void test_secuenciaInverClockWise(void){
    int velocidad=100;
    uint8_t cantidadPasos=4;
    uint8_t gpioVirtuales;
    bobinasCreate(&gpioVirtuales);   
    secuenciaCCW(velocidad,cantidadPasos); //funcion secuencia sentido agujas del reloj
    TEST_ASSERT_EQUAL(0b0001,gpioVirtuales);    
}

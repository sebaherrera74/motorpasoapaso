#include "build/temp/_test_motorpap.c"
#include "src/tick.h"
#include "src/bobinas.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"






void setUp(void){



}



void tearDown(void){



}



void test_InicializacionBobinas(void){

    uint8_t gpioVirtuales=0xF;

    bobinasCreate(&gpioVirtuales);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((gpioVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);



}



void test_ActivoSalidaUnaBobina(void){

    uint8_t gpioVirtuales;

    uint8_t numeroPaso=1;





    bobinasCreate(&gpioVirtuales);

    activoUnaBobina(numeroPaso);

    UnityAssertEqualNumber((UNITY_INT)((0b0001)), (UNITY_INT)((gpioVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}

void test_TiempoActivacionBobina(void){

    int velocidad=50;

    velocidadGiro(velocidad);

    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((velocidadGiro(velocidad))), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);



}



void test_secuenciaClockWise(void){

    int velocidad=100;

    uint8_t gpioVirtuales;

    bobinasCreate(&gpioVirtuales);

    secuenciaCW(velocidad);

    UnityAssertEqualNumber((UNITY_INT)((0b0010)), (UNITY_INT)((gpioVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);



}

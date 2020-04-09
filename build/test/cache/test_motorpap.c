#include "build/temp/_test_motorpap.c"
#include "src/bobinas.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"






void setUp(void){



}



void tearDown(void){



}



void test_InicilizacionBobinas(void){

    uint8_t gpioVirtuales=0xF;

    bobinasCreate(&gpioVirtuales);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((gpioVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}

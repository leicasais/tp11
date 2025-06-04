#ifndef HARDWARE_H
#define HARDWARE_H

//Librerias externas 
#include <stdint.h>

//Mapeo LED fisico (GPIO)
#define LED_0 17
#define LED_1 4
#define LED_2 18
#define LED_3 23
#define LED_4 24
#define LED_5 25
#define LED_6 22
#define LED_7 27

typedef struct{//Funciona para little endian
    uint8_t led_0 :1;
    uint8_t led_1 :1;
    uint8_t led_2 :1;
    uint8_t led_3 :1;
    uint8_t led_4 :1;
    uint8_t led_5 :1;
    uint8_t led_6 :1;
    uint8_t led_7 :1;

}bits_t;

typedef union{
	 bits_t leds;
	 uint8_t puerto;
}leds_t;



#define BITSET(puerto, n) ((puerto)=(TAMANO((puerto),((puerto) | (1<<(n)))))) /*Prende el bit indicado sin modificar el resto del registro*/
#define BITCLR(puerto, n) ((puerto)=(TAMANO((puerto),((puerto) & (~(1<<(n)))))))/*Apaga el bit indicado sin modificar el resto del registro*/
#define BITGET(puerto, n) ((puerto),(((puerto)>>(n)) && 1))/*Muestra si el bit indicado está prendido o apagado*/
#define BITTOGGLE(puerto, n) ((puerto)=(TAMANO((puerto),((puerto)^(1<<(n))))))/*Intercambia el estado del bit indicado sin modificar el resto del registro*/
#define MASKON(puerto, mask) ((puerto)=(TAMANO((puerto),((puerto)|(mask)))))/*Prende los bits indicado por la mascara sin modificar el resto del registro*/
#define MASKOFF(puerto, mask) ((puerto)=(TAMANO((puerto),((puerto)&(~(mask))))))/*Apaga los bits indicado por la mascara sin modificar el resto del registro*/
#define MASKTOGGLE(puerto, mask) ((puerto)=(TAMANO((puerto),((puerto)^(mask)))))/*Intercambia el estado de los bits indicado por la mascara sin modificar el resto del registro*/
#define TAMANO(puerto, res)	(sizeof(puerto)==1? (uint8_t) (res): (uint16_t)(res)) /*Macro que permite asignarle el tamaNo a las macros anteriores. Se fija el tamaNo del puerto y castea el valor de la respuesta de las macroa anteriores. Si el puerto es A o B, se castea el valor de un int a un int8_t y si es una registro tipo D se castea el valor de un tipo in a un tipo int16_t*/


#endif

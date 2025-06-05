#ifndef HARDWARE_H
#define HARDWARE_H

//Librerias externas 
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Mapeo LED fisico (GPIO)
#define LED_0 17
#define LED_1 4
#define LED_2 18
#define LED_3 23
#define LED_4 24
#define LED_5 25
#define LED_6 22
#define LED_7 27

//MACROS para el manejo de errores
#define OVERFLOW_NUM_PIN -2
#define EXPORT_ERROR -1
#define DIRECTION_ERROR -4
#define OPEN_FILE_ERROR -3
#define UNEXPORT_ERROR -5

//Prototipos
void export_pin(const int num_pin);
void setout(const int num_pin);
void SetPin(const int num_pin,const char* State);
void SET_ON(const int num_pin);//BORRAR DESPUES
void SET_OFF(const int num_pin);//BORRAR DESPUES
void unexport_pin(const int num_pin);

//Estructuras y uniones
typedef struct{//Funciona para little endian (CREO QUE ESTA AL PEDO)
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
	 bits_t bit;
	 uint8_t puerto;
}leds_t;

//Funciones para el manejo de bits, 1 byte o 2 bytes
#define BITSET(puerto, n) ((puerto)=(TAMANO((puerto),((puerto) | (1<<(n)))))) /*Prende el bit indicado sin modificar el resto del registro*/
#define BITCLR(puerto, n) ((puerto)=(TAMANO((puerto),((puerto) & (~(1<<(n)))))))/*Apaga el bit indicado sin modificar el resto del registro*/
#define BITGET(puerto, n) ((((puerto)>>(n)) & 1))/*Muestra si el bit indicado está prendido o apagado*/
#define BITTOGGLE(puerto, n) ((puerto)=(TAMANO((puerto),((puerto)^(1<<(n))))))/*Intercambia el estado del bit indicado sin modificar el resto del registro*/
#define TOGGLE(puerto) ((puerto)=(TAMANO((puerto),(~(puerto)))))/*Intercambia el estado de los bits indicado por la mascara sin modificar el resto del registro*/
#define ALL_ON(puerto) ((puerto)=(TAMANO((puerto),(puerto)|(~(puerto)))))
#define MASKON(puerto, mask) ((puerto)=(TAMANO((puerto),((puerto)|(mask)))))/*Prende los bits indicado por la mascara sin modificar el resto del registro*/
#define MASKOFF(puerto, mask) ((puerto)=(TAMANO((puerto),((puerto)&(~(mask))))))/*Apaga los bits indicado por la mascara sin modificar el resto del registro*/
#define MASKTOGGLE(puerto, mask) ((puerto)=(TAMANO((puerto),((puerto)^(mask)))))/*Intercambia el estado de los bits indicado por la mascara sin modificar el resto del registro*/
#define TAMANO(puerto, res)	(sizeof(puerto)==1? (uint8_t) (res): (uint16_t)(res)) /*Macro que permite asignarle el tamaNo a las macros anteriores. Se fija el tamaNo del puerto y castea el valor de la respuesta de las macroa anteriores. Si el puerto es A o B, se castea el valor de un int a un int8_t y si es una registro tipo D se castea el valor de un tipo in a un tipo int16_t*/


#endif

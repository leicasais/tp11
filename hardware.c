#include "hardware.h"


void export_pin (const int num_pin){
    FILE *doc;
    int error_w;
    char pin_str[5];  // Suficiente para almacenar "9999" como máximo

     // Convertir el número a cadena
    snprintf(pin_str, sizeof(pin_str), "%d", num_pin);

    if((doc = fopen("/sys/class/gpio/export","w")) == NULL){
        printf("No se pudo exportar el pin %d. Intente mas tarde\n", num_pin);
        exit(-1);//error de export
    }
    error_w=fputs(, );

}
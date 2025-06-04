#include "hardware.h"


void export_pin (int num_pin){
    FILE *doc;
    int error;

    if((doc = fopen("/sys/class/gpio/export","w")) == NULL){
        printf("No se pudo exportar el pin %d. Intente mas tarde\n", num_pin);
        exit();
    }

}
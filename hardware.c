#include "hardware.h"


void export_pin (const int num_pin){
    FILE *doc;
    char ppin_str[4];//Capacidad maxima  caracteres, 4 CONTANDO EL TERMINADOR ()

     // Convertir el número a cadena
    if(snprintf(ppin_str, sizeof(ppin_str), "%d", num_pin)>sizeof(ppin_str)){
        printf("Error de Overflow, el numero al que se quiere acceder es mas grande que el permitido maximo\n");
        exit(OVERFLOW_NUM_PIN);
    }

    if((doc = fopen("/sys/class/gpio/export","w")) == NULL){
        printf("No se pudo exportar el pin %d. Intente mas tarde\n", num_pin);
        exit(OPEN_FILE_ERROR);
    }

    if (fputs(ppin_str,doc )==EOF){
        printf("no se puede exportar el pin %s", ppin_str);
        exit(EXPORT_ERROR);
    }
    else{
        printf("Se exporto corectamente\n");
    }
    fclose(doc);
}
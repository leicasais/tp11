#include "hardware.h"

void export_pin(const int num_pin){
    FILE *doc;
    char ppin_str[4];//Capacidad maxima  caracteres, 4 CONTANDO EL TERMINADOR ()

     // Convertir el número a cadena
    if(snprintf(ppin_str, sizeof(ppin_str), "%d", num_pin)>=sizeof(ppin_str)){
        printf("Error de Overflow, el numero al que se quiere acceder es mas grande que el permitido maximo\n");
        exit(OVERFLOW_NUM_PIN);
    }

    if((doc = fopen("/sys/class/gpio/export","w")) == NULL){
        printf("No se pudo exportar el pin %d. Intente mas tarde: %s", num_pin, strerror(errno)); // strerror(errno) devuelve una cadena que describe el error, errno es una variable global que almacena el último numero de error ocurrido
        exit(OPEN_FILE_ERROR);
    }

    if (fputs(ppin_str,doc)==EOF){
        printf("no se puede exportar el pin %s: %s", ppin_str, strerror(errno));
        exit(EXPORT_ERROR);
    }
    else{
        printf("Se exporto corectamente\n");
    }
    fclose(doc);
}

void setout(const int num_pin){
    FILE * doc;
    char ppin_str[100];

    if(snprintf(ppin_str, sizeof(ppin_str), "/sys/class/gpio/gpio%d/direction", num_pin)>=sizeof(ppin_str)){//Le agrega el numero hecho str al str dl archivo para acceder al gpio direction
        printf("Error de Overflow, el numero al que se quiere acceder es mas grande que el permitido maximo\n");
        exit(OVERFLOW_NUM_PIN);
    }

    if((doc=fopen(ppin_str,"w"))==NULL){//Veo si puedo abrir el archivo con exito
        printf("No se pudo abrir el archivo del pin %s. Intente mas tarde: %s\n", num_pin, strerror(errno));
        exit(OPEN_FILE_ERROR);
    }
    if((fputs("out",doc)==EOF)){//Veo si puedo escribir el archivo
        printf("No se pudo escribir la direccion del pin %s. Intente mas tarde: %s\n", ppin_str, strerror(errno));
        exit(DIRECTION_ERROR);
    }
    else{
        printf("El documento para el PIN %s se abrio exitosamente\n", ppin_str);
    }
    fclose(doc);
}

void SetPin(const int num_pin,const char* State){
    FILE * doc;
     char ppin_str[100];

    if(snprintf(ppin_str, sizeof(ppin_str), "/sys/class/gpio/gpio%d/value", num_pin)>=sizeof(ppin_str)){//Le agrega el numero hecho str al str dl archivo para acceder al gpio direction
        printf("Error de Overflow, el numero al que se quiere acceder es mas grande que el permitido maximo\n");
        exit(OVERFLOW_NUM_PIN);
    }
    if(((doc=fopen(ppin_str,"w")) == NULL)){
        printf("No se pudo abrir el archivo del pin %s. Intente mas tarde: %s\n", ppin_str, strerror(errno));
        exit(OPEN_FILE_ERROR);
    }
    if(fputs(State,doc)==EOF){
        printf("No se pudo escribir en el archivo: %s\n", strerror(errno));
    }
    else{
        printf("El documento %s se Seteo con el estado %s \n",ppin_str,State);
    }
    fclose(doc);

}

void unexport_pin(const int num_pin){
    FILE *doc;
    char ppin_str[100];

    // Convertir el número a cadena
    if(snprintf(ppin_str, sizeof(ppin_str), "%d", num_pin)>=sizeof(ppin_str)){
        printf("Error de Overflow, el numero al que se quiere acceder es mas grande que el permitido maximo\n");
        exit(OVERFLOW_NUM_PIN);
    }

    if((doc = fopen("/sys/class/gpio/unexport","w")) == NULL){
        printf("No se pudo unexportar el pin %d. Intente mas tarde: %s\n", num_pin, strerror(errno));
        exit(OPEN_FILE_ERROR);
    }

    if (fputs(ppin_str,doc)==EOF){
        printf("no se puede unexportar el pin %s: %s\n", ppin_str, strerror(errno));
        exit(UNEXPORT_ERROR);
    }
    else{
        printf("Se unexporto corectamente\n");
    }
    fclose(doc);
}

void SET_ON(const int num_pin){
    char * value="1";
    export_pin(num_pin);
    setout(num_pin);
    SetPin(num_pin, value);
    unexport_pin(num_pin); // Unexport after setting the pin
}
void SET_OFF(const int num_pin){
    char * value="0";
    export_pin(num_pin);
    setout(num_pin);
    SetPin(num_pin, value);
    unexport_pin(num_pin); // Unexport after setting the pin

}
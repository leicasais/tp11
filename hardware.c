#include "hardware.h"


void export_pin(const int num_pin){
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

    if (fputs(ppin_str,doc)==EOF){
        printf("no se puede exportar el pin %s", ppin_str);
        exit(EXPORT_ERROR);
    }
    else{
        printf("Se exporto corectamente\n");
    }
    fclose(doc);
}

void setout(const int num_pin){
    FILE * doc;
    char buffer[50]; //Inicializo el str donde guardo la direccion del archivo de pin
    int nWritten;
    snprintf(buffer,sizeof(buffer),"/sys/class/gpio/gpio%d/direction",num_pin);
    if((doc=fopen(buffer,"w"))==NULL){                                                //Veo si puedo abrir el archivo con exito
        perror("No se pudo acceder a la direccion del pin\n");
        exit(1);
    }
    if((nWritten=fputs("out",doc)==-1)){                                            //Veo si puedo escribir el archivo
        perror("No se pudo abrir la direccion del pin\n");
        exit(1);
    }
    else{
        printf("El documento para el PIN se abrio exitosamente\n");               //  
    }
    fclose(doc);
}

void SetPin(const int num_pin,const int State){
    FILE * doc;
    char buffer[50]; //Inicializo el str donde guardo la direccion del archivo de pin
    int nWritten;
    snprintf(buffer,sizeof(buffer),"/sys/class/gpio/gpio%d/direction",num_pin);
    if((doc=fopen(buffer,"w")==NULL)){
        perror("No se pudo abrir el puerto");
        exit(1);
    }
    else{
        printf("Documento abierto exitosamente\n");
    }
    if(fputc(State,doc)==-1){
        perror("No se pudo escribir en el archivo\n");
    }
    else{
        printf("El documento %s se Seteo con el estado %d",buffer,State);
    }
}
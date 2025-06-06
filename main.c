#include "hardware.h"
int main(void)
{
    char input;
    
    uint8_t puerto = 0; // Inicializa el puerto a 0 (todos los LEDs apagados)
    
    int gpio_leds[] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};
    
    for (int i = 0; i<(sizeof(puerto)*8); i++){//exporto todas las leds y las pongo en setout para poder trabajar con ellas en el programa
        export_pin(gpio_leds[i]);
        setout(gpio_leds[i]);
    }

    do
    {
        printf("Ingrese un número entre 0 y 7 para encender el led correspondiente, t para que los LEDs cambien al estado opuesto, c para apagarlos todos, s para prenderlos todos o 'q' para salir.\n");
        scanf(" %c", &input);
        if (input>='0' && input<='7') {
            int led_num = input - '0'; // Convierte el carácter a número
            BITSET(puerto,led_num); // Actualiza el estado del LED
            SetPin(gpio_leds[led_num], "1"); // Enciende el LED
        }
        else if (input == 't') {
            TOGGLE(puerto);//cambia el estado de todas las leds
            actualizacion_leds_de_puerto(gpio_leds, puerto);
        }
        else if(input=='c'){
            puerto = 0; // Resetea el puerto a 0 (todos los LEDs apagados)
            actualizacion_leds_de_puerto(gpio_leds, puerto);
        }
        else if (input == 's'){
            ALL_ON(puerto); // Enciende todos los LEDs
            actualizacion_leds_de_puerto(gpio_leds, puerto);
        }
        
        else if (input != 'q'){
            printf("Entrada no válida. Intentelo de nuevo\n");
        }  
    } while (input != 'q');

    for (int i = 0; i<(sizeof(puerto)*8); i++){
        unexport_pin(gpio_leds[i]); // Desexporta el pin después de usarlo
    }    
    return 0;
}

#include "hardware.h"
int main(void)
{
    /*SET_ON(LED_0);
    SET_ON(LED_1);
    SET_ON(LED_4);//No van dentro del programa real pero no lopuedo probar y tengo sueño
    return 0;*/
    char input;
    leds_t leds;
    leds.puerto = 0; // Inicializa el puerto a 0 (todos los LEDs apagados)
    
    int gpio_leds[] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7};
    
    do
    {
        printf("Ingrese un número entre 0 y 7 para encender el led correspondiente, t para que los LEDs cambien al estado opuesto, c para apagarlos todos, s para prenderlos todos o 'q' para salir.\n");
        scanf(" %c", &input);
        if (input>=0 && input<=7) {
            int led_num = input - '0'; // Convertir el carácter a número
            BITSET(leds.puerto,led_num); // Actualiza el estado del LED
        }
        else if (input == 'q') {
            TTOGGLE(leds.puerto);//cambia el estado de todas las leds
        }
        else if(input=='c'){
            leds.puerto = 0; // Resetea el puerto a 0 (todos los LEDs apagados)
        }
        else if (input == 's'){
            ALL_ON(leds.puerto); // Enciende todos los LEDs
        }
        
        else if (input != 'q'){
            printf("Entrada no válida. Intentelo de nuevo\n");
        }  
    } while (input != 'q');

    for (int i = 0; i<8; i++){
        if (BITGET(leds.puerto, i)){
            export_pin(gpio_leds[i]);
            setout(gpio_leds[i]);
            SetPin(gpio_leds[i], "1"); // Enciende el LED
            unexport_pin(gpio_leds[i]); // Desexporta el pin después de usarlo
        }
    }   
}

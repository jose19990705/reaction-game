#include <stdio.h>
#include "pico/stdlib.h"
#include "secuencia.h"
#include "display.h"
#include "pulsador.h"
#include <time.h>
#include <stdlib.h>

// Asumo que la función debounce está en la librería pulsador.h
// Y que esta devuelve 'true' solo si el pulsador ha sido presionado de manera estable.

int main() {

    stdio_init_all();

    // Inicialización de los GPIO encargados del control del display
    gpio_init(control1);
    gpio_init(control2);
    gpio_init(control3);
    gpio_init(control4);

    // Inicialización de los GPIO encargados de los segmentos del display
    gpio_init(a);
    gpio_init(b);
    gpio_init(c);
    gpio_init(d);
    gpio_init(e);
    gpio_init(f);
    gpio_init(g);

    // Inicialización de los GPIO encargado de los leds.
    gpio_init(Led1);
    gpio_init(Led2);
    gpio_init(Led3);

    // Inicialización del GPIO de los botones.
    gpio_init(Pulsador1);
    gpio_init(Pulsador2);
    gpio_init(Pulsador3);
    gpio_init(RST);

    // Definición de entradas y salidas en los GPIO de control.
    gpio_set_dir(control1, GPIO_OUT);
    gpio_set_dir(control2, GPIO_OUT);
    gpio_set_dir(control3, GPIO_OUT);
    gpio_set_dir(control4, GPIO_OUT);

    // Definición de salidas de los GPIO de los digitos.
    gpio_set_dir(a, GPIO_OUT);
    gpio_set_dir(b, GPIO_OUT);
    gpio_set_dir(c, GPIO_OUT);
    gpio_set_dir(d, GPIO_OUT);
    gpio_set_dir(e, GPIO_IN);
    gpio_set_dir(f, GPIO_IN);
    gpio_set_dir(g, GPIO_IN);

    // Definición de los GPIO de los pulsadores.
    gpio_set_dir(Led1, GPIO_OUT);
    gpio_set_dir(Led2, GPIO_OUT);
    gpio_set_dir(Led3, GPIO_OUT);

    // Definición como salida de los pulsadores.
    gpio_set_dir(Pulsador1, GPIO_IN);
    gpio_set_dir(Pulsador2, GPIO_IN);
    gpio_set_dir(Pulsador3, GPIO_IN);
    gpio_set_dir(RST, GPIO_IN);

    // Definición de variables.
    bool reseteo = false, valid = false, boton_pulsado = false;
    uint8_t led_aleatorio = 0;
    uint16_t tiempo_presion_boton = 0;

    while (true) {

        if (!reseteo) {

            // Secuencia y led aleatorio.
            LedsSequence();
            led_aleatorio = random_led();
            tiempo_presion_boton = to_ms_since_boot(get_absolute_time());

            while (tiempo_presion_boton < 10000) {

                // Usamos debounce para verificar los pulsadores
                if (debounce(Pulsador1) || debounce(Pulsador2) || debounce(Pulsador3)) {
                    boton_pulsado = true;
                    break;
                }

                tiempo_presion_boton = to_ms_since_boot(get_absolute_time());
            }

            if (boton_pulsado) {
                switch (led_aleatorio) {
                    case 1:
                        if (debounce(Pulsador1)) {
                            valid = true;
                        } else {
                            valid = false;
                        }
                        break;

                    case 2:
                        if (debounce(Pulsador2)) {
                            valid = true;
                        } else {
                            valid = false;
                        }
                        break;

                    case 3:
                        if (debounce(Pulsador3)) {
                            valid = true;
                        } else {
                            valid = false;
                        }
                        break;
                }
            }

            // Verificación de si el led pulsado fue válido o no
            if (valid) {
                tiempo_presion_boton += 100;
            }
        } else {
            reseteo = true;
        }

        while (true) {
            // Verificación del RST para resetear
            if (gpio_get(RST)) {
                reseteo = true;
                break;  // Salir del ciclo de tiempo y resetear
            }
            showTime(tiempo_presion_boton);
        }
        
    }  // Aquí se cierra el primer while(true)

    return 0;
}

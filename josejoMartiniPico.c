#include <stdio.h>
#include "pico/stdlib.h"
#include "secuencia.h"
#include <stdlib.h>

int main()
{
    // i want that the system wait for 4 seconds, and after on led, and after off vamos!
    //genial!
    stdio_init_all();
    gpio_init(18);
    gpio_init(19);
    gpio_init(20);

    gpio_set_dir(18,GPIO_OUT);
    gpio_set_dir(19,GPIO_OUT);
    gpio_set_dir(20,GPIO_OUT);
    srand(time_us_32());

    LedsSequence();
    while (true) {
        

        uint8_t led_aleatorio=random_led();
        printf("el led es: %d\n", led_aleatorio);

        wait(3000);


    }
    return 0;
}

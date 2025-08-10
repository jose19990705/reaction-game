#include <stdio.h>
#include "pico/stdlib.h"
#include "secuencia.h"
#include "display.h"
#include <stdlib.h>


int main()
{
    // i want that the system wait for 4 seconds, and after on led, and after off vamos!
    //genial!
    stdio_init_all();

    gpio_init(6);
    gpio_init(7);
    gpio_init(8);
    gpio_init(9);

    


    gpio_init(16);
    gpio_init(17);
    gpio_init(18);
    gpio_init(19);
    gpio_init(20);
    gpio_init(21);
    gpio_init(22);

    gpio_set_dir(6,GPIO_OUT);
    gpio_set_dir(7,GPIO_OUT);
    gpio_set_dir(8,GPIO_OUT);
    gpio_set_dir(9,GPIO_OUT);


    
    gpio_set_dir_masked(((1 << 16) | (1 << 17) | (1 << 18) |
                (1 << 19) | (1 << 20) | (1 << 21) | (1 << 22)), ((1 << 16) | (1 << 17) | (1 << 18) |
                (1 << 19) | (1 << 20) | (1 << 21) | (1 << 22))); 
   // gpio_put_masked(mask2, mask2);
   // gpio_init(18);
   // gpio_init(19);
   // gpio_init(20);

   // gpio_set_dir(18,GPIO_OUT);
   // gpio_set_dir(19,GPIO_OUT);
   // gpio_set_dir(20,GPIO_OUT);
    //srand(time_us_32());
    

    //LedsSequence();
    while (true) {
    
        for(uint8_t i=1; i<=1000; i++){
    uint64_t inicio = to_ms_since_boot(get_absolute_time());
    while (to_ms_since_boot(get_absolute_time()) - inicio < 500) {
        showTime(i);
    }
}

       // uint8_t led_aleatorio=random_led();
       // printf("el led es: %d\n", led_aleatorio);

       // wait(3000);


    }
    return 0;
}

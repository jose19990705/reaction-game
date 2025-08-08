#include "pico/stdlib.h"
#include "secuencia.h"
#include <time.h>
#include <stdlib.h>






//Sequence.

void wait(uint16_t time_sleep){
    int64_t before_time=to_ms_since_boot(get_absolute_time());
    int64_t actual_time=to_ms_since_boot(get_absolute_time());
    while((actual_time-before_time)<time_sleep){
        actual_time=to_ms_since_boot(get_absolute_time());
    }
}

void LedsSequence(){

    //first step of the sequence.

    gpio_put_masked(Mask,0x1C0000);
    wait(2000);
    gpio_put_masked(Mask,0x140000);
    wait(2000);
    gpio_put_masked(Mask,0x100000);
    wait(2000);
    gpio_clr_mask(Mask);
    wait(2000);
}


uint8_t random_led(){
    uint8_t random_led= 1+ rand()%3;
    switch (random_led)
    {
    case 1:
        gpio_put(Led1,1);
        gpio_put(Led2,0);
        gpio_put(Led3,0);
        break;
    
    case 2:
        gpio_put(Led1,0);
        gpio_put(Led2,1);
        gpio_put(Led3,0);
        break;
    case 3:
        gpio_put(Led1,0);
        gpio_put(Led2,0);
        gpio_put(Led3,1);
        break;
    }
    return random_led;
}


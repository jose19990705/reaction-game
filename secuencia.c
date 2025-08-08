#include "pico/stdlib.h"
#include "secuencia.h"
#include <time.h>





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


#include <stdio.h>
#include <time.h>
#include "pico/stdlib.h"

#define led 25

int main()
{
    // i want that the system wait for 4 seconds, and after on led, and after off vamos!
    //genial!
    stdio_init_all();
    gpio_init(led);
    gpio_set_dir(led,GPIO_OUT);
    bool led_state=true;
    gpio_put(led,led_state);
    uint32_t start_time= to_ms_since_boot(get_absolute_time());
    uint32_t final_time= to_ms_since_boot(get_absolute_time());
    while (true) {
        final_time= to_ms_since_boot(get_absolute_time());
        if(final_time-start_time>=4000){
            led_state= !led_state;
            gpio_put(led,led_state);
            start_time=to_ms_since_boot(get_absolute_time());
        }

    }
    return 0;
}

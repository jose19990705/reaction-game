#include "pico/stdlib.h"
#include "display.h"
#include <time.h>
#include <stdlib.h>
#include <stdint.h>






void Dec_7_segmentos(uint8_t number){
   // gpio_put_masked(mask_digit,0);

    switch (number)
    {
    case 0:
        gpio_put_masked(mask_digit,N0);
        break;
    case 1:
        gpio_put_masked(mask_digit,N1);
        break;
    case 2:
        gpio_put_masked(mask_digit,N2);
        break;
    case 3:
        gpio_put_masked(mask_digit,N3);
        break;
    case 4:
        gpio_put_masked(mask_digit,N4);
        break;
    case 5:
        gpio_put_masked(mask_digit,N5);
        break;
    case 6:
        gpio_put_masked(mask_digit,N6);
        break;
    case 7:
        gpio_put_masked(mask_digit,N7);
        break;
    case 8:
        gpio_put_masked(mask_digit,N8);
        break;
    case 9:
        gpio_put_masked(mask_digit,N9);
        break;
    }
}




void showTime(uint16_t time){
    //separate the digits.
    uint8_t showDigit=0;
    
    uint8_t umil= time/1000;
    time=time%1000;
    uint8_t cent= time/100;
    time=time%100;
    uint8_t dec= time/10;
    uint8_t unid=time%10;

    for (uint8_t i=1; i<=4; i++){

    uint64_t start_time = to_ms_since_boot(get_absolute_time());
    uint64_t actual_time = start_time;

        switch (i)
        {
        case 1:
            showDigit=unid;
            gpio_put(control1,1);
            gpio_put(control2,0);
            gpio_put(control3,0);
            gpio_put(control4,0);
            break;
        
        case 2:
            showDigit= dec;
            gpio_put(control1,0);
            gpio_put(control2,1);
            gpio_put(control3,0);
            gpio_put(control4,0);
            break;
        case 3:
            showDigit=cent;
            gpio_put(control1,0);
            gpio_put(control2,0);
            gpio_put(control3,1);
            gpio_put(control4,0);
            break;
        case 4:
            showDigit=umil;
            gpio_put(control1,0);
            gpio_put(control2,0);
            gpio_put(control3,0);
            gpio_put(control4,1);
            break;
        }



        while((actual_time-start_time)<5){
            Dec_7_segmentos(showDigit);
            actual_time=to_ms_since_boot(get_absolute_time());
        }
    }
    
    //multiplexado.



}

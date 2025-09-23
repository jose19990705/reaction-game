#include <stdio.h>
#include "pico/stdlib.h"
#include "secuencia.h"
#include "display.h"
#include "pulsador.h"
#include <stdlib.h>


int main() {


     stdio_init_all();

     //Inicialización de los GPIO encargados del control del display

     gpio_init(control1);
     gpio_init(control2);
     gpio_init(control3);
     gpio_init(control4);

     //Inicialización de los GPIO encargados de los segmentos del display
     gpio_init(a);
     gpio_init(b);
     gpio_init(c);
     gpio_init(d);
     gpio_init(e);
     gpio_init(f);
     gpio_init(g);

     //Inicialización de los GPIO encargado de los  leds.
     gpio_init(Led1);
     gpio_init(Led2);
     gpio_init(Led3);
  
     //Inicialización del GPIO de los botones.
     gpio_init(Pulsador1);
     gpio_init(Pulsador2);
     gpio_init(Pulsador3);
     gpio_init(RST);

     //Definición de entradas y salidas en los GPIO de control.

     gpio_set_dir(control1,GPIO_OUT);
     gpio_set_dir(control2,GPIO_OUT);
     gpio_set_dir(control3,GPIO_OUT);
     gpio_set_dir(control4,GPIO_OUT);

     //Definición de salidas de los GPio de los digitos.


     gpio_set_dir(a,GPIO_OUT);
     gpio_set_dir(b,GPIO_OUT);
     gpio_set_dir(c,GPIO_OUT);
     gpio_set_dir(d,GPIO_OUT);
     gpio_set_dir(e,GPIO_IN);
     gpio_set_dir(f,GPIO_IN);
     gpio_set_dir(g,GPIO_IN);

     //Definición de los GPio de los pulsadores.

     gpio_set_dir(Led1,GPIO_OUT);
     pio_set_dir(Led2,GPIO_OUT);
     pio_set_dir(Led3,GPIO_OUT);

     //Definición como salida de los pulsadores.
     gpio_set_dir(Pulsador1,GPIO_IN);
     gpio_set_dir(Pulsador2,GPIO_IN);
     gpio_set_dir(Pulsador3,GPIO_IN);
     gpio_set_dir(RST,GPIO_IN);

     //Definición de variables.
     bool reseteo=false;

    



     while(true){



      if(gpio_get(RST)){

        reseteo=true;
      } else{
         reseteo=false;
      }

      if(!reseteo){

      }


        //wait(1);

     }
   

    return 0;
}

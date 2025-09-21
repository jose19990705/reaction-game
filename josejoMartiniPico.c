//#include <stdio.h>
//#include "pico/stdlib.h"
//#include "secuencia.h"
//#include "display.h"
//#include <stdlib.h>


//int main()
//{





  //  return 0;
//}

//#include <stdio.h>

#include <stdio.h>
#include "pico/stdlib.h"
#include "secuencia.h"
#include "display.h"
#include <stdlib.h>
#include "pulsador.h"


int main() {


     stdio_init_all();
     gpio_init(Pulsador);
     gpio_set_dir(Pulsador,GPIO_IN);
     while(true){

        pulsado();

        //wait(1);

     }
   

    return 0;
}

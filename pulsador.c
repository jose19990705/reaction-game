#include "pulsador.h"

bool debounce() {
    static bool last_stable_state = false;  
    static bool last_read_state = false;    
    static int64_t last_debounce_time = 0;  

    bool current_state = gpio_get(Pulsador);
    int64_t current_time = to_ms_since_boot(get_absolute_time());

    if (current_state != last_read_state) {
        last_debounce_time = current_time;
        last_read_state = current_state;
    }

  
    if ((current_time - last_debounce_time) > 10) {
        if (current_state != last_stable_state) {
            last_stable_state = current_state;
            if (current_state == true) {
                return true;
            }
        }
    }

    return false;
}




void pulsado() {
    uint8_t contador = 0;

    while (contador <= 10) {

        if (debounce()) {
            contador += 1;
            printf("contador: %d\n", contador);
        }

    }
}
#ifndef PULSADOR_H
#define PULSADOR_H
#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include <stdint.h>


#define Pulsador1 1
#define Pulsador2 2
#define Pulsador3 3
#define RST 4

bool debounce(uint8_t Pulsador_presionado);


#endif
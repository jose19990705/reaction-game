#ifndef SECUENCIA_H
#define SECUENCIA_H
//definition Leds.
#include <stdint.h>
#define Led1 18
#define Led2 19 
#define Led3 20


#define Mask ((1u << 18) | (1u << 19) | (1u << 20))
void LedsSequence();
void wait(uint16_t time_sleep);
uint8_t random_led();

#endif
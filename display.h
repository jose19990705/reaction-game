#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdint.h>


//control digit.
#define control1 9
#define control2 8
#define control3 7
#define control4 6

//segments.
#define a 18
#define b 16
#define c 19
#define d 21
#define e 22
#define f 20
#define g 17

//Masks
#define mask_digit ((1u<<a)|(1u<<b)|(1u<<c)|\
        (1u<<d)|(1u<<e)|(1u<<f)|(1u<<g))


#define N0 ((1u<<a)|(1u<<b)|(1u<<c)|\
        (1u<<d)|(1u<<e)|(1u<<f)|(0u<<g))

#define N1 ((0u<<a)|(1u<<b)|(1u<<c)|\
        (0u<<d)|(0u<<e)|(0u<<f)|(0u<<g))

#define N2 ((1u<<a)|(1u<<b)|(0u<<c)|\
        (1u<<d)|(1u<<e)|(0u<<f)|(1u<<g))

#define N3 ((1u<<a)|(1u<<b)|(1u<<c)|\
        (1u<<d)|(0u<<e)|(0u<<f)|(1u<<g))

#define N4 ((0u<<a)|(1u<<b)|(1u<<c)|\
        (0u<<d)|(0u<<e)|(1u<<f)|(1u<<g))

#define N5 ((1u<<a)|(0u<<b)|(1u<<c)|\
        (1u<<d)|(0u<<e)|(1u<<f)|(1u<<g))

#define N6 ((1u<<a)|(0u<<b)|(1u<<c)|\
        (1u<<d)|(1u<<e)|(1u<<f)|(1u<<g))

#define N7 ((1u<<a)|(1u<<b)|(1u<<c)|\
        (0u<<d)|(0u<<e)|(0u<<f)|(0u<<g))

#define N8 ((1u<<a)|(1u<<b)|(1u<<c)|\
        (1u<<d)|(1u<<e)|(1u<<f)|(1u<<g))

#define N9 ((1u<<a)|(1u<<b)|(1u<<c)|\
        (1u<<d)|(0u<<e)|(1u<<f)|(1u<<g))


void Dec_7_segmentos(uint8_t number);
void showTime(uint16_t time);



#endif
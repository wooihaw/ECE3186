// main.cpp to play birthday song on FRDM-KL25Z for mbed
#include "mbed.h"

#define c 262
#define d 294
#define e 330
#define f 349
#define g 392
#define a 440
#define b 494
#define c5 523

PwmOut buzzer(D7) ;

const float tones[ ] = {c, 0, c, 0, d, 0, c, 0, f, 0, e, 0,
                  c, 0, c, 0, d, 0, c, 0, g, 0, f, 0,
                  c, 0, c, 0, c5, 0, a, 0, f, 0, e, 0, d, 0, 
                  b, 0, b, 0, a, 0, f, 0, g, 0, f, 0}; // tones array

const float beat[ ] = {0.1, 0.1, 0.1, 0.1, 0.25, 0.1, 0.25, 0.1, 0.25, 0.1, 0.5, 0.1,
                 0.1, 0.1, 0.1, 0.1, 0.25, 0.1, 0.25, 0.1, 0.25, 0.1, 0.5, 0.1, 
                 0.1, 0.1, 0.1, 0.1, 0.25, 0.1, 0.25, 0.1, 0.25, 0.1, 0.25, 0.1, 0.5, 0.1,
                 0.1, 0.1, 0.1, 0.1, 0.25, 0.1, 0.25, 0.1, 0.25, 0.1, 0.5, 0.1} ; // beat array

int main() {
    while (1) { 
        for (int i=0; i<50; i++) {
            if (tones[i] == 0) {
                buzzer = 0;
            } else { 
                buzzer.period(1/(tones[i]));  // set PWM period 
                buzzer = 0.5;  // set duty cycle 
            }
            wait(beat[i]);  // hold for beat period 
        }
        buzzer = 0;
        wait(2.0);  
    }
}

#define F_CPU 16000000UL // Clock Speed
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

    // setup section -
    DDRB |= (1<<PB5);  // Setting pin 13 as output pin
    DDRD &= ~(1<<PD7); // Setting pin 7 as input pin
    PORTD |= (1<<PD7); // Internal registor pull up
    uint8_t BUTTON_PRESS = 1; // flag for button

    // loop section
    while(1) {
        if (!(PIND & (1<<PD7)))
            //check if button is pressed
        {
            if (BUTTON_PRESS == 0)
            {
                PORTB ^= (1<<PB5);   
            }
            BUTTON_PRESS = 1;      
        } 
        else
        {
            BUTTON_PRESS = 0;
        }       
    }

    
}

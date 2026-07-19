#define F_CPU 16000000UL // Clock Speed
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

    // setup section -
    DDRB |= (1<<PB5);  // Setting pin 13 as output pin
    DDRD &= ~(1<<PD7); // Setting pin 7 as input pin
    PORTD |= (1<<PD7); // Internal registor pull up
    
    uint8_t action; // variable to store fresh read
    uint8_t BUTTON_PRESS = 1; // flag for button

    // loop section -
    while(1) {
        action = !(PIND & (1<<PD7)); // read the current state of pin
        if (BUTTON_PRESS != action) // detect the change
        {   
            _delay_ms(20); // we wait-out the debounce
            action = !(PIND & (1<<PD7));
            if (action != BUTTON_PRESS)
            {
                // Edge detection
                PORTB ^= (1<<PB5); // toggle the output pin
            }  
        }   
    }
}

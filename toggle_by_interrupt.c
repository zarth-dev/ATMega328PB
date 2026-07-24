#define F_CPU 16000000UL // Clock Speed

#include <avr/io.h>
#include <avr/interrupt.h> // necessary for interrupts
#include <util/delay.h>

volatile uint8_t g_button_state = 0; // flag for button

int main(void) {

    // setup section -
    DDRB |= (1<<PB5);  // Setting pin 13 as output pin
    DDRD &= ~(1<<PD7); // Setting pin 7 as input pin
    PORTD |= (1<<PD7); // Internal register pull up

    // Enabling Interrupts -
    // Setting PCICR bit with PCIE2
    PCICR |= (1<<PCIE2); // enabl
    PCMSK2 |= (1<<PCINT23);
    
    // Enabling global interrupt - 
    sei();

    // loop section -
    while(1) {
        // Free for other stuff
    }      
}

ISR(PCINT2_vect) {
    
    uint8_t action; // variable to store fresh read
    
    action = !(PIND & (1<<PD7)); // read the current state of pin
    if (g_button_state != action) // detect the change
    {   
        _delay_ms(20); // we wait-out the debounce
        action = !(PIND & (1<<PD7)); // re-read the current state of pin for confirmation
        if (action == 1)    // only toggle on press, not release
        {
        // toggle on confirmed press
        PORTB ^= (1<<PB5); // toggle the output pin
        }  
        g_button_state = action; // remember the new state
    }
}

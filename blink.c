#define F_CPU 16000000UL // Clock Speed
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Setting pin 13 as output pin
    DDRB |= (1<<PB5);

    // blink cycle
    while (1)
    {
        PORTB |= (1<<PB5);
        _delay_ms(500);
        PORTB &= ~(1<<PB5);
        _delay_ms(500);
    }
    
}
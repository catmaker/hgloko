#include <Arduino.h>
#include <util/delay.h>

#include "motordriver_4wd.h"
#include "seeed_pwm.h"

/* 
 * PD7: Herc-CTR2A, PINM2F, output
 * PD6: Herc-IR2104SD, PINCS, output
 * PD5: Herc-CTR1B, PINM1R, output
 * PD4: Herc-CTR1A, PINM1F, output
 * PD3: RS232 TXD output
 * PD2: RS232 RXD (INT0) input
 * PD1: RS485 TXD output
 * PD0: RS485 RXD input
 *
 * PC6: Used for RESET#
 * PC5: RPISCL slave OC, set as input
 * PC4: RPISDA slave OC, set as input
 * PC3: Servo 3 output
 * PC2: Servo 2 output
 * PC1: Servo 1 output
 * PC0: Servo 0 output
 *
 * PB7: Used for XTAL2
 * PB6: Used for XTAL1
 * PB5: Uncommitted (SCK for ICP)
 * PB4: Uncommitted (MISO for ICP)
 * PB3: Uncommitted exp pin, set as output (MOSI for ICP)
 * PB2: Uncommitted exp pin, set as output
 * PB1: Uncommitted exp pin, set as output
 * PB0: Herc-CTR2B, pinM2R, output 
 *
 */

#define HERC_PCBA_PINS_INIT() {                 \
                DDRD =  0b11111010;             \
                PORTD = 0b00001010;             \
                DDRC =  0b00001111;             \
                PORTC = 0b00000000;             \
                DDRB =  0b00001111;             \
                PORTB = 0b00000000; }

#define mdelay(A) _delay_ms(A)

void uart_init(unsigned long baud);
void uart_off(void);
char uart_havechar(void);
char uart_getc(void);
void uart_putc(char c);
int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);


int main(void)
{

    char c;
    int dir1, dir2, speed = 80;
//	init();
    HERC_PCBA_PINS_INIT();
    
    
#if defined(USBCON)
	USBDevice.attach();
#endif
	
    setup(); // motorDriverDemo.ino's setup and loop, to refactor into here.
    
    uart_init(57600);

    
    while (1) {
	c = uart_getc();
	if (c == '\n') {
	    uart_putc('\r');
	    uart_putc('\n');
	}
	else
	    uart_putc(c);
	
	// parse(?)
	switch(c) {
	case 'f':
	    dir1 = DIRF;
	    dir2 = DIRF;
		break;
	case 'b':
	    dir1 = DIRR;
	    dir2 = DIRR;
	    break;
	case 'l':
	    dir1 = DIRF;
	    dir2 = DIRR;
	    break;
	case 'r':
	    dir1 = DIRR;
	    dir2 = DIRF;
	    break;
	case ' ':
	    speed = 0;
	    break;
	case '1':
	    speed = 25;
	    break;
	case '2':
	    speed = 50;
	    break;
	case '3':
	    speed = 75;
	    break;
	case '4':
	    speed = 100;
	    break;
	default:
	    break;
	}
	
	// perform action
	MOTOR.setSpeedDir1(speed, dir1);
	MOTOR.setSpeedDir2(speed, dir2);
       
       
    }

    
    
    
    
    
    
    
    
    
    for (;;) {
//
//		loop();
//
	MOTOR.setSpeedDir(80, DIRF);
	_delay_ms(3000);
	MOTOR.setSpeedDir(80, DIRR);
	_delay_ms(3000);

	if (serialEventRun) serialEventRun();
    }
    
    
    
    return 0;
}


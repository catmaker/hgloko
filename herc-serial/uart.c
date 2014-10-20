#include <stdio.h>
#include <avr/interrupt.h>

#define MYUBRR (F_CPU/16/BAUD-1)

void uart_init(unsigned long baud)
{
    /* Set baud rate */
    unsigned long ubrr = (F_CPU / 16 / baud - 1);
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)(ubrr>>0);
    /* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: Async,8,N,1 */
    UCSR0C = 0b00000110;
    //RS485_TXEN_OFF();
}     

void uart_off(void)
{
    UCSR0B = 0;
}

char uart_havechar(void)
{
    return (UCSR0A & (1<<RXC0));
}

char uart_getc(void)
{
    //TX485_OFF();
    while (!uart_havechar())
	;
    return UDR0;
}

void uart_putc(char c)
{
    //RS485_TXEN_ON();
    loop_until_bit_is_set(UCSR0A, UDRE0);
    
    UCSR0B = (1<<TXEN0);
    
    UDR0 = c;
    UCSR0A |= (1<<TXC0);
    loop_until_bit_is_set(UCSR0A, TXC0);
    //RS485_TXEN_OFF();
    
    UCSR0B = (1<<RXEN0);
    
}

int uart_putchar(char c, FILE *stream)
{
    if (c == '\n')
	uart_putc('\r');
    uart_putc(c);
    return 0;
}

int uart_getchar(FILE *stream)
{
    return uart_getc();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>

//#include "../firmware/juice.h"
#include "juice.h"

#define I2C_NUM_RETRIES	3
#define RETRY_TIMEOUT	20000

static int rpi_rev;
static int rj_file = 0;
static int rj_errno;

int rj_readbyte(int subreg);
int rj_writebyte(int subreg, int data);
int rj_readword(int subreg);
int rj_writeword(int subreg, int data);
int rj_readblock(int subreg, void *inbuf);

#define BUFSIZE 64
char version_str[BUFSIZE];

static int i2cdev_testopen(const char *devbusname, int i2caddr_test)
{
    int fd, r;
    unsigned char i2c_buffer[16];
    
    /* test bus */
    fd = open(devbusname, O_RDWR);
    if (fd < 0)
        return -1;
    
    /* setup test device as slave*/
    r = ioctl(fd, I2C_SLAVE, i2caddr_test);
    if (r < 0)
       return -2;
    
    /* read I2C test slave */
    r = read(fd, i2c_buffer, 4);
    if (r < 0)
        return -3;

    return fd;
}

int rj_open(int i2caddr)
{
    int rval;
    rpi_rev = 1;
    
    /* Test of I2C bus file and connectivity to AVR as I2C slave */
    rval = i2cdev_testopen("/dev/i2c-0", i2caddr);
    
    if (rval < 0) {
        rpi_rev = 2;
        rval = i2cdev_testopen("/dev/i2c-1", i2caddr);
    }
    if (rval < 0) {
        printf("i2cdev_testopen: /dev/i2c-x unsuccessful, Raspy Juice found.\n");
        return -1;
    }
    printf("i2cdev_testopen: successful, fd_i2cbus = %d, rpi_rev = %d\n",
           rj_file, rpi_rev);
    
    rj_file = rval;
    return rj_file;
}

char *rj_getversion(void)
{
    int i;

    i = 0;
    rj_writebyte(RJ_VERSION, 0);

    do {
	version_str[i] = rj_readbyte(RJ_VERSION);
    } while ((version_str[i] != 0) && (i++ < (BUFSIZE - 2) ) );

    version_str[i] = 0;
    return version_str;
}

int rj_setservo(int chan, int usec)
{
    return rj_writeword(chan, usec);
}

int rj_readstat(void)
{
    return rj_readbyte(GSTAT);
}

int rj_readadc(unsigned char mux)
{
    int rval;
    rval = rj_writebyte(ADCMUX, mux);
    rval = rj_readword(ADCDAT);
    return rval;
} 

int rj232_getc(void)
{
    return rj_readbyte(RS232D);
}

int rj232_read(unsigned char *buf, int maxlen)
{
    int i = 0;
    while ((rj_readstat() & RXA232) && (i < maxlen)) {
	buf[i++] = rj232_getc();
    }
    buf[i] = 0;
    return i;
}

int rj485_getc(void)
{
    return rj_readbyte(RS485D);
}

int rj485_read(unsigned char *buf, int maxlen)
{
    int i = 0;
    while ((rj_readstat() & RXA485) && (i < maxlen)) {
	buf[i++] = rj485_getc();
    }
    buf[i] = 0;
    return i;
}

int rj232_send(unsigned char *buf, int len)
{
    int i, rval;
    for (i = 0; i < len; i++)
	rval = rj_writebyte(RS232D, *buf++);
    return rval;
} 

int rj485_send(unsigned char *buf, int len)
{
    int i, rval;
    for (i = 0; i < len; i++)
	rval = rj_writebyte(RS485D, *buf++);
    return rval;
}


/**********************************************************************
 *
 **********************************************************************/

int rj_readbyte(int subreg)
{
    int rval, retry = 3;
    do {
	rval = i2c_smbus_read_byte_data(rj_file, subreg);
	if (rval < 0) {
	    retry--;
	    usleep(RETRY_TIMEOUT);
	}
    } while ((rval < 0) && (retry > 0));
    
    if (rval < 0)
	fprintf(stderr, "i2c_smbus_read_byte_data failed.\n");

    return rval;
}   

int rj_readword(int subreg)
{
   int rval, retry = 3;
    do {
	rval = i2c_smbus_read_word_data(rj_file, subreg);
	if (rval < 0) {
	    retry--;
	    usleep(RETRY_TIMEOUT);
	}
    } while ((rval < 0) && (retry > 0));

    if (rval < 0)
	fprintf(stderr, "i2c_smbus_read_word_data failed.\n");

    return rval;
}   

int rj_readblock(int subreg, void *inbuf)
{
    int rval, retry = 3;
    do {
	rval = i2c_smbus_read_block_data(rj_file, subreg, inbuf);
	if (rval < 0) {
	    retry--;
	    usleep(RETRY_TIMEOUT);
	}
    } while ((rval < 0) && (retry > 0));
   
    if (rval < 0)
	fprintf(stderr, "i2c_smbus_read_block_data failed.\n");

    return rval;
}


int rj_writebyte(int subreg, int data)
{
   int rval, retry = 3;
    do {
	rval = i2c_smbus_write_byte_data(rj_file, subreg, data);
	if (rval < 0) {
	    retry--;
	    usleep(RETRY_TIMEOUT);
	}
    } while ((rval < 0) && (retry > 0));

    if (rval < 0)
	fprintf(stderr, "i2c_smbus_write_byte_data failed.\n");

    return rval;
}   

int rj_writeword(int subreg, int data)
{
   int rval, retry = 3;
    do {
	rval = i2c_smbus_write_word_data(rj_file, subreg, data);
	if (rval < 0) {
	    retry--;
	    usleep(RETRY_TIMEOUT);
	}
    } while ((rval < 0) && (retry > 0));

    if (rval < 0)
	fprintf(stderr, "i2c_smbus_write_word_data failed.\n");

    return rval;
}   

struct avr_swuart_baud_setting {
    int bps;
    unsigned char prescaler;
    unsigned char ticks;
} avr_swuart_baud_setting;

struct avr_swuart_baud_setting avr_rates[] = {
    { 1200, 0x05, 96 },
    { 2400, 0x04, 96 },
    { 4800, 0x04, 48 },
    { 9600, 0x04, 24 },
    { 14400, 0x04, 16 },
    { 19200, 0x04, 12 },
    { 38400, 0x04, 6 },
};
int avr_rates_max = sizeof(avr_rates) / sizeof (avr_swuart_baud_setting);

int rj232_setbaud(int bps)
{
    int i = 0;
    
    while (i < avr_rates_max) {
	if (avr_rates[i].bps == bps) {
	    return rj_writeword(BPS232, (avr_rates[i].prescaler << 8) | 
				(avr_rates[i].ticks));
	}
	i++;
    }
    return -1;
}

struct avr_usart_baud_setting {
    int bps;
    int ubrr;
} avr_usart_baud_setting;

#define F_CPU 14745600UL
#define UBRR_V(BAUD) (F_CPU / 16 / (unsigned long)(BAUD) - 1) 

struct avr_usart_baud_setting avr_ubrrs[] = {
    { 1200,	UBRR_V(1200)	},
    { 2400,	UBRR_V(2400)	},
    { 4800,	UBRR_V(4800)	},
    { 9600,	UBRR_V(9600)	},
    { 14400,	UBRR_V(14400)	},
    { 19200,	UBRR_V(19200)	},
    { 38400,	UBRR_V(38400)	},
    { 57600,	UBRR_V(57600)	},
    { 115200,	UBRR_V(115200)	},
    { 230400,	UBRR_V(230400)	},
};
int avr_ubrrs_max = sizeof(avr_ubrrs) / sizeof (avr_usart_baud_setting);

int rj485_setbaud(int bps)
{
    int i = 0;
    
    while (i < avr_ubrrs_max) {
	if (avr_ubrrs[i].bps == bps)
	    return rj_writeword(BPS485, avr_ubrrs[i].ubrr);
	i++;
    }
    return -1;
}

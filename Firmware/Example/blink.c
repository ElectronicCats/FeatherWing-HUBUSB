// Based in the work of Kali Prasad, visit this link for information: 
// https://kprasadvnsi.com/posts/bare-metal-ch559-pt1/

#include <compiler.h>
#include <stdint.h>

SFR(PORT_CFG,	0xC6); // Port Configuration Register
SFR(P3_DIR,	0xBE);	// P3 port direction control register
SFR(P3,	0xB0);	// P3 port input and output register

SBIT(LED2, 0xB0, 2); // accessing pin 3.2

static inline void delay() 
{
    uint32_t i;
    for (i = 0; i < (120000UL); i++){}
        __asm__("nop");
}

void main() 
{
	PORT_CFG = 0b00101001;
    P3_DIR = 0b00001111;
	P3 = 0x00;

	while (1) 
	{
		delay();
		LED2 = !LED2;
	}
}
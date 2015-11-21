#include  "cc430F6137.h"
#include <string.h>

void main(void)
{
    unsigned char *lcdmem;

    // Clear entire display memory
    LCDBMEMCTL |= LCDCLRBM + LCDCLRM;

    // LCD_FREQ = ACLK/16/8 = 256Hz
    // Frame frequency = 256Hz/4 = 64Hz, LCD mux 4, LCD on
    LCDBCTL0 = (LCDDIV0 + LCDDIV1 + LCDDIV2 + LCDDIV3) | (LCDPRE0 + LCDPRE1) | LCD4MUX | LCDON;

    // LCB_BLK_FREQ = ACLK/8/4096 = 1Hz
    LCDBBLKCTL = LCDBLKPRE0 | LCDBLKPRE1 | LCDBLKDIV0 | LCDBLKDIV1 | LCDBLKDIV2 | LCDBLKMOD0;

    // I/O to COM outputs
    P5SEL |= (BIT5 | BIT6 | BIT7);
    P5DIR |= (BIT5 | BIT6 | BIT7);

    // Activate LCD output
    LCDBPCTL0 = 0xFFFF;  // Select LCD segments S0-S15
    LCDBPCTL1 = 0x00FF;  // Select LCD segments S16-S22

    // LCD Display
    lcdmem  = (unsigned char *)0x0A21;
    *lcdmem = (unsigned char)(*lcdmem | (BIT1));

    __no_operation();  // For debugger
}

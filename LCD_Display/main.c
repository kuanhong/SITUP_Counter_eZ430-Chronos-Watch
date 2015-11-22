#include <msp430.h>

// LCD Segments
#define LCD_A    BIT4
#define LCD_B    BIT5
#define LCD_C    BIT6
#define LCD_D    BIT7
#define LCD_F    BIT0
#define LCD_G    BIT1
#define LCD_E    BIT2
#define LCD_H    BIT3

// LCD Segment Mapping
const unsigned char  LCD_Char_Map[] =
{
  LCD_A+LCD_B+LCD_C+LCD_D+LCD_E+LCD_F,        // '0' or 'O'
  LCD_B+LCD_C,                                // '1' or 'I'
  LCD_A+LCD_B+LCD_D+LCD_E+LCD_G,              // '2' or 'Z'
  LCD_A+LCD_B+LCD_C+LCD_D+LCD_G,              // '3'
  LCD_B+LCD_C+LCD_F+LCD_G,                    // '4' or 'y'
  LCD_A+LCD_C+LCD_D+LCD_F+LCD_G,              // '5' or 'S'
  LCD_A+LCD_C+LCD_D+LCD_E+LCD_F+LCD_G,        // '6' or 'b'
  LCD_A+LCD_B+LCD_C,                          // '7'
  LCD_A+LCD_B+LCD_C+LCD_D+LCD_E+LCD_F+LCD_G,  // '8' or 'B'
  LCD_A+LCD_B+LCD_C+LCD_D+LCD_F+LCD_G,        // '9' or 'g'
};

int main(void)
{
  int i;
  WDTCTL = WDTPW + WDTHOLD;             // Stop WDT

  // Select LCD COM pins
//  P5SEL |= (BIT5 | BIT6 | BIT7);
//  P5DIR |= (BIT5 | BIT6 | BIT7);

  // Configure LCD_B
  // LCD_FREQ = ACLK/32/4, LCD Mux 4, turn on LCD
  // Charge pump generated internally at 3.44V, external bias (V2-V4) generation
  // Internal reference for charge pump
//  LCDBCTL0 =  (LCDDIV0 + LCDDIV1 + LCDDIV2 + LCDDIV3 + LCDDIV4)| LCDPRE0 | LCD4MUX | LCDON | LCDSON;
//  LCDBVCTL = LCDCPEN | VLCD_3_44;
//  LCDBCTL0 |= LCDON + LCDSON;
//  REFCTL0 &= ~REFMSTR;

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

  // Select LCD Segments 4-5
//  LCDBPCTL0 = 0x0030;
  LCDBPCTL0 = 0x00CFC;
  LCDBPCTL1 = 0x0000;

  unsigned char hundreds,tens,ones;

  while (1)
  {
    for (i = 999; i > 0; i--)
    {
    	hundreds = i % 1000 / 100;
    	tens= i % 100 / 10;
    	ones=i % 10;

    	LCDM2 = LCD_Char_Map[hundreds];          // Display Character
    	LCDM3 = LCD_Char_Map[tens];          // Display Character
    	LCDM4 = LCD_Char_Map[ones];          // Display Character
//      LCDM6 = LCD_Char_Map[i];          // Display Character

      __delay_cycles(1000000);           // Delay ~1sec
    }
    __no_operation();
  }
}

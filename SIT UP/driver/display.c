// *************************************************************************************************
//      Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
//
//        Redistribution and use in source and binary forms, with or without
//        modification, are permitted provided that the following conditions
//        are met:
//
//          Redistributions of source code must retain the above copyright
//          notice, this list of conditions and the following disclaimer.
//
//          Redistributions in binary form must reproduce the above copyright
//          notice, this list of conditions and the following disclaimer in the
//          documentation and/or other materials provided with the
//          distribution.
//
//          Neither the name of Texas Instruments Incorporated nor the names of
//          its contributors may be used to endorse or promote products derived
//          from this software without specific prior written permission.
//
//        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//        "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//        LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//        A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//        OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//        SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//        LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//        DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//        THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//        (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//        OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *************************************************************************************************
// Display functions.
// *************************************************************************************************
// Include section

// system
#include <project.h>
#include <string.h>

// driver
#include "display.h"

// logic
#include "stopwatch.h"

// *************************************************************************************************
// Prototypes section
void write_lcd_mem(unsigned char * lcdmem, unsigned char bits, unsigned char bitmask, unsigned char state);
void clear_line(unsigned char line);
void display_symbol(unsigned char symbol, unsigned char mode);
void display_char(unsigned char segment, unsigned char chr, unsigned char mode);
void display_chars(unsigned char segments, unsigned char * str, unsigned char mode);

// Table with memory bit assignment for digits "0" to "9" and characters "A" to "Z"
const unsigned char lcd_font[] = {
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F,         // Displays "0"
    SEG_B + SEG_C,                                         // Displays "1"
    SEG_A + SEG_B + SEG_D + SEG_E + SEG_G,                 // Displays "2"
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_G,                 // Displays "3"
    SEG_B + SEG_C + SEG_F + SEG_G,                         // Displays "4"
    SEG_A + SEG_C + SEG_D + SEG_F + SEG_G,                 // Displays "5"
    SEG_A + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G,         // Displays "6"
    SEG_A + SEG_B + SEG_C,                                 // Displays "7"
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G, // Displays "8"
    SEG_A + SEG_B + SEG_C + SEG_D + SEG_F + SEG_G,         // Displays "9"
};

// Table with memory address for each display element
const unsigned char *segments_lcdmem[] = {
	LCD_ICON_STOPWATCH_MEM,				// 0
	LCD_UNIT_L1_DEGREE_MEM,
	LCD_UNIT_L1_DEGREE_MEM,
	LCD_UNIT_L1_DEGREE_MEM,
	LCD_UNIT_L1_DEGREE_MEM,
	LCD_UNIT_L1_DEGREE_MEM,
	LCD_UNIT_L1_DEGREE_MEM,
	LCD_UNIT_L1_DEGREE_MEM,
	LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_UNIT_L1_DEGREE_MEM,
    LCD_ICON_ALARM_MEM,
    LCD_ICON_ALARM_MEM,				// 20
//  LCD_ICON_STOPWATCH_MEM,			// 20
    LCD_ICON_ALARM_MEM,
    LCD_ICON_ALARM_MEM,
    LCD_ICON_ALARM_MEM,
    LCD_ICON_ALARM_MEM,
    LCD_ICON_ALARM_MEM,
    LCD_SEG_L1_3_MEM,
    LCD_SEG_L1_2_MEM,
    LCD_SEG_L1_1_MEM,
    LCD_SEG_L1_0_MEM,
    LCD_SEG_L1_COL_MEM,
    LCD_SEG_L1_DP1_MEM,
    LCD_SEG_L1_DP0_MEM,
    LCD_SEG_L2_5_MEM,
    LCD_SEG_L2_4_MEM,
    LCD_SEG_L2_3_MEM,
    LCD_SEG_L2_2_MEM,
    LCD_SEG_L2_1_MEM,
    LCD_SEG_L2_0_MEM,
    LCD_SEG_L2_COL1_MEM,
    LCD_SEG_L2_COL0_MEM,
    LCD_SEG_L2_DP_MEM,
};

// Table with bit mask for each display element
const unsigned char segments_bitmask[] = {
	LCD_ICON_STOPWATCH_MASK,		// 0
	LCD_UNIT_L1_DEGREE_MASK,
	LCD_UNIT_L1_DEGREE_MASK,
	LCD_UNIT_L1_DEGREE_MASK,
	LCD_UNIT_L1_DEGREE_MASK,
	LCD_UNIT_L1_DEGREE_MASK,
	LCD_UNIT_L1_DEGREE_MASK,
	LCD_UNIT_L1_DEGREE_MASK,
	LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_UNIT_L1_DEGREE_MASK,
    LCD_ICON_ALARM_MASK,
    LCD_ICON_ALARM_MASK,			// 20
//  LCD_ICON_STOPWATCH_MASK,		// 20
    LCD_ICON_ALARM_MASK,
    LCD_ICON_ALARM_MASK,
    LCD_ICON_ALARM_MASK,
    LCD_ICON_ALARM_MASK,
    LCD_ICON_ALARM_MASK,
    LCD_SEG_L1_3_MASK,
    LCD_SEG_L1_2_MASK,
    LCD_SEG_L1_1_MASK,
    LCD_SEG_L1_0_MASK,
    LCD_SEG_L1_COL_MASK,
    LCD_SEG_L1_DP1_MASK,
    LCD_SEG_L1_DP0_MASK,
    LCD_SEG_L2_5_MASK,
    LCD_SEG_L2_4_MASK,
    LCD_SEG_L2_3_MASK,
    LCD_SEG_L2_2_MASK,
    LCD_SEG_L2_1_MASK,
    LCD_SEG_L2_0_MASK,
    LCD_SEG_L2_COL1_MASK,
    LCD_SEG_L2_COL0_MASK,
    LCD_SEG_L2_DP_MASK,
};

// Quick integer to array conversion table for most common integer values

const unsigned char int_to_array_conversion_table[][3] = {
	"000", "001", "002", "003", "004", "005", "006", "007", "008", "009", "010", "011", "012",
	"013", "014", "015",
	"016", "017","018", "019", "020", "021", "022", "023", "024", "025", "026", "027", "028",
    "029", "030", "031",
    "032", "033", "034", "035", "036", "037", "038", "039", "040", "041", "042", "043", "044",
    "045", "046", "047",
    "048", "049", "050", "051", "052", "053", "054", "055", "056", "057", "058", "059", "060",
    "061", "062", "063",
    "064", "065", "066", "067", "068", "069", "070", "071", "072", "073", "074", "075", "076",
    "077", "078", "079",
    "080", "081", "082", "083", "084", "085", "086", "087", "088", "089", "090", "091", "092",
    "093", "094", "095",
    "096", "097", "098", "099",
};

// Display flags
volatile s_display_flags display;

// Global return string for int_to_array function
unsigned char int_to_array_str[8];

// *************************************************************************************************
// Extern section
extern void (*fptr_lcd_function_line1)(unsigned char line, unsigned char update);
extern void (*fptr_lcd_function_line2)(unsigned char line, unsigned char update);

// *************************************************************************************************
// @fn          lcd_init
// @brief       Erase LCD memory. Init LCD peripheral.
// @param       none
// @return      none
// *************************************************************************************************
void lcd_init(void)
{
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
    LCDBPCTL0 = 0xFFFF;         // Select LCD segments S0-S15
    LCDBPCTL1 = 0x00FF;         // Select LCD segments S16-S22

#ifdef USE_LCD_CHARGE_PUMP
    // Charge pump voltage generated internally, internal bias (V2-V4) generation
    LCDBVCTL = LCDCPEN | VLCD_2_72;
#endif
}

// *************************************************************************************************
// @fn          clear_line
// @brief       Erase segments of a given line.
// @param       unsigned char line LINE1, LINE2
// @return      none
// *************************************************************************************************
void clear_line(unsigned char line)
{
    if (line == LINE1)
    {
        display_symbol(LCD_SEG_L1_DP1, SEG_OFF);
        display_symbol(LCD_SEG_L1_DP0, SEG_OFF);
        display_symbol(LCD_SEG_L1_COL, SEG_OFF);
    }
    else                        // line == LINE2
    {
        display_symbol(LCD_SEG_L2_DP, SEG_OFF);
        display_symbol(LCD_SEG_L2_COL1, SEG_OFF);
        display_symbol(LCD_SEG_L2_COL0, SEG_OFF);
    }
}

// *************************************************************************************************
// @fn          write_segment
// @brief       Write to one or multiple LCD segments
// @param       lcdmem          Pointer to LCD byte memory
//                              bits            Segments to address
//                              bitmask         Bitmask for particular display item
//                              mode            On, off or blink segments
// @return
// *************************************************************************************************
void write_lcd_mem(unsigned char * lcdmem, unsigned char bits, unsigned char bitmask, unsigned char state)
{
    if (state == SEG_ON)
    {
        // Clear segments before writing
        *lcdmem = (unsigned char) (*lcdmem & ~bitmask);

        // Set visible segments
        *lcdmem = (unsigned char) (*lcdmem | bits);
    }
    else if (state == SEG_OFF)
    {
        // Clear segments
        *lcdmem = (unsigned char) (*lcdmem & ~bitmask);
    }
}

// *************************************************************************************************
// @fn          int_to_array
// @brief       Generic integer to array routine. Converts integer n to string.
//                              Default conversion result has leading zeros, e.g. "00123"
//                              Option to convert leading '0' into whitespace (blanks)
// @param       unsigned int n                   integer to convert
//                              unsigned char digits               number of digits
//                              unsigned char blanks               fill up result string with number of
// whitespaces instead of leading zeros
// @return      unsigned char                              string
// *************************************************************************************************
unsigned char *int_to_array(unsigned int n, unsigned char digits, unsigned char blanks)
{
    unsigned char i;
    unsigned char digits1 = digits;

    // Preset result string
    memcpy(int_to_array_str, "0000000", 7);

    // Return empty string if number of digits is invalid (valid range for digits: 1-7)
    if ((digits == 0) || (digits > 7))
        return (int_to_array_str);

    // Numbers 0 .. 180 can be copied from int_to_array_conversion_table without conversion
    if (n <= 180)
    {
        if (digits >= 3)
        {
            memcpy(int_to_array_str + (digits - 3), int_to_array_conversion_table[n], 3);
        }
        else                    // digits == 1 || 2
        {
            memcpy(int_to_array_str, int_to_array_conversion_table[n] + (3 - digits), digits);
        }
    }

    // Remove specified number of leading '0', always keep last one
    i = 0;
    while ((int_to_array_str[i] == '0') && (i < digits1 - 1))
    {
        if (blanks > 0)
        {
            // Convert only specified number of leading '0'
            int_to_array_str[i] = ' ';
            blanks--;
        }
        i++;
    }

    return (int_to_array_str);
}

// *************************************************************************************************
// @fn          display_symbol
// @brief       Switch symbol on or off on LCD.
// @param       unsigned char symbol               A valid LCD symbol (index 0..42)
//                              unsigned char state                SEG_ON, SEG_OFF, SEG_BLINK
// @return      none
// *************************************************************************************************
void display_symbol(unsigned char symbol, unsigned char mode)
{
    unsigned char *lcdmem;
    unsigned char bits;
    unsigned char bitmask;

    if (symbol <= LCD_SEG_L2_DP)
    {
        // Get LCD memory address for symbol from table
        lcdmem = (unsigned char *) segments_lcdmem[symbol];

        // Get bits for symbol from table
        bits = segments_bitmask[symbol];

        // Bitmask for symbols equals bits
        bitmask = bits;

        // Write LCD memory
        write_lcd_mem(lcdmem, bits, bitmask, mode);
    }
}

// *************************************************************************************************
// @fn          display_char
// @brief       Write to 7-segment characters.
// @param       unsigned char segment              A valid LCD segment
//                              unsigned char chr                  Character to display
//                              unsigned char mode         SEG_ON, SEG_OFF, SEG_BLINK
// @return      none
// *************************************************************************************************
void display_char(unsigned char segment, unsigned char chr, unsigned char mode)
{
    unsigned char *lcdmem;                 // Pointer to LCD memory
    unsigned char bitmask;                 // Bitmask for character
    unsigned char bits, bits1;             // Bits to write

    // Write to single 7-segment character
    if ((segment >= LCD_SEG_L1_3) && (segment <= LCD_SEG_L2_DP))
    {
        // Get LCD memory address for segment from table
        lcdmem = (unsigned char *) segments_lcdmem[segment];

        // Get bitmask for character from table
        bitmask = segments_bitmask[segment];

        // Get bits from font set
        if ((chr >= 0x30) && (chr <= 0x5A))
        {
            // Use font set
            bits = lcd_font[chr - 0x30];
        }
        else if (chr == 0x2D)
        {
            // '-' not in font set
            bits = BIT1;
        }
        else
        {
            // Other characters map to ' ' (blank)
            bits = 0;
        }

        // When addressing LINE2 7-segment characters need to swap high- and low-nibble,
        // because LCD COM/SEG assignment is mirrored against LINE1
        if (segment >= LCD_SEG_L2_5)
        {
            bits1 = ((bits << 4) & 0xF0) | ((bits >> 4) & 0x0F);
            bits = bits1;

            // When addressing LCD_SEG_L2_5, need to convert ASCII '1' and 'L' to 1 bit,
            // because LCD COM/SEG assignment is special for this incomplete character
            if (segment == LCD_SEG_L2_5)
            {
                if ((chr == '1') || (chr == 'L'))
                    bits = BIT7;
            }
        }

        // Physically write to LCD memory
        write_lcd_mem(lcdmem, bits, bitmask, mode);
    }
}

// *************************************************************************************************
// @fn          display_chars
// @brief       Write to consecutive 7-segment characters.
// @param       unsigned char segments     LCD segment array
//                              unsigned char * str                Pointer to a string
//                              unsigned char mode             SEG_ON, SEG_OFF, SEG_BLINK
// @return      none
// *************************************************************************************************
void display_chars(unsigned char segments, unsigned char * str, unsigned char mode)
{
    unsigned char i;
    unsigned char length = 0;              // Write length
    unsigned char char_start;              // Starting point for consecutive write

    switch (segments)
    {
        // LINE1
        case LCD_SEG_L1_3_0:
            length = 4;
            char_start = LCD_SEG_L1_3;
            break;
        case LCD_SEG_L1_2_0:
            length = 3;
            char_start = LCD_SEG_L1_2;
            break;
        case LCD_SEG_L1_1_0:
            length = 2;
            char_start = LCD_SEG_L1_1;
            break;
        case LCD_SEG_L1_3_1:
            length = 3;
            char_start = LCD_SEG_L1_3;
            break;
        case LCD_SEG_L1_3_2:
            length = 2;
            char_start = LCD_SEG_L1_3;
            break;

        // LINE2
        case LCD_SEG_L2_5_0:
            length = 6;
            char_start = LCD_SEG_L2_5;
            break;
        case LCD_SEG_L2_4_0:
            length = 5;
            char_start = LCD_SEG_L2_4;
            break;
        case LCD_SEG_L2_3_0:
            length = 4;
            char_start = LCD_SEG_L2_3;
            break;
        case LCD_SEG_L2_2_0:
            length = 3;
            char_start = LCD_SEG_L2_2;
            break;
        case LCD_SEG_L2_1_0:
            length = 2;
            char_start = LCD_SEG_L2_1;
            break;
        case LCD_SEG_L2_5_4:
            length = 2;
            char_start = LCD_SEG_L2_5;
            break;
        case LCD_SEG_L2_5_2:
            length = 4;
            char_start = LCD_SEG_L2_5;
            break;
        case LCD_SEG_L2_3_2:
            length = 2;
            char_start = LCD_SEG_L2_3;
            break;
        case LCD_SEG_L2_4_2:
            length = 3;
            char_start = LCD_SEG_L2_4;
            break;
    }

    // Write to consecutive digits
    for (i = 0; i < length; i++)
    {
        // Use single character routine to write display memory
        display_char(char_start + i, *(str + i), mode);
    }
}

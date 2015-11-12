/*
 *  scroller.c
 *
 *  Copyright: 2011, 2014
 *  Author: doprescu, jeanniel
 */


// *************************************************************************************************
// LCD scroller
// *************************************************************************************************

// *************************************************************************************************
// Include section

// system
#include "project.h"

// driver
#include "display.h"
#include "bmp_as.h"
#include "cma_as.h"
#include "as.h"

// logic
#include "scroller.h"
#include "simpliciti.h"
#include "user.h"
#include "string.h"

// ******************************************
// Global Variable section
struct scroll scroller;

// ******************************************
// Extern section

// ******************************************
// @fn          reset_scroller
// @brief       Reset / INIT scroller data.
// @param       none
// @return      none
// ******************************************
void reset_scroller(void)
{
	const char *LCD_MESSAGE = "SIT UP";

    // Reset state is not active
    scroller.mode = SCROLLER_MODE_OFF;

    strcpy(scroller.msg, LCD_MESSAGE);

}

// ******************************************
// @fn          sx_scroller
// @brief       Button UP does nothing for now.
// @param       u8 line     LINE2
// @return      none
// ******************************************
void sx_scroller(u8 line)
{

}

// ******************************************
// @fn          display_scroller
// @brief       Display routine.
// @param       u8 line         LINE1
//              u8 update       DISPLAY_LINE_UPDATE_FULL, DISPLAY_LINE_CLEAR
// @return      none
// ******************************************
void display_scroller(u8 line, u8 update)
{
    if (update == DISPLAY_LINE_UPDATE_FULL)
    {
        display_chars(LCD_SEG_L1_3_0, scroller.msg, SEG_ON);
        display_symbol(LCD_ICON_HEART, SEG_ON_BLINK_ON);

        // Set mode
        scroller.mode = SCROLLER_MODE_ON;
    }
    else if (update == DISPLAY_LINE_UPDATE_PARTIAL)
    {
        display_chars(LCD_SEG_L1_3_0, scroller.msg, SEG_ON);
    }
    else if (update == DISPLAY_LINE_CLEAR)
    {
        display_symbol(LCD_ICON_HEART, SEG_OFF);

        reset_scroller();
    }
}

// ******************************************
// @fn          is_scroller_active
// @brief       Returns 1 if scroller module is currently active
// @param       none
// @return      u8      1 = scroller module currently active
// ******************************************
u8 is_scroller_active(void)
{
    return scroller.mode == SCROLLER_MODE_ON;
}

// ******************************************
// @fn          do_scroll
// @brief       Returns 1
// @param       none
// @return      u8      1
// ******************************************
void do_scroll(void)
{
    // Move the text
    u8 firstElem = scroller.msg[0];
    u8 len = sizeof(scroller.msg) / sizeof(u8);
    u8 i;
    for (i = 0; i < len - 1; i++) {
    	scroller.msg[i] = scroller.msg[i+1];
    }
    scroller.msg[len - 1] = firstElem;

    // Set display update flag
    display.flag.update_scroller = 1;
}

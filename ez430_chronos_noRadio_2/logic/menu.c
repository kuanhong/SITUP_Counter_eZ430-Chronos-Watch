// *************************************************************************************************
//
//      Copyright (C) 2009 Texas Instruments Incorporated - http://www.ti.com/
//
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
//
// *************************************************************************************************
// Menu management functions.
// *************************************************************************************************

// *************************************************************************************************
// Include section

// system
#include "project.h"

// driver
#include "display.h"

// logic
#include "menu.h"
#include "user.h"
#include "clock.h"
#include "stopwatch.h"
#include "battery.h"
#include "acceleration.h"

#include <string.h>

// *************************************************************************************************
// Defines section
#define FUNCTION(function)  function

// *************************************************************************************************
// Global Variable section
const struct menu *ptrMenu_L1 = NULL;
const struct menu *ptrMenu_L2 = NULL;

// *************************************************************************************************
// Global Variable section

void display_nothing(unsigned char line, unsigned char update)
{
}

unsigned char update_time(void)
{
    return (display.flag.update_time);
}

unsigned char update_stopwatch(void)
{
    return (display.flag.update_stopwatch);
}

unsigned char update_battery_voltage(void)
{
    return (display.flag.update_battery_voltage);
}

unsigned char update_acceleration(void)
{
    return (display.flag.update_acceleration);
}

// *************************************************************************************************
// User navigation ( [____] = default menu item after reset )
//
//      LINE1:  [Time] -> Speed -> Acceleration
//
//      LINE2:  Stopwatch -> Battery  -> ACC -> PPT -> SYNC --> RFBSL
// *************************************************************************************************

// Line1 - Time
const struct menu menu_L1_Time = {
    FUNCTION(sx_time),                // direct function
    FUNCTION(mx_time),                // sub menu function
    FUNCTION(display_time),           // display function
    FUNCTION(update_time),            // new display data
};

// Line1 - Speed
const struct menu menu_L1_Speed = {
    FUNCTION(dummy),                  // direct function
    FUNCTION(dummy),                  // sub menu function
    FUNCTION(display_nothing),		// insert by alwy
    FUNCTION(update_time),            // new display data
    &menu_L1_Acceleration,
};

// Line1 - Acceleration
const struct menu menu_L1_Acceleration = {
    FUNCTION(sx_acceleration),        // direct function
    FUNCTION(dummy),                  // sub menu function
    FUNCTION(display_acceleration),   // display function
    FUNCTION(update_acceleration),    // new display data
    &menu_L1_Time,
};

// Line2 - Stopwatch
const struct menu menu_L2_Stopwatch = {
    FUNCTION(sx_stopwatch),           // direct function
    FUNCTION(mx_stopwatch),           // sub menu function
    FUNCTION(display_stopwatch),      // display function
    FUNCTION(update_stopwatch),       // new display data
    &menu_L2_Battery,
};

// Line2 - Battery
const struct menu menu_L2_Battery = {
    FUNCTION(dummy),                  // direct function
    FUNCTION(dummy),                  // sub menu function
    FUNCTION(display_battery_V),      // display function
    FUNCTION(update_battery_voltage), // new display data
    &menu_L2_Rf,
};

// Line2 - ACC (acceleration data + button events via SimpliciTI)
const struct menu menu_L2_Rf = {
    FUNCTION(dummy),                  // direct function
    FUNCTION(dummy),                  // sub menu function
    FUNCTION(display_nothing),		// insert by alwy
    FUNCTION(update_time),            // new display data
    &menu_L2_Ppt,
};

// Line2 - PPT (button events via SimpliciTI)
const struct menu menu_L2_Ppt = {
	FUNCTION(dummy),                  // direct function
    FUNCTION(dummy),                  // sub menu function
    FUNCTION(display_nothing),		// insert by alwy
    FUNCTION(update_time),            // new display data
    &menu_L2_Sync,
};

// Line2 - SXNC (synchronization/data download via SimpliciTI)
const struct menu menu_L2_Sync = {
	FUNCTION(dummy),                  // direct function
    FUNCTION(dummy),                  // sub menu function
    FUNCTION(display_nothing),		// insert by alwy
    FUNCTION(update_time),            // new display data
    &menu_L2_CalDist,
};

// Line2 - Calories/Distance
const struct menu menu_L2_CalDist = {
	FUNCTION(dummy),                  // direct function
    FUNCTION(dummy),                  // sub menu function
    FUNCTION(display_nothing),		// insert by alwy
    FUNCTION(update_time),            // new display data
    &menu_L2_RFBSL,
};

// Line2 - RFBSL
const struct menu menu_L2_RFBSL = {
	FUNCTION(dummy),                  // direct function
    FUNCTION(dummy),                  // sub menu function
    FUNCTION(display_nothing),		// insert by alwy
    FUNCTION(update_time),            // new display data
};

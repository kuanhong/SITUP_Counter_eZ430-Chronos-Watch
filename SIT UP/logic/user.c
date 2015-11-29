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
// Several user functions.
// *************************************************************************************************

// system
#include "project.h"

// driver
#include "display.h"
#include "buzzer.h"
#include "ports.h"

// logic
#include "menu.h"
#include "user.h"
#include "stopwatch.h"

// *************************************************************************************************
// Extern section
extern void idle_loop(void);

// *************************************************************************************************
// @fn          dummy
// @brief       Dummy direct function.
// @param       unsigned char line LINE1, LINE2
// @return      none
// *************************************************************************************************
void dummy(unsigned char line)
{
}

// *************************************************************************************************
// @fn          set_value
// @brief       Generic value setting routine
// @param       int * value                                                     Pointer to value to
// set
//                              unsigned chardigits
//                                                        Number of digits
//                              unsigned char blanks
//                                                       Number of whitespaces before first valid
// digit
//                              int limitLow                                            Lower limit
// of value
//                              int limitHigh                                           Upper limit
// of value
//                              unsigned short mode
//                              unsigned char segments
//                                                     Segments where value should be drawn
//                              fptr_setValue_display_function1         Value-specific display
// routine
// @return      none
// *************************************************************************************************
void set_value(int * value, unsigned char digits, unsigned char blanks, int limitLow, int limitHigh, unsigned short mode,
               unsigned char segments,
               void (*fptr_setValue_display_function1)(unsigned char segments, unsigned int value, unsigned char digits,
                                                       unsigned char blanks))
{
    unsigned char stopwatch_state;

    // Clear button flags
    button.all_flags = 0;

    // For safety only - buzzer on/off and button_repeat share same IRQ
    stop_buzzer();

    // Init step size and repeat counter
    sButton.repeats = 0;

    // Turn on 200ms button repeat function
    button_repeat_on(200);

    // Turn off button repeat function
    button_repeat_off();

    // Enable stopwatch display updates again
    sStopwatch.state = stopwatch_state;
}

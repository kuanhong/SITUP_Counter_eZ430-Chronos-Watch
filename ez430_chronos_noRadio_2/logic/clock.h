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

#ifndef CLOCK_H_
#define CLOCK_H_

// *************************************************************************************************
// Defines section

// Definitions for time format
#define TIMEFORMAT_24H          (0u)
#define TIMEFORMAT_12H          (1u)

// *************************************************************************************************
// Prototypes section
extern void reset_clock(void);
extern void sx_time(unsigned char line);
extern void mx_time(unsigned char line);
extern void clock_tick(void);
extern void display_selection_Timeformat1(unsigned char segments, unsigned int index, unsigned char digits, unsigned char blanks);
extern void display_time(unsigned char line, unsigned char update);

// English units support
extern void calc_24H_to_12H(unsigned char * hours, unsigned char * timeAM);
extern unsigned char convert_hour_to_12H_format(unsigned char hour);
extern unsigned char is_hour_am(unsigned char hour);

// *************************************************************************************************
// Global Variable section
struct time
{
    unsigned int system_time;            // Global system time. Used to calculate last activity
    unsigned int last_activity;          // Inactivity detection (exits set_value() function)
    unsigned char drawFlag;                // Flag to minimize display updates
    unsigned char line1ViewStyle;          // Viewing style
    unsigned char hour;                    // Time data
    unsigned char minute;                  // Time data
    unsigned char second;                  // Time data
};
extern struct time sTime;

#endif                          /*CLOCK_H_ */
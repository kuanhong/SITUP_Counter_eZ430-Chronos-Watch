/*
 *  scroller.h
 *
 *  Copyright: 2011, 2014
 *  Author: doprescu, jeanniel 
 */


#ifndef SCROLLER_H_
#define SCROLLER_H_

// ******************************************
// Defines section
#define SCROLLER_MODE_OFF     (0u)
#define SCROLLER_MODE_ON      (1u)

// ******************************************
// Global Variable section
struct scroll
{
    u8          mode;    // SCROLLER_MODE_OFF, SCROLLER_MODE_ON
    u8          msg[11]; // Data to display
};
extern struct scroll scroller;

// ******************************************
// Extern section
extern void reset_scroller(void);
extern void sx_scroller(u8 line);
extern void display_scroller(u8 line, u8 update);
extern u8 is_scroller_active(void);
extern void do_scroll(void);

#endif /* SCROLLER_H_ */

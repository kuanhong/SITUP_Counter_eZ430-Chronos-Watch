// *************************************************************************************************
//	Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
//
//	  Redistribution and use in source and binary forms, with or without 
//	  modification, are permitted provided that the following conditions 
//	  are met:
//	
//	    Redistributions of source code must retain the above copyright 
//	    notice, this list of conditions and the following disclaimer.
//	 
//	    Redistributions in binary form must reproduce the above copyright
//	    notice, this list of conditions and the following disclaimer in the 
//	    documentation and/or other materials provided with the   
//	    distribution.
//	 
//	    Neither the name of Texas Instruments Incorporated nor the names of
//	    its contributors may be used to endorse or promote products derived
//	    from this software without specific prior written permission.
//	
//	  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//	  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//	  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//	  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//	  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//	  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//	  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//	  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//	  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//	  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//	  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *************************************************************************************************

#ifndef BMP_AS_H_
#define BMP_AS_H_

// *************************************************************************************************
// Prototypes section
extern void bmp_as_start(void);
extern void bmp_as_stop(void);
extern unsigned char bmp_as_read_register(unsigned char bAddress);
extern unsigned char bmp_as_write_register(unsigned char bAddress, unsigned char bData);
extern void bmp_as_get_data(unsigned char * data);

/********************************************************************
* Bosch BMA250
* Register Map
********************************************************************/

#define BMP_CHIPID           (0x00)
#define BMP_ACC_X_LSB        (0x02)
#define BMP_ACC_X_MSB        (0x03)
#define BMP_ACC_Y_LSB        (0x04)
#define BMP_ACC_Y_MSB        (0x05)

#define BMP_GRANGE           (0x0F)	   // g Range
#define BMP_BWD              (0x10)	   // Bandwidth
#define BMP_PM               (0x11)	   // Power modes
#define BMP_SCR              (0x13)	   // Special Control Register
#define BMP_RESET            (0x14)	   // Soft reset register (writing 0xB6 causes reset)
#define BMP_ISR1             (0x16)	   // Interrupt settings register 1
#define BMP_ISR2             (0x17)	   // Interrupt settings register 2
#define BMP_IMR1             (0x19)	   // Interrupt mapping register 1
#define BMP_IMR2             (0x1A)	   // Interrupt mapping register 2
#define BMP_IMR3             (0x1B)	   // Interrupt mapping register 3

#endif /*BMP_AS_H_*/

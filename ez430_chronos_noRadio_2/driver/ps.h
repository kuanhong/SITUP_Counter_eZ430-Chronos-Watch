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

#ifndef PS_H_
#define PS_H_

// *************************************************************************************************
// Include section

// *************************************************************************************************
// Prototypes section
extern void ps_init(void);
extern unsigned char ps_i2c_sda(unsigned char ack);
extern void ps_i2c_delay(void);
extern void ps_i2c_write(unsigned char data);
extern unsigned char ps_i2c_read(unsigned char ack);
extern unsigned char ps_write_register(unsigned char device, unsigned char address, unsigned char data);
extern unsigned short ps_read_register(unsigned char device, unsigned char address, unsigned char mode);
extern void init_pressure_table(void);
extern void update_pressure_table(short href, unsigned int p_meas, unsigned short t_meas);
extern short conv_pa_to_meter(unsigned int p_meas, unsigned short t_meas);

// *************************************************************************************************
// Defines section

// Port and pin resource for I2C interface to pressure sensor
// SCL=PJ.3, SDA=PJ.2, EOC=P2.6
#define PS_I2C_IN            (PJIN)
#define PS_I2C_OUT           (PJOUT)
#define PS_I2C_DIR           (PJDIR)
#define PS_I2C_REN           (PJREN)
#define PS_SCL_PIN           (BIT3)
#define PS_SDA_PIN           (BIT2)

// Port, pin and interrupt resource for interrupt from acceleration sensor, EOC=P2.6
#define PS_INT_IN            (P2IN)
#define PS_INT_OUT           (P2OUT)
#define PS_INT_DIR           (P2DIR)
#define PS_INT_IE            (P2IE)
#define PS_INT_IES           (P2IES)
#define PS_INT_IFG           (P2IFG)
#define PS_INT_PIN           (BIT6)

// I2C defines
#define PS_I2C_WRITE         (0u)
#define PS_I2C_READ          (1u)

#define PS_I2C_SEND_START    (0u)
#define PS_I2C_SEND_RESTART  (1u)
#define PS_I2C_SEND_STOP     (2u)
#define PS_I2C_CHECK_ACK     (3u)

#define PS_I2C_8BIT_ACCESS   (0u)
#define PS_I2C_16BIT_ACCESS  (1u)

#define PS_I2C_SCL_HI        { PS_I2C_OUT |=  PS_SCL_PIN; }
#define PS_I2C_SCL_LO        { PS_I2C_OUT &= ~PS_SCL_PIN; }
#define PS_I2C_SDA_HI        { PS_I2C_OUT |=  PS_SDA_PIN; }
#define PS_I2C_SDA_LO        { PS_I2C_OUT &= ~PS_SDA_PIN; }
#define PS_I2C_SDA_IN        { PS_I2C_OUT |=  PS_SDA_PIN; PS_I2C_DIR &= ~PS_SDA_PIN; }
#define PS_I2C_SDA_OUT       { PS_I2C_DIR |=  PS_SDA_PIN; }

// *************************************************************************************************
// Global Variable section

// *************************************************************************************************
// Extern section

// Global flag for pressure sensor initialisation status
extern unsigned char ps_ok;


#endif                          /*PS_H_ */

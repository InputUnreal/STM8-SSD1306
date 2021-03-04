/*
* Minimal SSD1306 
*/
#include <stdint.h>
#include <stdio.h>
#include "I2C.h"

#ifndef _SSD1306_H
#define _SSD1306_H

//SSD1306 Control  
#define ADDRESS 0x3C        //this is the I2C address 
#define COMMANDBYTE 0x00    //this byte must be sent before sending any commands
#define DATABYTE 0x40       //this byte must be sent before sending any data

//Bitmap of numbers
//USER SHOULD NOT R/W numArr
extern const uint8_t numArr[10][3][16];

//Fundamental Commands - pg28
#define CONTRASTCONTROL     0x81    //command for setting brightness followed by 0-255d
#define DISPLAYRAM          0xA4    //command to display RAM content
#define ENTIREDISPLAYON     0xA5    //command to turn on the whole display
#define NONINVERSE          0xA6    //command to not invert display
#define INVERSE             0xA7    //command the invert display
#define DISPLAYON           0xAF    //command to turn on display
#define DISPLAYOFF          0xAE    //commad to turn off display

void setContrast(uint8_t contrast);
void displayON();
void displayOFF();

//Addressing Setting Commands - pg30-31
//NOTE ONLY VERTICAL AND HORIZONTAL MODES ARE SUPPORTED
#define ADDRESSINGMODE      0x20    //command to set addressing mode followed by mode
#define HORIZONTAL          0x00    //horizontal addressing mode

//Horizontal / Vertical Addressing - pg30-31
#define SETPAGEADDRESS      0x22    //command for setting page address for H||V mode followed by start and end address (0-7d)
//sets the page address both values are inclusive 
static void setPageAddress(uint8_t start, uint8_t end);
#define SETCOLUMNADDRESS    0x21    //command for setting column address for H||V mode followed by start and end address (0-127d)
//set the column address both values are inclusive
static void setColumnAddress(uint8_t start, uint8_t end);

//sets all pixels to 0 value
//expensive only call when needed
void ssd1306_clear();

//initalize the display
void ssd1306_init();

//prints uint16 values both coordiantes are inclusive 
void ssd1306_print(uint16_t number, uint8_t x, uint8_t y);

#endif
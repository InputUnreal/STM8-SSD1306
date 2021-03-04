#include "SSD1306.h"
/*
*Contains the bitmap of numbers 0-9
*index 0 -> number 0 etc
*complier should not load this is SRAM
*/
const uint8_t numArr[10][3][16] = {
    {{0x00,0x00,0xC0,0xE0,0x60,0x30,0x30,0x30,0x30,0x30,0x30,0x60,0xE0,0xC0,0x00,0x00},
    {0x00,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0x00},
    {0x00,0x01,0x07,0x0F,0x0C,0x18,0x18,0x18,0x18,0x18,0x18,0x1C,0x0F,0x07,0x01,0x00}},
    {{0x00,0x00,0x00,0x80,0x80,0xC0,0x60,0x60,0x70,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1A,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00}},
    {{0x00,0x00,0xC0,0xE0,0x60,0x30,0x30,0x30,0x30,0x30,0x30,0x60,0xE0,0xC0,0x00,0x00},
    {0x00,0x00,0x01,0x01,0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x1C,0x0F,0x07,0x00,0x00},
    {0x00,0x00,0x18,0x1C,0x1E,0x1F,0x1B,0x19,0x18,0x18,0x18,0x18,0x18,0x18,0x10,0x00}},
    {{0x00,0x00,0xC0,0xE0,0x60,0x30,0x30,0x30,0x30,0x30,0x30,0x70,0xE0,0xC0,0x00,0x00},
    {0x00,0x00,0x01,0x01,0x00,0x10,0x18,0x18,0x18,0x18,0x38,0x3C,0x67,0xE7,0xC0,0x00},
    {0x00,0x00,0x07,0x0E,0x1C,0x18,0x18,0x18,0x10,0x18,0x18,0x18,0x0E,0x0F,0x03,0x00}},
    {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0x70,0x70,0xF0,0xF0,0x00,0x00,0x00},
    {0x00,0x80,0xE0,0xF0,0x38,0x9E,0x07,0x03,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00},
    {0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x1F,0x1F,0x1F,0x01,0x01,0x00}},
    {{0x00,0x00,0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x00,0x00},
    {0x00,0x00,0x3F,0x3F,0x19,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1C,0x38,0xF0,0xE0,0x00},
    {0x00,0x00,0x07,0x0F,0x1C,0x18,0x18,0x18,0x10,0x18,0x18,0x1C,0x0E,0x07,0x03,0x00}},
    {{0x00,0x00,0x80,0xC0,0xE0,0x70,0x30,0x30,0x30,0x30,0x30,0x70,0xE0,0xC0,0x80,0x00},
    {0x00,0xFE,0xFF,0xFB,0x18,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1C,0x38,0xF0,0xE0,0x00},
    {0x00,0x00,0x03,0x0F,0x0C,0x18,0x18,0x18,0x18,0x18,0x18,0x1C,0x0E,0x07,0x03,0x00}},
    {{0x00,0x00,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0xB0,0xF0,0xF0,0x30,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xF0,0x78,0x1E,0x07,0x03,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x18,0x1E,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
    {{0x00,0x00,0xC0,0xE0,0x60,0x30,0x30,0x30,0x30,0x30,0x30,0x60,0xE0,0xC0,0x00,0x00},
    {0x00,0xC0,0xE3,0x67,0x3C,0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x67,0xE3,0xC0,0x00},
    {0x00,0x03,0x07,0x0E,0x1C,0x18,0x18,0x18,0x10,0x18,0x18,0x1C,0x0E,0x0F,0x03,0x00}},
    {{0x00,0x00,0xC0,0xE0,0x60,0x30,0x30,0x30,0x30,0x30,0x30,0x60,0xE0,0xC0,0x00,0x00},
    {0x00,0x0F,0x1F,0x3D,0x70,0x60,0x60,0x60,0x40,0x60,0x60,0x30,0x3D,0xFF,0xFF,0x00},
    {0x00,0x00,0x06,0x0E,0x1C,0x18,0x18,0x18,0x18,0x18,0x18,0x0C,0x0F,0x07,0x01,0x00}}
};

void setContrast(uint8_t contrast){
    i2c_start();
    i2c_send_addr(ADDRESS<<1);
    i2c_send_byte(COMMANDBYTE);
    i2c_send_byte(CONTRASTCONTROL);
    i2c_send_byte(contrast);
    i2c_stop();
}

void displayON(){
    i2c_start();
    i2c_send_addr(ADDRESS<<1);
    i2c_send_byte(COMMANDBYTE);
    i2c_send_byte(DISPLAYON);
    i2c_stop();
}

void displayOFF(){
    i2c_start();
    i2c_send_addr(ADDRESS<<1);
    i2c_send_byte(COMMANDBYTE);
    i2c_send_byte(DISPLAYOFF);
    i2c_stop(); 
}

static void setPageAddress(uint8_t start, uint8_t end){
    i2c_send_byte(SETPAGEADDRESS);
    i2c_send_byte(start);
    i2c_send_byte(end);
}

static void setColumnAddress(uint8_t start, uint8_t end){
    i2c_send_byte(SETCOLUMNADDRESS);
    i2c_send_byte(start);
    i2c_send_byte(end);
}

//only works in H/V mode, expensive call
void ssd1306_clear(){
    i2c_start();
    i2c_send_addr(ADDRESS<<1);
    i2c_send_byte(DATABYTE);
    for(uint16_t i = 0; i < 1024; i++){
        i2c_send_byte(0x00);
    }
    i2c_stop();
}

//initilaztion should be done using a struct
void ssd1306_init(){
    i2c_start();
    i2c_send_addr(ADDRESS<<1);
    i2c_send_byte(COMMANDBYTE);
    //set mux ratio - this effectively sets the height of the display 
    i2c_send_byte(0xA8);    //command
    i2c_send_byte(0x3F);    //value 63 
    //set display offset - this sets the vertical shift by COM from 0d-63d
    i2c_send_byte(0xD3);    //command
    i2c_send_byte(0x00);    //value 0
    //set start line - this tells the display to start at a certain COM location 0d-63d
    i2c_send_byte(0x40);    //command D7-D6 + value D5-D0
    //set segment re-map - this changes the displays left right direction
    i2c_send_byte(0xA1);    //command D7-D1 + value 0xA0 address 0 -> SEG0 | 0xA1 address 0 -> SEG127 
    //set scan direction - ???
    i2c_send_byte(0xC8);    //command + value D3 0xC0 -> COM0 - COM(N-1) | 0xC8 -> COM(N-1) - COM0
    //hardware config - ???
    i2c_send_byte(0xDA);    //command
    i2c_send_byte(0x12);    //value
    //contrast - set the brightness of the display 
    i2c_send_byte(CONTRASTCONTROL);     //command
    i2c_send_byte(0x1F);                //value
    //display all or display ram 
    i2c_send_byte(DISPLAYRAM);   //DISPLAYRAM || ENTIREDISPLAYON 
    //invert | noinvert
    i2c_send_byte(NONINVERSE);    //NONIVERSE || INVERSE
    //set osc frequency - this controllers the internal osc frequency
    i2c_send_byte(0xD5);    //command
    i2c_send_byte(0x80);    //value 
    //enable charge pump - this turns on the charge pump the generate the OLED voltage
    i2c_send_byte(0x8D);    //command
    i2c_send_byte(0x14);    //value (ON)
    //turn display ON
    i2c_send_byte(DISPLAYON);   //DISPLAYON || DISPLAYOFF
    //set display mode 
    i2c_send_byte(ADDRESSINGMODE);      //command
    i2c_send_byte(HORIZONTAL);          //value
    //set page start & end address
    setPageAddress(0,7);
    //set column start & end address
    setColumnAddress(0,127);
    i2c_stop();
}

void ssd1306_print(uint16_t number, uint8_t x, uint8_t y){
    
    uint8_t numcount = 0;
    uint8_t numholder[8];

    while(number > 0){
        numholder[numcount] = number%10;
        number/=10;
        numcount++;
    }
    
    i2c_start();
    i2c_send_addr(ADDRESS<<1);
    i2c_send_byte(COMMANDBYTE);
    setPageAddress(y,y+2);
    setColumnAddress(x, x+(numcount*16)-1);
    i2c_stop();

    i2c_start();
    i2c_send_addr(ADDRESS<<1);
    i2c_send_byte(DATABYTE);
    for (uint8_t i = 0; i < 3; i++){
        for (int8_t j = numcount-1; j >= 0; j--){
            for (uint8_t k = 0; k < 16; k++){
                i2c_send_byte(numArr[numholder[j]][i][k]);
            }
        }
    }
    i2c_stop();
}

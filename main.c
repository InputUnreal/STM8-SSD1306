#include <stdint.h>
#include <stdio.h>
#include "stm8.h"
#include "I2C.h"
#include "SSD1306.h"

void delay(unsigned long count) {
    while (count--)
        nop();
}

int main(void){
    CLK_CKDIVR = 0;     //set the clock to 16MHz
    
    i2c_init();         //initialize the I2C module
    ssd1306_init();     //initialize the SSD1306 module 
    ssd1306_clear();    //clear the display

	while(1) {
        for(uint8_t i = 0; i < 255; i++){
            ssd1306_print(i,0,0);
            ssd1306_print(i,63,0);
            ssd1306_print(i,0,5);
            ssd1306_print(i,63,5);
            delay(80000L);
        }
    }        
}

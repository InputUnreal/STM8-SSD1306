#include "I2C.h"

void i2c_init(){

    I2C_CR1 = 0; //make sure the i2c peripheral is disabled 
    
    I2C_FREQR = 16; //set the I2C clock to 16MHz
    I2C_CCRH = 0x00; //clcok control register high 
    I2C_CCRL = 0x50; //clock control register low
    I2C_OARH &= ~(1<<7); //7 bit address
    I2C_OARH = (1<<6); //ADDCONF must always be on pg308
    I2C_TRISER = 17; //calculated rise times pg318
    
    I2C_CR1 = 1; //renable the i2c peripheral
}

void i2c_start(){
    I2C_CR2 |= (1<<0);
    while(!(I2C_SR1 & (1<<0))){ //continue after the start condition has benn generated
        nop();
    }
}

void i2c_send_addr(uint8_t addr){
    I2C_DR = addr;
    while(!(I2C_SR1 & (1<<1))){ //continue after ACK has been received
        nop();
    }
    (void) I2C_SR3;   
}

void i2c_send_byte(uint8_t byte){
    I2C_DR = byte;
    while(!(I2C_SR1 & (1<<7))){ //continue after data has ben sent
        nop();
    }
}

void i2c_stop(){
    I2C_CR2 |= (1<<1);
    while((I2C_SR3 & (1<<0))){ //continue after the peripheral has entered slave mode pg296
        nop();
    }
}
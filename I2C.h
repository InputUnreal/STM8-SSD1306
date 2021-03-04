#include <stdint.h>
#include "stm8.h"

#ifndef _I2C_H
#define _I2C_H

void i2c_init();

void i2c_start();

void i2c_send_addr(uint8_t addr);

void i2c_send_byte(uint8_t byte);

void i2c_stop();

#endif
#include <Wire.h>

uint8_t i2c_read_register(uint8_t i2c_address, uint8_t i2c_reg) {
  Wire.beginTransmission(i2c_address);
  Wire.write(i2c_reg);
  Wire.endTransmission();
  Wire.requestFrom(i2c_address, (uint8_t)1);
  uint8_t tmp = Wire.read();
  return tmp;
}

void i2c_read_buffer(uint8_t i2c_address, uint8_t i2c_reg, uint8_t *buf, uint8_t len) {
  Wire.beginTransmission(i2c_address);
  Wire.write(i2c_reg);
  Wire.endTransmission();
  Wire.requestFrom(i2c_address, len);
  uint8_t i = 0;
  while (Wire.available()) { 
    buf[i] = Wire.read(); // Receive a byte as a character
    i++;
  }
}

void i2c_write_register(byte i2c_address, uint8_t i2c_reg, uint8_t i2c_value) {
  Wire.beginTransmission(i2c_address);
  Wire.write(i2c_reg);
  Wire.write(i2c_value);
  Wire.endTransmission();
}

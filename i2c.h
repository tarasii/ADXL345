uint8_t i2c_read_register(uint8_t i2c_address, uint8_t i2c_reg);
void i2c_read_buffer(uint8_t i2c_address, uint8_t i2c_reg, uint8_t *buf, uint8_t len);
void i2c_write_register(byte i2c_address, uint8_t i2c_reg, uint8_t i2c_value);

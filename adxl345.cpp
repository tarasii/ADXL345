#include "Arduino.h"
#include "i2c.h"
#include "adxl345.h"

uint8_t adxl345_address;
uint8_t no_device = 1;

void adxl345_set_base_address(uint8_t address)
{
  adxl345_address = address;
}

uint8_t adxl345_read_register(uint8_t adxl345_reg) 
{
  uint8_t tmp = i2c_read_register(adxl345_address, adxl345_reg);
  return tmp;
}

void adxl345_read_buffer(uint8_t adxl345_reg, uint8_t *buf, uint8_t len) 
{
  i2c_read_buffer(adxl345_address, adxl345_reg, buf, len);
}

void adxl345_write_register(uint8_t adxl345_reg, uint8_t adxl345_value) 
{
  i2c_write_register(adxl345_address, adxl345_reg, adxl345_value);
}

uint8_t adxl345_read_device_id()
{
  uint8_t value = adxl345_read_register(ADXL345_REG_ID); 
  return value;
}

uint8_t adxl345_test()
{
  uint8_t value = adxl345_read_device_id(); 
  if (value == ADXL345_DEVICE_ID) return 1;
  return 0;
}

void adxl345_get_data(adxl345_data_t *value)
{
  adxl345_read_buffer(ADXL345_REG_DATAX0, (uint8_t *) value, 6); 
}

uint16_t adxl345_get_data_x()
{
  uint16_t value = 0;
  adxl345_read_buffer(ADXL345_REG_DATAX0, (uint8_t *) &value, 2); 
  return value;
}

uint16_t adxl345_get_data_y()
{
  uint16_t value = 0;
  adxl345_read_buffer(ADXL345_REG_DATAY0, (uint8_t *) &value, 2); 
  return value;
}

uint16_t adxl345_get_data_z()
{
  uint16_t value = 0;
  adxl345_read_buffer(ADXL345_REG_DATAZ0, (uint8_t *) &value, 2); 
  return value;
}


uint8_t adxl345_read_and_clear_interupts()
{
  uint8_t value = 0;
  value = adxl345_read_register(ADXL345_REG_INT_SOURCE); 
  return value;
}

void adxl345_measure_mode()
{
  if (no_device) return;
  adxl345_write_register(ADXL345_REG_POWER_CTL, ADXL345_MEASURE);
}

uint8_t adxl345_init(uint8_t address)
{
  adxl345_set_base_address(address);
  if (adxl345_test() == 0) return 0;
  no_device = 0;
  adxl345_write_register(ADXL345_REG_DATA_FORMAT, ADXL345_FULL_RES + ADXL345_RANGE_16G); // FULL_RES = 1, range = 11 (±16g)0x0B 
  adxl345_measure_mode();

  return 1;
}

void adxl345_disable_interrupts()
{
  if (no_device) return;
  adxl345_write_register(ADXL345_REG_INT_ENABLE, 0); 
}

void adxl345_set_interrupts(adxl345_int_conf_t* int_conf)
{
  if (no_device) return;
  adxl345_write_register(ADXL345_REG_THRESH_ACT,    int_conf->act_trehold  );
  adxl345_write_register(ADXL345_REG_THRESH_INACT,  int_conf->inact_trehold);
  adxl345_write_register(ADXL345_REG_THRESH_TAP,    int_conf->tap_trehold  );
  adxl345_write_register(ADXL345_REG_THRESH_FF,     int_conf->ff_trehold   ); 
  adxl345_write_register(ADXL345_REG_DUR,           int_conf->duration     );
  adxl345_write_register(ADXL345_REG_LATENT,        int_conf->latency      );
  adxl345_write_register(ADXL345_REG_WINDOW,        int_conf->window       );
  adxl345_write_register(ADXL345_REG_TIME_INACT,    int_conf->inact_time   );
  adxl345_write_register(ADXL345_REG_TIME_FF,       int_conf->ff_time      ); 
  adxl345_write_register(ADXL345_REG_ACT_INACT_CTL, int_conf->int_sources  ); 
  adxl345_write_register(ADXL345_REG_INT_ENABLE,    int_conf->int_enable   ); 
  adxl345_write_register(ADXL345_REG_INT_MAP,       int_conf->int_map      ); 
  adxl345_write_register(ADXL345_REG_TAP_AXES,      int_conf->tap_axes     ); 
  adxl345_read_and_clear_interupts();
}

void adxl345_set_action_interrupt(uint8_t trehold, uint8_t sources)
{
  adxl345_int_conf_t int_conf;
  int_conf.act_trehold = trehold;
  int_conf.int_sources = sources;
  int_conf.int_enable  = ADXL345_ACTIVITY;
  int_conf.int_map     = 0;
  adxl345_set_interrupts(&int_conf);

  adxl345_read_and_clear_interupts();
}

void adxl345_set_inaction_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources)
{
  adxl345_int_conf_t int_conf;
  int_conf.inact_trehold = trehold;
  int_conf.int_sources   = sources;
  int_conf.inact_time    = duration;
  int_conf.int_enable    = ADXL345_INACTIVITY;
  int_conf.int_map       = 0;
  adxl345_set_interrupts(&int_conf);

  adxl345_read_and_clear_interupts();
}

void adxl345_set_tap_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources)
{
  adxl345_int_conf_t int_conf;
  int_conf.tap_trehold = trehold;
  int_conf.tap_axes    = sources;
  int_conf.duration    = duration;
  int_conf.int_enable  = ADXL345_SINGLE_TAP;
  int_conf.int_map     = 0;
  adxl345_set_interrupts(&int_conf);

  adxl345_read_and_clear_interupts();
}

void adxl345_set_free_fall_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources)
{
  adxl345_int_conf_t int_conf;
  int_conf.ff_trehold = trehold;
  int_conf.ff_time    = duration;
  int_conf.int_enable = ADXL345_FREEFALL;
  int_conf.int_map    = 0;
  adxl345_set_interrupts(&int_conf);

  adxl345_read_and_clear_interupts();
}

void print_register_value(uint8_t reg)
{
  byte tmp = 0;
  tmp = adxl345_read_register(reg);
  Serial.print("0x");
  Serial.print(reg, HEX);
  Serial.print(":0x");
  Serial.print(tmp, HEX);
  Serial.println("");
}

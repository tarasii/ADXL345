# ADXL345

Small ADXL345 lib with interrupts for arduino.

Includes examples of interrupt configuration for excess axeleration. 


## Get data functions: 

void adxl345_get_data(adxl345_data_t *value);

returns all axes to adxl345_data_t structure;


typedef struct {

  int16_t x;

  int16_t y;

  int16_t z;

} adxl345_data_t;


uint16_t adxl345_get_data_x();

uint16_t adxl345_get_data_y();

uint16_t adxl345_get_data_z();

returns value of specified axes;


## Interrupt initialization functions 

void adxl345_set_interrupts(adxl345_int_conf_t* int_conf);

main universal interrupt configuration function;

examples of different interrupts configuration:

void adxl345_set_action_interrupt(uint8_t trehold, uint8_t sources);

excess axeleration interrupt configuration function;


void adxl345_set_tap_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);

tap interrupt configuration function;


void adxl345_set_free_fall_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);

free fall interrupt configuration function;


void adxl345_set_inaction_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);

inaction interrupt configuration function;


void adxl345_disable_interrupts();

disables all interrupts;

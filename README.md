# ADXL345

Small ADXL345 lib with interrupts for arduino.

Includes examples of interrupt configuration for excess axeleration. 


## Get data functions: 
```c
typedef struct {
  int16_t x;
  int16_t y;
  int16_t z;
} adxl345_data_t;
```
All axes value structure

```c
void adxl345_get_data(adxl345_data_t *value);
```
returns all axes to adxl345_data_t structure;


```c
uint16_t adxl345_get_data_x();
uint16_t adxl345_get_data_y();
uint16_t adxl345_get_data_z();
```
returns value of specified axes;


## Interrupt initialization functions 
```c
typedef struct {
  int8_t int_enable;
  int8_t int_map;
  int8_t int_sources;
  int8_t tap_axes;
  int8_t act_trehold;
  int8_t inact_trehold;
  int8_t tap_trehold;
  int8_t ff_trehold;
  int8_t latency;
  int8_t window;
  int8_t duration;
  int8_t inact_time;
  int8_t ff_time;
} adxl345_int_conf_t;
```
Interrupt configuration structure

```c
void adxl345_set_interrupts(adxl345_int_conf_t* int_conf);
```
main universal interrupt configuration function;

examples of different interrupts configuration:
```c
void adxl345_set_action_interrupt(uint8_t trehold, uint8_t sources);
```
excess axeleration interrupt configuration function;

```c
void adxl345_set_tap_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);
```
tap interrupt configuration function;

```c
void adxl345_set_free_fall_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);
```
free fall interrupt configuration function;

```c
void adxl345_set_inaction_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);
```
inaction interrupt configuration function;

```c
void adxl345_disable_interrupts();
```
disables all interrupts;

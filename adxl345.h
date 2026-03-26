#ifndef ADXL345_h
#define ADXL345_h


// I2C Address
#define ADXL345_STD     0x1D    // Standard address if SDO/ALT ADDRESS is HIGH.
#define ADXL345_ALT     0x53    // Alternate address if SDO/ALT ADDRESS is LOW.


#define ADXL345_REG_ID             0x00
#define ADXL345_REG_THRESH_TAP     0x1D
#define ADXL345_REG_OFSX           0x1E
#define ADXL345_REG_OFSY           0x1F
#define ADXL345_REG_OFSZ           0x20
#define ADXL345_REG_DUR            0x21
#define ADXL345_REG_LATENT         0x22
#define ADXL345_REG_WINDOW         0x23
#define ADXL345_REG_THRESH_ACT     0x24
#define ADXL345_REG_THRESH_INACT   0x25
#define ADXL345_REG_TIME_INACT     0x26
#define ADXL345_REG_ACT_INACT_CTL  0x27
#define ADXL345_REG_THRESH_FF      0x28
#define ADXL345_REG_TIME_FF        0x29
#define ADXL345_REG_TAP_AXES       0x2A
#define ADXL345_REG_ACT_TAP_STATUS 0x2B
#define ADXL345_REG_BW_RATE        0x2C
#define ADXL345_REG_POWER_CTL      0x2D
#define ADXL345_REG_INT_ENABLE     0x2E
#define ADXL345_REG_INT_MAP        0x2F
#define ADXL345_REG_INT_SOURCE     0x30
#define ADXL345_REG_DATA_FORMAT    0x31
#define ADXL345_REG_DATAX0         0x32
#define ADXL345_REG_DATAX1         0x33
#define ADXL345_REG_DATAY0         0x34
#define ADXL345_REG_DATAY1         0x35
#define ADXL345_REG_DATAZ0         0x36
#define ADXL345_REG_DATAZ1         0x37
#define ADXL345_REG_FIFO_CTL       0x38
#define ADXL345_REG_FIFO_STATUS    0x39

#define ADXL345_DEVICE_ID      0xE5

#define ADXL345_THRESH_16G     0xFF
#define ADXL345_THRESH_8G      0x7F
#define ADXL345_THRESH_4G      0x3F
#define ADXL345_THRESH_2G      0x1F
#define ADXL345_THRESH_1G      0x0F

//0x2C BE RATE
#define ADXL345_LOW_POWER      0x10 
// Data Rate
#define ADXL345_RATE_3200HZ    0x0F    // 3200 Hz
#define ADXL345_RATE_1600HZ    0x0E    // 1600 Hz
#define ADXL345_RATE_800HZ     0x0D    // 800 Hz
#define ADXL345_RATE_400HZ     0x0C    // 400 Hz
#define ADXL345_RATE_200HZ     0x0B    // 200 Hz
#define ADXL345_RATE_100HZ     0x0A    // 100 Hz
#define ADXL345_RATE_50HZ      0x09    // 50 Hz
#define ADXL345_RATE_25HZ      0x08    // 25 Hz
#define ADXL345_RATE_12_5HZ    0x07    // 12.5 Hz
#define ADXL345_RATE_6_25HZ    0x06    // 6.25 Hz
#define ADXL345_RATE_3_13HZ    0x05    // 3.13 Hz
#define ADXL345_RATE_1_56HZ    0x04    // 1.56 Hz
#define ADXL345_RATE_0_78HZ    0x03    // 0.78 Hz
#define ADXL345_RATE_0_39HZ    0x02    // 0.39 Hz
#define ADXL345_RATE_0_20HZ    0x01    // 0.20 Hz
#define ADXL345_RATE_0_10HZ    0x00    // 0.10 Hz

//0x27 ACT INAC_CTL
//0x2B ACT TAP STATUS
#define ADXL345_ACT_XYZ        0x70 
#define ADXL345_ACT_X          0x40 
#define ADXL345_ACT_Y          0x20 
#define ADXL345_ACT_Z          0x10 

//0x27 ACT INAC_CTL
#define ADXL345_ACT_AC         0x80
#define ADXL345_INACT_DC       0x08
#define ADXL345_INACT_XYZ      0x07   
#define ADXL345_INACT_X        0x04 
#define ADXL345_INACT_Y        0x02 
#define ADXL345_INACT_Z        0x01 

//0x2A ACT TAP AXES
//0x2B ACT TAP STATUS
#define ADXL345_TAP_XYZ        0x07 
#define ADXL345_TAP_X          0x04 
#define ADXL345_TAP_Y          0x02 
#define ADXL345_TAP_Z          0x01 

//0x2B ACT TAP STATUS
#define ADXL345_ASLEEP         0x08 

//0x2A ACT TAP AXES
#define ADXL345_SUPRESS        0x08 

//0x31 DATA FORMAT
#define ADXL345_SELF_TEST      0x80  
#define ADXL345_SPI            0x40  
#define ADXL345_INT_INVERT     0x20 
#define ADXL345_FULL_RES       0x08
#define ADXL345_JUSTIFY        0x04 
// Range
#define ADXL345_RANGE_16G      0x03    // +-16 g
#define ADXL345_RANGE_8G       0x02    // +-8 g
#define ADXL345_RANGE_4G       0x01    // +-4 g
#define ADXL345_RANGE_2G       0x00    // +-2 g

//0x2D POWER CTL
#define ADXL345_LINK           0x20
#define ADXL345_AUTO_SLEEP     0x10   
#define ADXL345_MEASURE        0x08 
#define ADXL345_SLEEP          0x04 
#define ADXL345_WAKEUP_1HZ     0x03 
#define ADXL345_WAKEUP_2HZ     0x02 
#define ADXL345_WAKEUP_4HZ     0x01 
#define ADXL345_WAKEUP_8HZ     0x00 

//0x2E INT ENABLE
//0x2F INT MAP
#define ADXL345_DATA_READY     0x80
#define ADXL345_SINGLE_TAP     0x40
#define ADXL345_DOUBLE_TAP     0x20
#define ADXL345_ACTIVITY       0x10   
#define ADXL345_INACTIVITY     0x08 
#define ADXL345_FREEFALL       0x04 
#define ADXL345_WALEMARK       0x02 
#define ADXL345_OWERRUN        0x01 

//0x38
#define ADXL345_FIFO_MODE_BYPASS  0x00 
#define ADXL345_FIFO_MODE         0x40 
#define ADXL345_FIFO_MODE_STREAM  0x80 
#define ADXL345_FIFO_MODE_TRIGGER 0xC0 
#define ADXL345_FIFO_TRIGGER      0x20 

//0x39
#define ADXL345_FIFO_TRIG         0x80

typedef struct {
  int16_t x;
  int16_t y;
  int16_t z;
} adxl345_data_t;
    
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

// I2C functions
uint8_t adxl345_read_register(uint8_t adxl345_reg);
void adxl345_write_register(uint8_t adxl345_reg, uint8_t adxl345_value);

void adxl345_set_base_address(byte address);
uint8_t adxl345_read_device_id();
uint8_t adxl345_test();
uint8_t adxl345_init(uint8_t address);
void adxl345_measure_mode();
// Data funtions
void adxl345_get_data(adxl345_data_t *value);
uint16_t adxl345_get_data_x();
uint16_t adxl345_get_data_y();
uint16_t adxl345_get_data_z();
// Interrapt functions
void adxl345_set_action_interrupt(uint8_t trehold, uint8_t sources);
void adxl345_disable_interrupts();
void adxl345_set_interrupts(adxl345_int_conf_t* int_conf);
void adxl345_set_tap_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);
void adxl345_set_free_fall_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);
void adxl345_set_inaction_interrupt(uint8_t trehold, uint8_t duration, uint8_t sources);
uint8_t adxl345_read_and_clear_interupts();
void print_register_value(uint8_t reg);

#endif

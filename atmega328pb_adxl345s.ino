#include <Wire.h>
#include "adxl345.h"

const int ledPin = 14;  // the number of the LED pin
int ledState = LOW;  // ledState used to set the LED
unsigned long previousMillis = 0;  // will store last time LED was updated
long interval = 500; 

uint8_t int_reset = 0;
uint8_t trig = 0;

#define F_CPU 4000000UL 
#define adxl345_int_pin 3

adxl345_data_t adxl_data;

void land()
{
  int_reset = 1;
}

void setup() {
  Wire.begin();
 
  pinMode(ledPin, OUTPUT);
  pinMode(adxl345_int_pin, INPUT);
  Serial.begin(9600);
  Serial.println("Hello");

  adxl345_init(ADXL345_STD);
  adxl345_set_action_interrupt(0xC0, ADXL345_ACT_AC + ADXL345_ACT_XYZ);

  attachInterrupt(digitalPinToInterrupt(adxl345_int_pin), land, RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (int_reset) 
  {
    int_reset = 0;
    if (trig == 0) trig = 1;
    interval = 100;
    adxl345_read_and_clear_interupts();
    Serial.println("land");    
  }
  

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (trig > 5) 
    {
      trig = 0;
      interval = 500;
    }
    if (trig) trig++;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);

    if (1==0)
    {
      adxl345_get_data(&adxl_data);
      Serial.print("X: "); Serial.print(adxl_data.x);
      Serial.print(" Y: "); Serial.print(adxl_data.y);
      Serial.print(" Z: "); Serial.println(adxl_data.z);

    }
  
  }

}

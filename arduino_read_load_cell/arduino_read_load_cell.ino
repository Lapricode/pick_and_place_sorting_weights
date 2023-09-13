#include <stdio.h>
#include <stdlib.h>
#include <HX711_ADC.h>  // library for the HX711 ADC amplifier

// define the pins for HX711 module
const unsigned int data_pin = 4;  // the Data line pin
const unsigned int clock_pin = 5;  // the Clock line pin

// create an HX711 object (an instance of the HX711_ADC class)
HX711_ADC load_cell(data_pin, clock_pin);  // the constructor
const float calibration_factor = 782.5;  // the calibration factor

void setup() {
  // establish the serial communication between the PC and the arduino board
  Serial.begin(115200);  
  // initialize the HX711 load cell amplifier
  load_cell.begin();  // set pins, HX711 default gain and power up the HX711
  load_cell.setCalFactor(calibration_factor);  // adjust the calibration value
  load_cell.tare();  // tare the load cell, zero the scale
}

void loop() {
  load_cell.update();  // read out 24 bits data and add to dataset of samples
  float sensor_reading = load_cell.getData();  // return the filtered data
  Serial.println(sensor_reading);  // send to the PC the measurement in grams
  delay(20);  // make a time delay of 20 msec
}

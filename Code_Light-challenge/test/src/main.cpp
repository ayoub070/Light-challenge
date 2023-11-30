#include <Arduino.h>

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 1


// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 0   // dont change this
#define CLOCK_PIN 13  // dont change this

const byte PIR_led  = 1; 





// Define the array of leds
CRGB leds[NUM_LEDS];
// Define the the function for viberation interrupt

void setup() {
    
    Serial.begin(9600);
  
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(54);  // setup the brightness of the leds

   delay(10000);
}

void loop() {
 //=================== This is code for Testing the RGB LED==============//
  
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Green;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Orange;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Yellow;
  FastLED.show();
  delay(1000);
}




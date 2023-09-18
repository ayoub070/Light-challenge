#include <Arduino.h>

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 16

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3
#define CLOCK_PIN 13


// Define the array of leds
CRGB leds[NUM_LEDS];


void setup() {
   // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(100);  // setup the brightness of the leds
}

void loop() {
 // Turn the LED on, then pause
  leds[0] = CRGB::Blue;
  leds[1] = CRGB::Blue;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Red;
  leds[4] = CRGB::DarkRed;
  leds[5] = CRGB::OrangeRed;
  leds[6] = CRGB::LightGoldenrodYellow;
  leds[7] = CRGB::AntiqueWhite;
  leds[8] = CRGB::Green;
  leds[9] = CRGB::Yellow;
  leds[10] = CRGB::Yellow;
  leds[11] = CRGB::Yellow;
  leds[12] = CRGB::MediumPurple;
  leds[13] = CRGB::Purple;
  leds[14] = CRGB::PowderBlue;
  leds[15] = CRGB::HotPink;
  FastLED.show();
  //delay(500);
  
  // Now turn the LED off, then pause
 // leds[0] = CRGB::Black;
  //FastLED.show();
 // delay(500);
}




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
const byte PIR_sens = 4;
const byte PIR_led  = 5;

volatile byte state   = LOW;




// Define the array of leds
CRGB leds[NUM_LEDS];

void pir_sens_L(); // declare the interrupt function

void setup() {
    
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);   //initialize Safety light as output
    attachInterrupt(digitalPinToInterrupt(PIR_sens),pir_sens_L,RISING);
   // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(50);  // setup the brightness of the leds

   
}

void loop() {
 // Turn the LED on, then pause
  //leds[0] = CRGB::Blue;
 // leds[1] = CRGB::Blue;
 // leds[2] = CRGB::Blue;
  /*leds[3] = CRGB::Red;
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
  FastLED.show();*/
  //delay(500);
leds[0] = CRGB::Black;
leds[1] = CRGB::Black;
leds[2] = CRGB::Black;
FastLED.show();
  
  // Now turn the LED off, then pause
 // leds[0] = CRGB::Black;
  //FastLED.show();
 // delay(500);
//===============Code for the PIR sesnor================//


}

void pir_sens_L(){
    //if (state==HIGH){
        // leds[0] = CRGB::Blue;
        // leds[1] = CRGB::Blue;
       //  leds[2] = CRGB::Blue;
       digitalWrite(LED_BUILTIN,HIGH);
       //  FastLED.show();
        delay(500);
        Serial.println("aan");
   // }
    
}



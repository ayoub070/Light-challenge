#include <Arduino.h>

#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 16


// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 0
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
 //=================== This is code for the  guidance light==============//
  /*
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
  */
  //======================================================================//
if (state==HIGH){
    //digitalWrite(LED_BUILTIN,HIGH);
    leds[0] = CRGB::Blue;
    leds[1] = CRGB::Blue;
    leds[2] = CRGB::Blue;
    leds[3] = CRGB::Blue;
    leds[4] = CRGB::Blue;
    leds[5] = CRGB::Blue;
    leds[6] = CRGB::Blue;
    leds[7] = CRGB::Blue;
    leds[8] = CRGB::Blue;
    leds[9] = CRGB::Blue;
    leds[10] = CRGB::Blue;
    leds[11] = CRGB::Blue;
    leds[12] = CRGB::Blue;
    leds[13] = CRGB::Blue;
    leds[14] = CRGB::Blue;
    leds[15] = CRGB::Blue;
    FastLED.show();
    delay(5000);
    state=LOW;
    //digitalWrite(LED_BUILTIN,LOW);
     leds[0] = CRGB::Black;
     leds[1] = CRGB::Black;
     leds[2] = CRGB::Black;
     leds[3] = CRGB::Black;
     leds[4] = CRGB::Black;
     leds[5] = CRGB::Black;
     leds[6] = CRGB::Black;
     leds[7] = CRGB::Black;
     leds[8] = CRGB::Black;
     leds[9] = CRGB::Black;
     leds[10] = CRGB::Black;
     leds[11] = CRGB::Black;
     leds[12] = CRGB::Black;
     leds[13] = CRGB::Black;
     leds[14] = CRGB::Black;
     leds[15] = CRGB::Black;
     FastLED.show();
    delay(0);
    Serial.println("uit");
  }else{
    state=LOW;
  
  }
 
//=============== Interrupt code for the PIR sesnor================//


}

void pir_sens_L(){
    
       state = HIGH;
   
    
}



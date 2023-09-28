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
const byte PIR_sens1 = 4;
const byte PIR_sens2 = 8;
const byte PIR_led  = 5;
const byte Vibration_sens = 7;

volatile byte state   = LOW;




// Define the array of leds
CRGB leds[NUM_LEDS];
// Define the the function for viberation interrupt
void VIB_sens();

void setup() {
    
    Serial.begin(9600);
    pinMode(PIR_sens1,INPUT);
    pinMode(PIR_sens2,INPUT);
    //attachInterrupt(digitalPinToInterrupt(PIR_sens),pir_sens_L,RISING);
    attachInterrupt(digitalPinToInterrupt(Vibration_sens),VIB_sens,FALLING);
   // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(254);  // setup the brightness of the leds

   delay(10000);
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

  if(state==HIGH){  // Als er trilling of vibratie gedecteerd wordt zal er een delay van 5 sec. plaats vinden.
    delay(5000);
    state=LOW;
  }
  else if (digitalRead(PIR_sens2)==HIGH){  // Als PIR sens 2  een object detecteerd zal  de 2e helft van de LED strip aan gaan voor 5 sec.
    
    leds[8] = CRGB::Red;
    leds[9] = CRGB::Red;
    leds[10] = CRGB::Red;
    leds[11] = CRGB::Red;
    leds[12] = CRGB::Red;
    leds[13] = CRGB::Red;
    leds[14] = CRGB::Red;
    leds[15] = CRGB::Red;
    FastLED.show();
    delay(5000);
    state=LOW;
    
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
  }
  else if (digitalRead(PIR_sens1)==HIGH){ // Als PIR sens 1  een object detecteerd zal  de 1e helft van de LED strip aan gaan voor 5 sec.
    
    leds[0] = CRGB::Red;
    leds[1] = CRGB::Red;
    leds[1] = CRGB::Red;
    leds[2] = CRGB::Red;
    leds[3] = CRGB::Red;
    leds[4] = CRGB::Red;
    leds[5] = CRGB::Red;
    leds[6] = CRGB::Red;
    leds[7] = CRGB::Red;
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
     FastLED.show();
    delay(0);
  
  
  }
 Serial.println(digitalRead(PIR_sens1));
//=============== Interrupt code for the Vibration sesnor================//


}


void VIB_sens(){  // Interrupt voor het uit doen van alle RGB LEDs, wanneer er een trilling of vibrartie plaat vindt. 
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
   state=HIGH;
    
}

/*

   This example listens for LoRa transmissions using SX1262 Lora modules.
   To successfully receive data, the following settings have to be the same
   on both transmitter and receiver:
    - carrier frequency
    - bandwidth
    - spreading factor
    - coding rate
    - sync word
    - preamble length
*/

// include the library
#include <RadioLib.h>

// Waveshare SX1262 has the following connections:
// NSS pin:   3
// DIO1 pin:  20
// NRST pin:  15
// BUSY pin:  2
SX1262 radio = new Module(3, 20, 15, 2, SPI1, RADIOLIB_DEFAULT_SPI_SETTINGS);




void setup() {
  //SPI1 bus setup
  SPI1.setSCK(10); //SPI1 bus clock
  SPI1.setTX(11);  //SPI1 bus MOSI
  SPI1.setRX(12);  //SPI1 bus MISO
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  SPI1.begin(false);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  // "Initializing" and "Found" messages not showing without waiting for serial connection
  while (!Serial)
  {
    ; // Wait for serial to connect
  }

  Serial.println("Start");
  
  Serial.print(F("[SX1262] Initializing ... "));
  // carrier frequency:           868.0 MHz
  // bandwidth:                   500.0 kHz
  // spreading factor:            6
  // coding rate:                 5
  // sync word:                   0x34 (public network/LoRaWAN)
  // output power:                22 dBm
  // preamble length:             20 symbols
  int state = radio.begin(868.0, 500.0, 6, 5, 0x34, 22, 20);
  //int state = radio.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
}

void loop() {
  //Serial.print(F("Waiting on data request\n"));
  String str;
  String ack = "false";
  int count; 
  int state = radio.receive(str);


  if (state == RADIOLIB_ERR_NONE) {
    // packet was successfully received

    Serial.println(F("success!"));

    // print the data of the packet
    Serial.print(F("[SX1262] Data:\t\t"));
    Serial.println(str);

    Serial.print(F("[SX1262] Transmitting packet ... "));
    
    //message builder based on the recieved string
    // you can transmit C-string or Arduino string up to
    // 256 characters long
    String str = "Hello World! #" + String(count++);


    do //loop to verify transmission was succesfull
    {
      for (int i = 0; i <= 5; i++) {

        int state = radio.transmit(str);

        if (state == RADIOLIB_ERR_NONE) {
        // the packet was successfully transmitted
        Serial.println(F("Transmit success!"));
        } else {
        // some other error occurred
        Serial.print(F("failed, code "));
        Serial.println(state);
        }

        Serial.println(F("Waiting for ack"));
        for (int a = 0; a <= 10; a++) {
         //Acknowledge 
          int state = radio.receive(ack);
          if (state == RADIOLIB_ERR_NONE) {
            // print the data of the packet
            Serial.print(F("Acknowledge =\t\t"));
            Serial.println(ack);
            a = 20; //stopping loop
            i = 20; //stopping loop
          } else {
            // some other error occurred
            if(state != -6){
            Serial.print(F("failed, code "));
            Serial.println(state);
            }
          }
        }

      }
      ack = "fail";
    }while(ack == "false" );
    Serial.println(ack);

  } else {
    // some other error occurred
    if(state != -6){
    Serial.print(F("failed, code "));
    Serial.println(state);
    }
  }
}
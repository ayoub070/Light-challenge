#define TXU1       8   
#define RXU1       9 
int BERICHT=LOW;


#include <string.h>

void setup() {

    pinMode(LED_BUILTIN, OUTPUT);
    Serial2.setTX(8);
    Serial2.setRX(9);

    Serial.begin(9600);      
    Serial2.begin(9600);

    attachInterrupt(digitalPinToInterrupt(RXU1), msg, FALLING);  
    
}

void msg(){
  BERICHT = HIGH;
}


/*
  //checks if msg is for this pico
  if(rec.startsWith("1"))
  {
        Serial.println("Msg is for me");
        //compares what characters after id are
        if (rec.substring(1 , 5) == "Hallo")
        {
            Serial.println("Msg is Hallo");
        }
  }
*/

void loop() {

  if(BERICHT == HIGH){
    digitalWrite(LED_BUILTIN, HIGH);
    
    //read the incomming msg
    String rec = Serial2.readString();
    Serial.println(rec);
    Serial2.println("dit is pico 2");
    //211:12-10-09-2003check 17-21
    //checks if msg is for this pico
    if(rec.startsWith("2")) //change number for number of pico
    {
      Serial.println("Msg is for me");
      Serial2.println("Hoi");  
      //this is where we add functions    
      String date = rec.substring(1 , 16); 

      if(rec.substring(17, 18) == "0"){ // 17 -> 0 is for default keepalive check 
        Serial2.println("2alive");
        Serial.println("2alive");
      }
      else if(rec.substring(17, 18) == "1"){ //17 -> 1 is for changing the colour of the led.
        String colour = rec.substring(18, 19); //assign number per colour
        //Here code for changing the colour to the new one. 
        Serial2.println("2done");
      }
      else if(rec.substring(17,18 ) == "2"){ //17 -> 2 is for sending data to the master
        Serial.println("2Blablabla dit is de data van pico 2");
        Serial2.println("2Blablabla dit is de data van pico 2");
      }

    }
    BERICHT = LOW;
    digitalWrite(LED_BUILTIN, LOW);
  
  }
 // digitalWrite(LED_BUILTIN, HIGH);
}


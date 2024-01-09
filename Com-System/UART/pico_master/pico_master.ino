#define TXU1       8   
#define RXU1       9 
#include <string.h>
using namespace std;
int BERICHT = LOW;

void setup() {
    
    pinMode(LED_BUILTIN, OUTPUT);
    //UART pins
    Serial2.setTX(8);
    Serial2.setRX(9);
    //Serial begin
    Serial.begin(9600);      
    Serial2.begin(9600);
    //attachInterrupt(digitalPinToInterrupt(RXU1), msg, FALLING);  
    
}
/*
void msg(){ 
  BERICHT = HIGH;
  
}
*/
String recmsg() {
  digitalWrite(LED_BUILTIN, HIGH);
  for(int i = 0; i <= 2; i++){
    String msg = Serial2.readString();
    if (msg != ""){
      return msg;
    }
    else{
      delay(1000);
    }

  }
  Serial.println("no response");
  digitalWrite(LED_BUILTIN, LOW);
   return "";
}


void loop() {
    String function = "data";
    String colour = "";
    String tijd ="11:12-10-09-2003";
    String msg = "";
    String numbers[2] = {"2","1"}; //,"3","4","5","6"}; //extend for number of picos
  
    //transmitting functions
    for(String i : numbers){
      delay(1000);
      if(function == "colour"){ //function colour = 1
        msg = i + tijd + "1" + colour;
        //Serial.println(msg);
        Serial2.println(msg);
        delay (1000);
      }

      else if(function == "data"){ //function colour = 1
        msg = i + tijd + "2";// function for asking for data
        Serial.println(msg);
        Serial2.println(msg);
        auto rec = recmsg();
        Serial.println(rec);

/*
        delay (1000);
        String temp = Serial2.readString();
        delay (1000);
        Serial.println(temp);
*/

      }
      else{ //default  is a check if the pico is still alive
        msg = i + tijd + 0; //normal check = 0
        Serial.println(msg);
        Serial2.println(msg);
        delay (1000);
        String temp = Serial2.readString();
        delay (1000);
        Serial.println(temp);
    }
    } 

} 

/*
if(BERICHT == HIGH){
    String rec = Serial2.readString(); //switch case 
    if(rec.startsWith("1")){
        Serial.println("Msg van pico 1 is" + rec.substring(1 , 100));
    }
    else if(rec.startsWith("2")){
        Serial.println("Msg van pico 2 is" + rec.substring(1 , 100));
    }
    else if(rec.startsWith("3")){
        Serial.println("Msg van pico 3 is" + rec.substring(1 , 100));
    }
    else if(rec.startsWith("4")){
        Serial.println("Msg van pico 4 is" + rec.substring(1 , 100));
    }
  }
  */

/*
    digitalWrite(LED_BUILTIN, HIGH);

    delay (5000);
    Serial2.print("1Hallo");
    

    Serial.print("n");
    Serial2.print("1Hallo");
    String rec = Serial2.readString();
    Serial.println(rec);
*/

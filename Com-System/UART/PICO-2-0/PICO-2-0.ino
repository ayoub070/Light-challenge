void setup() {
  // put your setup code here, to run once:
  Serial1.setRX(17);
  Serial1.setTX(16);
  Serial.begin(9600);
  Serial1.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int data = random(0,500);
  Serial.print("Data:");
  Serial.println(data);
  Serial1.print("Data:");
  Serial1.println(data);
  delay(2500);
}

void setup() {
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  Serial.begin(115200);
}
void loop() {
  //Serial.println(analogRead(A0)>200);
  //digitalWrite(8,analogRead(A0)>800);
  Serial.println(analogRead(A0));
  delay(75);
}

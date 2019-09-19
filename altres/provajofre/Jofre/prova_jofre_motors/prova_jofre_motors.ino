void setup() {
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
}
void loop() {
digitalWrite(5, LOW);
digitalWrite(4, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
//
delay(1000);
digitalWrite(4, HIGH);
delay(1000);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
delay(1000);
//
digitalWrite(5, LOW);
digitalWrite(11, HIGH);
delay(1000);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
delay(1000);
//
digitalWrite(5, HIGH);
delay(1000);
digitalWrite(5, LOW);
digitalWrite(12, LOW);
digitalWrite(4, HIGH);
digitalWrite(11, HIGH);
delay(1000);
//
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
delay(1000);
digitalWrite(5, LOW);
digitalWrite(11, LOW);
digitalWrite(4, HIGH);
digitalWrite(12, HIGH);
delay(1000);
}

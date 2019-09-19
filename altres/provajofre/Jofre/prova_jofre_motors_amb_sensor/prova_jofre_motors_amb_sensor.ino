#include <NewPing.h>
NewPing DistanceSensor(14, 15, 250);
void setup() {
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
Serial.begin(9600);
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
unsigned int Distance = DistanceSensor.ping_cm();
Serial.print("Distància d'objecte més proper ");
Serial.println(Distance);
if (Distance > 20 || Distance == 0){
Serial.println("Pista buida");
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
delay(1000);
}
else{
Serial.println("Obstacle detectat, retrocedint");
}
digitalWrite(5, LOW);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
digitalWrite(4, HIGH);
delay(1000);
}

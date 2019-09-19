#include <NewPing.h>
NewPing DistanceSensor(14,15, 300);
void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
}
void loop() {
  unsigned int ValorDelSensor = DistanceSensor.ping_cm();
  Serial.print("Distancia: ");
  Serial.print(ValorDelSensor);
  Serial.println(" cm");
  if (ValorDelSensor > 19 && ValorDelSensor < 41){
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    unsigned int i = 50;
    while(i != 0){
        unsigned int ValorDelSensor = DistanceSensor.ping_cm();
        Serial.print("Distancia: ");
        Serial.print(ValorDelSensor);
        Serial.println(" cm");
        delay(1);
        i -= 1;
    }
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
}

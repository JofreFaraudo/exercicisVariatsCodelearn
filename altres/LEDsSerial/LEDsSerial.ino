#define numberOfLEDs 3
int LEDsPins[numberOfLEDs] = {9,10,11};
unsigned int interval = 200;
unsigned int turn = 0;
unsigned int power = 255;
String reading;
void setup() {
  Serial.begin(9600);
  for(int LED = 0; LED<=numberOfLEDs; LED++)
    pinMode(LEDsPins[LED],OUTPUT);
}
void loop() {
  if(Serial.available()){
    reading = Serial.readString();
    if(reading == "A"){
      power = 0;
    }else if(reading[0] == 'P'){
      power = reading.substring(1).toInt();
    }else if(reading[0] == 'V'){
      interval = reading.substring(1).toInt()*10;
    }
  }
  for(int LED = 0; LED<=numberOfLEDs; LED++)
    digitalWrite(LEDsPins[LED],LOW);
  analogWrite(LEDsPins[turn%3],power);
  delay(interval);
  turn++;
}

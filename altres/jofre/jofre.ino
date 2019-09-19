#define LDR A0
#define POT A1
#define INT 12
#define LED1 9
#define LED2 10
#define LED3 11
unsigned int current = 1;
int LEDs[] = {LED1,LED2,LED3};
void setup() {
  pinMode(LDR,INPUT);
  pinMode(POT,INPUT);
  pinMode(INT,INPUT_PULLUP);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
}
void loop() {
  if(digitalRead(INT) == 0){
    analogWrite(LED1,analogRead(POT)/4);
    analogWrite(LED2,analogRead(POT)/4);
    analogWrite(LED3,analogRead(POT)/4);
  }else{
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    analogWrite(LEDs[current%3],analogRead(POT)/4);
    current++;
  }
  delay(analogRead(LDR)*2);
}

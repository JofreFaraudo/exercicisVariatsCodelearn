#define I "110"
#define F "111"
#define d 75
const int n = 2;
const String E[n] = {"100","101"};
const int pins[n] = {12,11};
void setup() {
  for(int i=0;i<n;i++){
    pinMode(pins[i],OUTPUT);
  }
}
void loop() {
  startEmeting(random(n));
  delay(d*5);
}
void startEmeting(int e){
  sendData(I,e);
  sendData(E[e],e);
  sendData(createRandomMessage(),e);
  sendData(F,e);
  digitalWrite(pins[e],0);
}
String createRandomMessage(){
  String data = "";
  for(int i=0; i<3; i++)
    data += String(random(2));
  if(data != I && data != F && data != E[1] && data != E[1])
    return data;
  return createRandomMessage();
}
void sendData(String data,int pin){
  int numOfOnes = 0;
  for(int i = 0; i<data.length(); i++){
    if(data[i] == '1')
      numOfOnes++;
    digitalWrite(pins[pin],data[i] - '0');
    delay(d);
  }
  digitalWrite(pins[pin],numOfOnes%2);
  delay(d);
}

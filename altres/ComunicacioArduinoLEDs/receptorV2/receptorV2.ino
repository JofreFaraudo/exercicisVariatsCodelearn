#define d 75
#define v 300
#define I 1100
#define F 1111
#define S1 1001
#define S2 1010
int e = 0;
int readed;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(115200);
}
void loop() {
  while(analogRead(A0)<v);
  readed = readSerial();
  if(readed == I && verify(readed)){
    Serial.println("Transmissio en curs..");
    switch(readSerial()){
      case S1:
        e = 1;
        break;
      case S2:
        e = 2;
        break;
      default:
        e = 0;
        break;
    }
    if(e != 0){
      Serial.print("Rebent missatge de l\'emissor: ");
      Serial.println(e);
      while(true){
        readed = readSerial();
        if(verify(readed)){
          if(readed == F){
            Serial.println("Final del missatge...");
            break;
          }else
            Serial.println("Rebent dada: "+String(readed));
        }
      }
    }
  }
}
int readSerial(){
  String val = "";
  for(int i = 0; i<4;i++){
    val += String(analogRead(A0)>v);
    delay(d);
  }
  return val.toInt();
}
bool verify(int val){
  int s;
  String str = String(val);
  for(int i = 0; i<str.length(); i++){
    s += str[i];
  }
  return s%2 == 1;
}

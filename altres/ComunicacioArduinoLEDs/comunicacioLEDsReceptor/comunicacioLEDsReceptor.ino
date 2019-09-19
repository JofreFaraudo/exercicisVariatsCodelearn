String readed;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
void loop() {
  while(analogRead(A0)<1000);
  readed = "";
  delay(750);
  if(analogRead(A0)<1000){
    delay(500);
    if(analogRead(A0)<1000){
      Serial.println("Rebent transmisio");
      while(readed != "111"){
        readed = "";
        for(int i=0;i<3;i++){
         delay(500);
          readed += analogRead(A0)>1000;
        }
        Serial.println("S\'ha rebut: "+readed);
      }
      Serial.println("Transmisio finalitzada\n");
    }
  }
}

#define M1 2
#define TR1 3
#define T1 4
#define TL1 5
#define RB1 6
#define B1 7
#define LB1 8
#define Dp1 9
#define M2 10
#define TR2 11
#define T2 12
#define TL2 13
#define RB2 14
#define B2 15
#define LB2 16
#define Dp2 17
int nums[10][7] = {
    {B1,T1,TL1,LB1,RB1,TR1},
    {TL1,LB1},
    {T1,M1,B1,TL1,RB1},
    {T1,M1,B1,TL1,LB1},
    {TL1,LB1,TR1,M1},
    {T1,M1,B1,TR1,LB1},
    {B1,T1,TR1,LB1,RB1,M1},
    {TL1,LB1,T1},
    {B1,T1,TL1,LB1,RB1,TR1,M1},
    {B1,T1,TL1,LB1,TR1,M1}
   };
int numsB[10][7] = {
    {B2,T2,TL2,LB2,RB2,TR2},
    {TL2,LB2},
    {T2,M2,B2,TL2,RB2},
    {T2,M2,B2,TL2,LB2},
    {TL2,LB2,TR2,M2},
    {T2,M2,B2,TR2,LB2},
    {B2,T2,TR2,LB2,RB2,M2},
    {TL2,LB2,T2},
    {B2,T2,TL2,LB2,RB2,TR2,M2},
    {B2,T2,TL2,LB2,TR2,M2}
   };
void setup() {
  pinMode(M1,OUTPUT);
  pinMode(TR1,OUTPUT);
  pinMode(T1,OUTPUT);
  pinMode(TL1,OUTPUT);
  pinMode(RB1,OUTPUT);
  pinMode(B1,OUTPUT);
  pinMode(LB1,OUTPUT);
  pinMode(Dp1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(TR2,OUTPUT);
  pinMode(T2,OUTPUT);
  pinMode(TL2,OUTPUT);
  pinMode(RB2,OUTPUT);
  pinMode(B2,OUTPUT);
  pinMode(LB2,OUTPUT);
  pinMode(Dp2,OUTPUT);
}
void loop() {
  allOff(0);
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < sizeof(nums[i])/sizeof(nums[i][8]); j++){
      digitalWrite(nums[i][j],LOW);
    }
    for(int k = 0; k < 10; k++){
      for(int j = 0; j < sizeof(numsB[k])/sizeof(numsB[k][8]); j++){
        digitalWrite(numsB[k][j],LOW);
      }
      delay(1000);
      allOff(2);
    }
    allOff(1);
  }
  digitalWrite(Dp1,LOW);
  digitalWrite(Dp2,LOW);
  delay(1000);
}
void allOff(int t){
  if(t < 2){
  digitalWrite(M1,HIGH);
  digitalWrite(TR1,HIGH);
  digitalWrite(T1,HIGH);
  digitalWrite(TL1,HIGH);
  digitalWrite(RB1,HIGH);
  digitalWrite(B1,HIGH);
  digitalWrite(LB1,HIGH);
  digitalWrite(Dp1,HIGH);
  }
  if(t != 1){
  digitalWrite(M2,HIGH);
  digitalWrite(TR2,HIGH);
  digitalWrite(T2,HIGH);
  digitalWrite(TL2,HIGH);
  digitalWrite(RB2,HIGH);
  digitalWrite(B2,HIGH);
  digitalWrite(LB2,HIGH);
  digitalWrite(Dp2,HIGH);
  }
}

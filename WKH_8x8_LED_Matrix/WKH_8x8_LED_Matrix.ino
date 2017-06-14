
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
byte colDataMatrix[8] = { 
   B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110
  };
                      
byte rowDataMatrix[3][8] = { 
    {B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111},

    {B00000000,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B00000000},

     {B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00000000,
    B00000000},
  };
 
 
// 定義顯示器顯示的時間 (延遲時間), 預設 1ms
int delay_time = 1;
       
void setup() {
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
}
void loop() {
for(int j=0;j<3;j++){
  int a=1;
  unsigned long startTime=millis();
  while(a){
     unsigned long endTime;
       for(int i = 0; i < 8 ; i++){
       //byte colData = colDataMatrix[i];
       endTime=millis();
       digitalWrite(latchPin,LOW);
        //  pickDigit(i);
          shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
          shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[j][i]);
          //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
          digitalWrite(latchPin,HIGH);
          if((endTime-startTime)>1000) {a=0;}
          delay(delay_time);
  }
}
}
}
void pickDigit(int x) {
  byte rowByte = 1 << x;
  shiftOut(dataPin, clockPin, MSBFIRST, rowByte);

}



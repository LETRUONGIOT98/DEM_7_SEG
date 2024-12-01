#include "Wire.h"
#define LATCH 4
#define CLK 3
#define DATA 2

//bilangan HEX Array
byte digit[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F};//tanpa uln2003

int i,j,k,h,m,n,tong;
int cong = A0;
int tru = A1;
int set = A2;
int ok = A3;
int sensor = A3;
int relay = 12;
void setup(){
  pinMode(cong, INPUT_PULLUP);
  pinMode(tru, INPUT_PULLUP);
  pinMode(sensor, INPUT_PULLUP);
  pinMode(set, INPUT_PULLUP);
  pinMode(ok, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
 shiftOut(DATA, CLK, MSBFIRST, ~digit[0]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[0]);  // chục
      shiftOut(DATA, CLK, MSBFIRST, ~digit[0]);   // đơn vị
      digitalWrite(LATCH, HIGH);
}

void loop(){

if(digitalRead(set)==0){
  h = h+1;
  if(h > 3)h=0;
  delay(500);
}
if(h == 1){
  if(digitalRead(cong) == 0){
 i = i+1;
 i =i%10;
 digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[i%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[m/10%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[n/100]); // trăm
      digitalWrite(LATCH, HIGH);
 delay(300);
}
if(digitalRead(tru) == 0){
 i = i-1;
 digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[i%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[m/10%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[n/100]); // trăm
      digitalWrite(LATCH, HIGH);
 delay(300);
}
}

if(h == 2){
  if(digitalRead(cong) == 0){
 m = m+10;
 m= m%100;
 digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[i%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[m/10%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[n/100]); // trăm
      digitalWrite(LATCH, HIGH);
 delay(300);
}
if(digitalRead(tru) == 0){
 m = m-10;
 digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[i%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[m/10%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[n/100]); // trăm
      digitalWrite(LATCH, HIGH);
 delay(300);
}
}

if(h == 3){
  if(digitalRead(cong) == 0){
 n = n+100;
 n = n%1000;
 digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[i%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[m/10%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[n/100]); // trăm
      digitalWrite(LATCH, HIGH);
 delay(300);
}
}

if(h == 3){
  if(digitalRead(cong) == 0){
 n = n-100;
 digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[i%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[m/10%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[n/100]); // trăm
      digitalWrite(LATCH, HIGH);
 delay(300);
}
}
if(digitalRead(ok) == 0){
  tong = n + m + i;
  for(int f =0; f < 5; f++){
    digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[0]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[0]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[0]); // trăm
      digitalWrite(LATCH, HIGH);
      delay(200);
      digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[i%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[m/10%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[n/100]); // trăm
      digitalWrite(LATCH, HIGH);
      delay(200);
  }
  h =0;
}
if(digitalRead(sensor) ==0){
 k = k+1;
 digitalWrite(LATCH, LOW);
      shiftOut(DATA, CLK, MSBFIRST, ~digit[k%10]); // trăm
      shiftOut(DATA, CLK, MSBFIRST, ~digit[k/10%10]);  // chục
      shiftOut(DATA, CLK, MSBFIRST, ~digit[k/100]);   // đơn vị
      digitalWrite(LATCH, HIGH);
 delay(500);
}
if(k == tong){
  digitalWrite(relay, HIGH); 
}
else digitalWrite(relay, LOW);
}

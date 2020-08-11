#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int ledred = 13;
int ledyellow = 12;
int ledgreen =11;
int sensor1 = 10;
int sensor2 = 9;
int sensor3 = 8;
int state1 = LOW;
int state2 = LOW;
int state3 = LOW; 
int val1 = 0; 
int val2 = 0;
int val3 = 0;

void setup() {
pinMode(ledred, OUTPUT);  
pinMode(ledyellow, OUTPUT);
pinMode(ledgreen, OUTPUT);
pinMode(sensor1, INPUT); 
pinMode(sensor2, INPUT); 
pinMode(sensor3, INPUT);
lcd.begin(16,2);
Serial.begin(9600); 
}

void loop(){
val1 = digitalRead(sensor1);
val2 = digitalRead(sensor2);
val3 = digitalRead(sensor3);

if (val1==HIGH){
digitalWrite(ledred,HIGH);
lcd.setCursor(0,0);
lcd.print("S1=mendeteksi ");
delay(100);
if(state1==LOW){
Serial.println("MENDETEKSI GERAKAN SENSOR 1 !");
state1=HIGH;
}
}
else{
digitalWrite(ledred,LOW);
lcd.setCursor(0,0);
lcd.print("S1=DIAM ");
delay(100);

if(state1==HIGH){
Serial.println("TIDAK MENDETEKSI GERAKAN SENSOR 1");
state1=LOW;
}
}
if (val2==HIGH){
digitalWrite(ledyellow,HIGH);
lcd.setCursor(8,0);
lcd.print("S2=mendeteksi");
delay(100);

if(state2==LOW){
Serial.println("MENDETEKSI GERAKAN SENSOR 2 !");
state2=HIGH;
}
}
else{
digitalWrite(ledyellow,LOW);
lcd.setCursor(9,0);
lcd.print("S2=DIAM");
delay(100);

if(state2==HIGH){
Serial.println("TIDAK MENDETEKSI GERAKAN SENSOR 2");
state2=LOW;
}
}
if (val3==HIGH){
digitalWrite(ledgreen,HIGH);
lcd.setCursor(0,1);
lcd.print("S3=mendeteksi ");
delay(100);

if(state3==LOW){
Serial.println("MENDETEKSI GERAKAN SENSOR 3 !");
state3=HIGH;
}
}
else{
digitalWrite(ledgreen,LOW);
lcd.setCursor(0,1);
lcd.print("S3=DIAM");
delay(100);

if(state3==HIGH){
Serial.println("TIDAK MENDETEKSI GERAKAN SENSOR 3");
state3=LOW;
}
}
}

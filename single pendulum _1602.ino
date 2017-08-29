//单摆 1602
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define ul  unsigned long  
const int pin = 8; 
float time[8]={0,0,0,0,0,0,0,0}; 
const ul MAXHT = 30*1000*1000;
unsigned long time_avr;
unsigned long f;
unsigned long T;
unsigned long g;
int n=8;
int t=4;
float M=4*3.14*3.14*0.35;
void setup()  
{   lcd.begin(16, 2);
    lcd.print("Simple pendulum");
    pinMode(pin, INPUT);  
    Serial.begin( 9600 );  
}  
  
void loop()  
{   lcd.setCursor(0, 1);
    lcd.print("t:");
    //Serial.print("\n\n START:\t");
    for(int i=0;i<8;i++)
{
    ul ht = pulseIn(pin,HIGH, MAXHT);  
    time[i]=ht;
}
    float time_avr=(time[1]+time[2]+time[3]+time[4]+time[5]+time[6]+time[7]+time[8]); 
    float f=n/(time_avr/1000000);
    float T=(time_avr/1000000*t);
    float g=M/(T*T);
    lcd.print(T);lcd.print("s");lcd.print(" g:");lcd.print(g);//lcd.print("m/s²");
    Serial.print(T);  Serial.print("s");  Serial.print("\t");
    //Serial.print(f);  Serial.print("n/s ");  Serial.print("\t");
    //Serial.print(T);  Serial.print("s");  Serial.print("\t");
    //Serial.print(g);  Serial.print("m/s²"); 
}  
  


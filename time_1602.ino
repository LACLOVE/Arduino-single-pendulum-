//单摆周期测量仪 LCD1602显示
//利用时间函数计时
//外部中断计数
// made by 卢宁 2018.6.18

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 13, 11, 10, 9, 8);
int pin = 7;
int pin1 = 6;
int val,va2;
int i;
unsigned long t1=0;
unsigned long t2=0;
unsigned long t;
float M=4*3.14*3.14*0.646;//分子4π²L（摆长）
void setup()  
{   
    lcd.begin(16, 2);
    lcd.print("Simple pendulum"); 
    Serial.begin( 9600 ); 
    pinMode(pin, OUTPUT);
    pinMode(pin1, OUTPUT);
    attachInterrupt(0, blink0, RISING);//中断0（引脚2），中断1（引脚3） 
    delay(2000);
    lcd.clear();
}  
  
void loop()  
{   
   float  t=t2-t1;
   float  T=(t/1000)/6;
   float g=M/(T*T);

//   Serial.print("n: ");
//   Serial.println(i);
//   Serial.print("\t");
   val = digitalRead(pin);
   va2 = digitalRead(pin1);

   lcd.setCursor(0, 0);
   lcd.print("n:");
   if(i<10){
    lcd.setCursor(2, 0);
    lcd.print("0");
    lcd.print(i);
   }
   if(i>=10){
    lcd.print(i);
   }
   lcd.setCursor(4, 0);
   lcd.print("   ");
   
  if(val==LOW&&va2==HIGH){
//     Serial.print("t: ");
//     Serial.print(t/1000);
//     Serial.print(" s ");
//     Serial.print(" T: ");
//     Serial.print(T);
//     Serial.print(" s ");
//     Serial.print(" g: ");
//     Serial.print(g);
//     Serial.print("\n");
    
      lcd.setCursor(8, 0);
      lcd.print("t:");
      lcd.print(t/1000);
      
      lcd.setCursor(0, 1); 
      lcd.print("T:");
      lcd.print(T);
      lcd.print("s");
  
      
      lcd.print(" g:");
      lcd.print(g);//lcd.print("m/s²");
   }

} 
 
void blink0()
{  
  i++;
  //Serial.println(i);
  if(i==5){
    t1=millis();
//    Serial.print(t1);
//    Serial.print("\n");
    digitalWrite(pin,1);
    digitalWrite(pin1,0);
  }
  if(i==17){
    t2=millis();
//    Serial.print(t2);
//    Serial.print("\n");
    digitalWrite(pin,0);
    digitalWrite(pin1,1);
    i=0;
  }
} 



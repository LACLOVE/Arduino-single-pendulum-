//单摆 1602
//利用时间函数计时 
//外部中断计数
//加入按键改变摆长
// made by 卢宁 2018.6.18
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 13, 11, 10, 9, 8);
int pin = 7;
int pin1 = 6;
int KEY_add = A1;
int KEY_red = A0;
int key_1 = 0,key_2 = 0,key_3 = 0,key_4 = 0;
float  L = 0.65;
int val,va2;
int i;
unsigned long t1=0;
unsigned long t2=0;
unsigned long t;
//float M=4*3.14*3.14*L;//分子4π²L（摆长）
void setup()  
{   
    lcd.begin(16, 2);
    lcd.print("Simple pendulum"); 
    Serial.begin( 9600 ); 
    pinMode(pin, OUTPUT);
    pinMode(pin1, OUTPUT);
    pinMode(KEY_add, INPUT);
    pinMode(KEY_red, INPUT);
    attachInterrupt(0, blink0, RISING);//中断0（引脚2），中断1（引脚3） 
    delay(2000);
    lcd.clear();
}  
  
void loop()  
{   
   scan();
   float M=4*3.14*3.14*L;
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
      lcd.print("L:");
      lcd.print(L);
      
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

void scan(){
    key_1 = digitalRead(KEY_add);//读取输入数值并且存储
    key_3 = digitalRead(KEY_red);
    if((key_1==HIGH)&&(key_2==LOW))//检查按钮的变化情况
    { 
      L=L+0.01;
      delay(20);//只多了这一行
      }
      key_2 = key_1;  
      if((key_3==HIGH)&&(key_4==LOW))//检查按钮的变化情况
    { 
      L=L-0.01;
      delay(20);
      }
      key_4 = key_3;  
//      Serial.println(L);
 }


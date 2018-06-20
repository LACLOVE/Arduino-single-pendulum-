//单摆周期测量仪 LCD1602显示
//利用时间函数计时
//利用按键模拟光电门开关计数
// made by 卢宁 2018.6.18
#define BUTTON  3//定义按钮在 3号引脚,连接一个下拉电阻
int val = 0;//变量val 存储按钮的状态
int old_val = 0;//暂存val变量的上一个时间状态
int state = 0;//打印到串口的数据，按钮每被按下一次，state自增1
int a=13;
int b=7;
int val_a,val_b;
float t1;
float t2;
float t;
 void setup(){
  pinMode(BUTTON, INPUT); 
  pinMode(a, OUTPUT); 
  pinMode(b, OUTPUT); 
  Serial.begin(9600);//用于串口输出
   }
 
 void loop(){
    val = digitalRead(BUTTON);//读取输入数值并且存储
    val_a = digitalRead(a);//读取输入数值并且存储
    val_b = digitalRead(b);//读取输入数值并且存储
    if((val==LOW)&&(old_val==HIGH))//检查按钮的变化情况
    {
      printState();
      delay(20);//只多了这一行
      }
      old_val=val;//val现在是旧的了，让我们暂存一下 
 }
 void printState()
 {

  state++;
  Serial.println(state);
  if(state==6){
    digitalWrite(a, HIGH);
    t1=millis();
  }
  if(state==18){
    digitalWrite(a, LOW);
    t2=millis();
    state=0;
    float t=t2-t1;
    Serial.print("   ");
    Serial.print("t:");
    Serial.print(t); 
    Serial.println("ms");

    Serial.print("   ");
    Serial.print("t:");
    Serial.print(t/1000); 
    Serial.println("s");
    float T=(t/1000)/6;
    
    Serial.print("   ");
    Serial.print("T:");
    Serial.print(T); 
    Serial.println("s");
    float fen_zi=4*3.14*3.14*0.65;//分子4π²L（摆长）
    float g=fen_zi/(T*T);

    Serial.print("   ");
    Serial.print("g:");
    Serial.print(g); 
    }

   
  }

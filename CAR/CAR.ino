#include <PS2X_lib.h>
//C語言有public與private之分
//public通常是可以開放大家使用的
//private是作者本人測試 或是public程式會使用的"原始程式"
#include <Servo.h>

PS2X ps2x; 
int error;

Servo num_1;
Servo num_2;
Servo num_3;
Servo num_4;
Servo num_5;
Servo num_6;


void setup() {
  //46~53

  //for(參考值 ; 條件 ; 遞進式){}
  for(int x = 46 ; x < 54 ; x = x + 1) {
    pinMode(x,OUTPUT);
  }

  Serial.begin(57600);
  do { //clk,att,cmd,dat//14,15,16,17
    //GamePad(clock, command, attention, data, Pressures?, Rumble?)
    error = ps2x.config_gamepad(14, 16, 15, 17, true, true);   //這行要和接線對應正確
    if (error == 0) { Serial.print("Gamepad found!");break; } 
    else { 
      delay(100);
    } 
  } while (1);

  num_1.attach(8);
  num_2.attach(9);
  num_3.attach(10);
  num_4.attach(11);
  num_5.attach(12);
  num_6.attach(13);

}
/*--------------------------------------------*/
void stop(){

  for(int i = 46 ; i < 54 ; i+=2){       //i = i + 1 or i++ or i+=1
                                        //i = i + 2 or i+=2
    digitalWrite(i,LOW);
    digitalWrite(i+1,LOW);
  }
}
/*--------------------------------------------*/
void forward(){

  for(int i = 46 ; i < 54 ; i+=2){       //i = i + 1 or i++ or i+=1
                                        //i = i + 2 or i+=2
    digitalWrite(i,HIGH);
    digitalWrite(i+1,LOW);
  }
}
/*--------------------------------------------*/
void backward(){
  
  for(int i = 46 ; i < 54 ; i+=2){      //i = i + 1 or i++ or i+=1
                                        //i = i + 2 or i+=2
    digitalWrite(i,LOW);
    digitalWrite(i+1,HIGH);
  }
}
/*--------------------------------------------*/
void right(){

  int j = 0;
  for(int i = 46 ; i < 54 ; i+=2){      //i = i + 1 or i++ or i+=1    //i = i + 2 or i+=2
    
    if(j % 2 == 1){                 //模數除法%   用法: 11除以3的餘數是2: 11%3 = 2
      digitalWrite(i,HIGH);
      digitalWrite(i+1,LOW);
    }

    else{
      digitalWrite(i,LOW);
      digitalWrite(i+1,HIGH);
    }

    j++;

  }
}
/*--------------------------------------------*/
void left(){

  int j = 1;
  for(int i = 46 ; i < 54 ; i+=2){
    
    if(j % 2 == 1){
      digitalWrite(i,HIGH);
      digitalWrite(i+1,LOW);
    }

    else{
      digitalWrite(i,LOW);
      digitalWrite(i+1,HIGH);
    }

    j++;

  }
}

void turn_right(){

  int j = 1;
  for(int i = 46 ; i < 54 ; i+=2){

    if(j <= 2){
      digitalWrite(i,HIGH);
      digitalWrite(i+1,LOW);
    }
    else{
      digitalWrite(i,LOW);
      digitalWrite(i+1,HIGH);
    }
    j++;
  }
}
void turn_left(){

  int j = 1;
  for(int i = 46 ; i < 54 ; i+=2){

    if(j <= 2){
      digitalWrite(i,LOW);
      digitalWrite(i+1,HIGH);
    }
    else{
      digitalWrite(i,HIGH);
      digitalWrite(i+1,LOW);
    }
    j++;
  }
}

/*--------------------------------------------*/




void loop() {
  ps2x.read_gamepad();
  delay(10);

  int raw_rx = ps2x.Analog(PSS_RX) / 2.5;
  Serial.prinln(raw_rx);
    int rx = map(raw_rx, 0, 255, 170, 10);
    //控制數, 控制0%, 控制100%, 被控制0%, 控制100%
    num_6.write(rx);


  if(ps2x.Button(PSB_PAD_UP)){
    forward();
  }

  else if(ps2x.Button(PSB_PAD_DOWN)) {
    backward();
  }

  else if(ps2x.Button(PSB_PAD_RIGHT)) {
    right();
  }

  else if(ps2x.Button(PSB_PAD_LEFT)) {
    left();
  }
  
  else if(ps2x.Button(PSB_R1)) {
    turn_right();
  }
  
  else if(ps2x.Button(PSB_L1)) {
    turn_left();
  }

  else{
    stop();
  }

}
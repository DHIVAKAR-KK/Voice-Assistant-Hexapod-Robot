#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define SDA_PIN 21  //Datapin 21 Esp32
#define SCL_PIN 22  //Datapin 22 Esp32
#define wait 100
#define wait1 500
#define wait2 500
Adafruit_PWMServoDriver pwm;
BluetoothSerial MORA;
void Rightforward();
void Leftforward();
void wake();
void riseup();
void risedown();
// setup MORA.begin("MORA_");
void setup() {
  Serial.begin(9600);
  MORA.begin("MORA_");
  Wire.begin(SDA_PIN, SCL_PIN);
  pwm.begin();
  pwm.setPWMFreq(50);
  Serial.println("MORA_ROBOT_Initialized");
  wake();
  Serial.println("MORA IS WAKING UP");

  
}
String command;  // Variable initialized for storing the commands
void loop() {
   if (MORA.available() >0) {                         
    command = MORA.readStringUntil('\n'); 
     Serial.println(command);}
   
    if(command == "riseup") {
          riseup();   // if command is riseup bot will rise up
    }
    else if(command == "forward"){   
          Rightforward();   // if command is forward bot will move forward 
          Leftforward();
          Rightforward();
          Leftforward();        
    }
    else if(command == "risedown"){
          risedown();       // if command is risedown the bot will risedown
    }
  
    else {
      wake();  // else bot will stay wake
    }

  }


void setServoAngle(uint8_t channel, int angle) {
  int pwmValue = map(angle, 0, 180, 150, 600);
  pwm.setPWM(channel, 0, pwmValue);
}
void wake(){
  setServoAngle(0, 60);//60 constant decrase for forward
  delay(100);
  setServoAngle(5, 85);
  delay(100);
  setServoAngle(1, 100);
  delay(100);
  setServoAngle(4, 90);
  delay(100);
  setServoAngle(2, 40);
  delay(100);
  setServoAngle(3, 50);//50 constant increase for forward
  delay(100);
  setServoAngle(6, 70);///increase
  delay(100);
  setServoAngle(8, 110);//increase
  delay(100);
  setServoAngle(11, 110);//increase
  delay(100);
  setServoAngle(9, 110);//increase
  delay(100);
  setServoAngle(7, 50);//decrease
  delay(100);
  setServoAngle(10, 50);//decrease
  delay(100);
}
void Rightforward(){
  setServoAngle(11, 90);
  delay(wait);
  setServoAngle(7, 20);
  delay(wait);
  setServoAngle(9, 50);
  delay(wait);
  setServoAngle(3, 80);
  delay(wait1);
  setServoAngle(1, 70);
  delay(wait1);
  setServoAngle(5,125);
  delay(wait1);
  setServoAngle(11, 120);
  delay(wait);
  setServoAngle(7, 50);
  delay(wait);
  setServoAngle(9, 110);
  delay(wait);
  setServoAngle(3, 50);
  delay(wait1);
  setServoAngle(1, 100);
  delay(wait1);
  setServoAngle(5, 85);
  delay(wait1);
}
void Leftforward(){
  setServoAngle(6, 40);
  delay(wait);
  setServoAngle(10, 100);
  delay(wait);
  setServoAngle(8, 50);
  delay(wait);
  setServoAngle(0, 40);
  delay(wait1);
  setServoAngle(4, 125);
  delay(wait1);
  setServoAngle(2, 0);
  delay(wait1);
  setServoAngle(6, 70);
  delay(wait);
  setServoAngle(10, 50);
  delay(wait);
  setServoAngle(8, 110);
  delay(wait);
  setServoAngle(0, 70);
  delay(wait1);
  setServoAngle(4, 90);
  delay(wait1);
  setServoAngle(2, 40);
  delay(wait1);

}void risedown(){
  setServoAngle(3, 30);
  delay(wait2);
  setServoAngle(5, 130);
  delay(wait2);
  setServoAngle(0, 90);
  delay(wait2);
  setServoAngle(2, 0);
  delay(wait2);
  setServoAngle(1, 100);
  delay(wait2);
  setServoAngle(4, 90);
  delay(wait2);
  setServoAngle(9, 110);
 
  setServoAngle(11, 120);
  
  setServoAngle(8, 110);
  
  setServoAngle(6, 70);
 
  setServoAngle(7, 50);

  setServoAngle(10, 50);
  delay(wait2);

  
}void riseup(){

  setServoAngle(3, 30);
  delay(wait2);
  setServoAngle(5, 130);
  delay(wait2);
  setServoAngle(0, 90);
  delay(wait2);
  setServoAngle(2, 0);
  delay(wait2);
  setServoAngle(1, 100);
  delay(wait2);
  setServoAngle(4, 90);
  delay(wait2);
  setServoAngle(9, 140);
  
  setServoAngle(11, 150);
 
  setServoAngle(8, 140);
  
  setServoAngle(6, 100);
 
  setServoAngle(7, 80);
 
  setServoAngle(10, 10);
  delay(wait2);
}

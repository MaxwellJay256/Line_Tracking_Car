#include <MsTimer2.h>
#include "Motor.h"
#include "IRSensor.h"
#include "Device.h"
#include "Drive.h"

//#define TARGET 250

void Control() {
     
  Drive::classic_move();
//注意！！！！！！现在换成了UNO版
}

void setup()
{
    TCCR1B = TCCR1B & B11111000 | B00000001;//PWM频率调节，设置9、10引脚的PWM输出频率为31372Hz，适合于我们使用的电机
    MsTimer2::set(period, Control);
    MsTimer2::start();
    Serial.begin(9600);
    /*pinMode(24,INPUT);
    pinMode(26,INPUT);
    pinMode(28,INPUT);
    pinMode(30,INPUT);
    pinMode(32,INPUT);
    pinMode(3,INPUT);
    pinMode(4,INPUT);
    pinMode(5,INPUT);
    pinMode(2,INPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    //pinMode(12,INPUT);
    //pinMode(13,INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);*/

}

void loop()
{
    //DisplayInfo();
    Serial.print(MotorL.velocity);
    Serial.print(",");
    Serial.print(MotorR.velocity);
    Serial.print(",");
    //Serial.print(TARGET);
    Serial.print("\r\n");
    delay(period);

    //Drive::PatrolEnd();
}

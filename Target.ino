#include "Target.h"
// Servo servo1; //서보모터모터모터
// Servo servo2;
// //int sensorpin = 0; //센서핀 A0
// int distance1 = 0; //거리 센서값 =
// int distance2 = 0;
// // int moterv = 0; //모터 조향값

#define TARGET_COUNT 1

Target target[TARGET_COUNT];

void setup()
{
    Serial.begin(9600);

    target[0].init(7, A0);
}
/*
   멀어지면 적외선 센서값은 낮아지고, 가까워지면 적외선 센서값은 증가함.
 */
void loop()
{
    for (int i = 0; i < TARGET_COUNT; i++) 
        target[i].check();
}

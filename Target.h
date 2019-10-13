#ifndef TARGET_H
#define TARGET_H

#include <Servo.h>

class Target {
private:
    Servo servo;
    int disPort;
    int getDistance() {
      return analogRead(disPort);
    }
public:
    static const int moterv = 0;
    init (int servPort, int disPort) {
        servo.attach(servPort);
        servo.write(0);

        this->disPort = disPort;

        Serial.print("disPort : ");
        Serial.println(this->disPort);
        Serial.print("servPort : ");
        Serial.println(servPort);
    }

    check() {
        int distance = getDistance();
        Serial.println(distance);
        delay(300); //0.3초 지연
        if (distance >= 150) { //과녁이 쓰러진것
                Serial.println("Over");
                servo.write(80);
                delay(300);
                servo.write(0);
        }
        else if (distance < 150) { //과녁이 아직 쓰러지지 않음
                servo.write(0);
        }
    }
};

#endif

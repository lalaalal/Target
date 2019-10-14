#include <Servo.h>

class Target {
private:
    Servo servo;
    const int SERVO_PORT;
    const int INFRARED_PORT;
    const int TARGET_SCORE;
    
    int getDistance() {
      return analogRead(INFRARED_PORT);
    }
public:
    static const int SERVO_READY = 0;
    static const int SERVO_PUSH  = 100;
    static const int SERVO_CHECK = 400;
    
    Target (int servPort, int infraredPort, int targetScore)
        : SERVO_PORT(servPort), INFRARED_PORT(infraredPort), TARGET_SCORE(targetScore) {
        servo.attach(servPort);
        servo.write(SERVO_READY);
    }

    int check() {
        Serial.print(SERVO_PORT);
        Serial.print(" : ");
        Serial.println(getDistance());
        if (getDistance() >= SERVO_CHECK) {
            while (getDistance() >= SERVO_CHECK) {
                servo.write(SERVO_PUSH);
            }
            delay(500);
            return TARGET_SCORE;
        } else {
            servo.write(SERVO_READY);
            return 0;
        }
    }
};

typedef Target * TargetPtr;

#define TARGET_COUNT 6

TargetPtr target[TARGET_COUNT];

int score = 0;

void setup()
{
    Serial.begin(9600);

    target[0] = new Target(2, A0, 10);
    target[1] = new Target(3, A1, 20);
    target[2] = new Target(4, A2, 30);
    target[3] = new Target(5, A3, 60);
    target[4] = new Target(6, A4, 40);
    target[5] = new Target(7, A5, 50);
}

void loop()
{   
    for (int i = 0; i < TARGET_COUNT; i++) 
        score += target[i]->check();
    Serial.print("score : ");
    Serial.println(score);
}

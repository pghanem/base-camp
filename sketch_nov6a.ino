
#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN_LEFT  11
#define ECHO_PIN_LEFT     10
#define TRIGGER_PIN_RIGHT  12
#define ECHO_PIN_RIGHT     13
#define MAX_DISTANCE 200
#define MOTOR_A_1A 2
#define MOTOR_A_1B 4
#define MOTOR_B_1A 6
#define MOTOR_B_1B 8

Servo myservo;
Servo myservo2; // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;
int pos2 = 0;

NewPing sonarRight(TRIGGER_PIN_RIGHT, ECHO_PIN_RIGHT, MAX_DISTANCE);
NewPing sonarLeft(TRIGGER_PIN_LEFT, ECHO_PIN_LEFT, MAX_DISTANCE);

void setup() {
  // Motor pins need to be OUTPUT.
  Serial.begin(115200);
  pinMode(MOTOR_A_1A, OUTPUT);
  pinMode(MOTOR_A_1B, OUTPUT);
  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT);
  myservo.attach(3);
  myservo2.attach(5);// attaches the servo on pin 9 to the servo object

}

void wheelABackwards() {
  analogWrite(MOTOR_A_1A, 255);
  analogWrite(MOTOR_A_1B, 0);
}

void wheelAForwards() {
  analogWrite(MOTOR_A_1A, 0);
  analogWrite(MOTOR_A_1B, 255);
}

void wheelAStop() {
  analogWrite(MOTOR_A_1A, 0);
  analogWrite(MOTOR_A_1B, 0);
}

void wheelBForwards() {
  analogWrite(MOTOR_B_1A, 255);
  analogWrite(MOTOR_B_1B, 0);
}

void wheelBBackwards() {
  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_1B, 255);
}

void wheelBStop() {
  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_1B, 0);
}

void loop() {
  // use the wheel... methods to drive one motor.

  delay(250);
  Serial.print("Ping Right: ");
  Serial.print(sonarRight.ping_cm());
  Serial.println("cm");
  Serial.print("Ping Left: ");
  Serial.print(sonarLeft.ping_cm());
  Serial.println("cm");

  if (sonarRight.ping_cm() <= 25) {
    wheelAStop();
    delay(100);

    for (pos = 180; pos >= 0; pos -= 2) {

      myservo.write(pos);

      if (pos2 <= 180) {
        myservo2.write(pos2);
        pos2 += 2;
      } else {
        pos2 = 0;
      }

      delay(20);
    }


  } else if (sonarLeft.ping_cm() <= 25) {
    wheelBStop();
  }
  else
  {
    wheelAForwards();
    wheelBForwards();
  }
}




#include <Servo.h>
Servo mijnservo;

void setup() {
  mijnservo.attach(8);
}

void loop() {
  mijnservo.write(90);
  delay(500);
  mijnservo.write(0);
  delay(500);
}
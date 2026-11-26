#include <Servo.h>
Servo minservo;

void setup() {
  minservo.attach(8);
}

void loop() {
  minservo.write(90);
  delay(500);
  minservo.write(0);
  delay(500);
}
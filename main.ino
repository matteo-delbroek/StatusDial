#include <Servo.h>
Servo myServo;

const int ledR = 4;
const int ledG = 5;
const int ledB = 6;
const int piezo = 9;
const int ultrasonic = 7;

int currentZone = 0; 

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(piezo, OUTPUT);
  myServo.attach(8);
  Serial.begin(9600);
}

void loop() {
  pinMode(ultrasonic, OUTPUT);
  digitalWrite(ultrasonic, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonic, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonic, LOW);
  
  pinMode(ultrasonic, INPUT);
  long duration = pulseIn(ultrasonic, HIGH, 30000);
  float distance = (duration * 0.0343) / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(50);
  
  if (distance <= 50) {
    analogWrite(ledR, 255);
    analogWrite(ledG, 0);
    analogWrite(ledB, 0);
    myServo.write(45);
    
    if (currentZone != 2) {
      tone(piezo, 800);
      delay(100);
      noTone(piezo);
      currentZone = 2;
    }
  }
  else if (distance <= 75) {
    analogWrite(ledR, 255);
    analogWrite(ledG, 165);
    analogWrite(ledB, 0);
    myServo.write(45);
    
    if (currentZone != 1) {
      tone(piezo, 500);
      delay(100);
      noTone(piezo);
      currentZone = 1;
    }
  }
  else if (distance > 75 && distance <= 100) {
    analogWrite(ledR, 0);
    analogWrite(ledG, 255);
    analogWrite(ledB, 0);
    myServo.write(45);
    currentZone = 0;
  }
  else {
    analogWrite(ledR, 0);
    analogWrite(ledG, 0);
    analogWrite(ledB, 0);
    myServo.write(135);
    currentZone = 0; 
  }
}.
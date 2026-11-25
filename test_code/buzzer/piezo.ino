const int piezoPin = 9;

void setup() {
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  tone(piezoPin, 800 ); 
  delay(100);
  noTone(piezoPin);     
  delay(1000);
}
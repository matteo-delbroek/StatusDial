const int sigPin = 7; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(sigPin, LOW);

  pinMode(sigPin, INPUT);
  long duur = pulseIn(sigPin, HIGH);

  float afstand = (duur * 0.0343) / 2;

  Serial.print("Afstand: ");
  Serial.print(afstand);
  Serial.println(" cm");

  delay(200);
}
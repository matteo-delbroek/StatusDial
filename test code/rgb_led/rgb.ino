const int rgbRed = 4;
const int rgbBlue = 6;
const int rgbGreen = 5;
void setup()
{
  pinMode(rgbRed, OUTPUT);
  pinMode(rgbBlue, OUTPUT);
  pinMode(rgbGreen, OUTPUT);
}

void loop()
{
  analogWrite(rgbBlue,0);
  analogWrite(rgbRed, 0);
  analogWrite(rgbGreen, 0);
  delay(1000);
  analogWrite(rgbBlue, 255);
  analogWrite(rgbRed, 0);
  analogWrite(rgbGreen, 0);
  delay(1000);
  analogWrite(rgbBlue, 0);
  analogWrite(rgbRed, 255);
  analogWrite(rgbGreen, 0);
  delay(1000);
  analogWrite(rgbBlue, 0);
  analogWrite(rgbRed, 0);
  analogWrite(rgbGreen, 255);
  delay(1000);
  analogWrite(rgbBlue, 186);
  analogWrite(rgbRed, 247);
  analogWrite(rgbGreen, 116);
  delay(1000);
  
}
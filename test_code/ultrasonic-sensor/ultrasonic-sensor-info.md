### Ultrasonic sensor test code
This is only for testing or getting started; this is not the actual program!

1. Flash `test_code/ultrasonic-sensor/ultrasonic-sensor.ino` onto your Arduino and make sure the wiring is correct:

| Pin | Arduino pin |
| :--- | :--- |
| Ultrasonic minus (-) | GND |
| Ultrasonic plus (+) | 5V |
| Ultrasonic signal | D7 |

#### How does an ultrasonic sensor work?
- It sends out a short, high-frequency sound wave and listens for the echo to bounce back, allowing you to measure how long the round trip takes.
- To use this 3-pin sensor without a library, we switch the same pin (`D7`) rapidly between sending and receiving:
  1. Set the pin to `OUTPUT` (`pinMode(7, OUTPUT);`) and send a 10-microsecond pulse using `digitalWrite()`.
  2. Immediately switch the pin to `INPUT` (`pinMode(7, INPUT);`) and measure the echo duration in microseconds with `pulseIn(7, HIGH)`.
  3. Convert the time into distance (in centimeters) using the speed of sound: `distance = (duration * 0.0343) / 2`.
  
### Servo motor test code
This is only for testing or getting started; this is not the actual program!

1. Flash `test_code/servo/servo.ino` onto your Arduino and make sure the wiring is correct:

| Pin | Arduino pin |
| :--- | :--- |
| Servo minus (-) | GND |
| Servo plus (+) | 5V |
| Servo signal | D8 |

#### What is a servo?
A servo is a motor that you can set to a specific angle, such as 90°. For Arduino, you can use the `Servo.h` library. To use this library, include `#include <Servo.h>` at the top of your code. 

Next, create a servo object and give it a name, such as **myServo**, using `Servo myServo;`. To assign a pin to your servo, use `myServo.attach(8);` (matching pin D8). Finally, to move your servo to a specific angle, use `myServo.write(90);`.
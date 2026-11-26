### Piezo buzzer test code
This is only for testing or getting started this is not the actual program!
1. Flash `test_code/buzzer/piezo.ino` onto your Arduino and make sure the wiring is correct:

| Pin | Arduino pin |
| --- | --- |
| Piezo min (-) | D4 |
| Piezo plus (+) | D5 |

#### What is `tone()`?
`tone()` is how we tell our piezo which pitch to play, measured in Hertz (Hz). To change it, you can adjust the number in `tone(piezoPin, 800)`try changing `800` to another number and hear the difference! If you want to make the beep longer or shorter, you can change the duration in `delay(100)`.
# StatusDial 

**StatusDial** is a compact Arduino-powered monitor mount that lets people around you know if you're at your desk and warns you when you're sitting too close to your screen.

Using a 3-pin ultrasonic distance sensor, an RGB LED, a piezo buzzer, and an analog servo dial, it tracks how close you are in real time:
* **<= 50 cm (Too close!):** Red LED, servo needle points right (`45°`), and a short high-pitched warning beep (`800 Hz`).
* **51 – 75 cm (Getting close):** Orange LED, servo needle points right (`45°`), and a single soft alert beep (`500 Hz`).
* **76 – 100 cm (Good posture):** Green LED, servo needle stays right (`45°`), silent.
* **> 100 cm (Away from desk):** LED off, servo needle swings left (`135°`) to show you're away.

##  Features

-  **Tinkercad Simulation & Breadboard Circuit:** Tested ultrasonic distance sensing, RGB status feedback, single-beep zone alerts, and servo needle movement (`images/circuit-v3.png`).
-  **Modular Test Sketches:** Standalone test programs and documentation for every component in `test_code/`.
-  **Main Firmware (`main.ino`):** Combined non-repeating alert logic with real-time serial distance readout.
-  **3D-Printed Enclosure:** Custom monitor-top mount and physical dial pointer.

##  Components & Bill of Materials

See [`BOM.scv`](BOM.scv) for the full parts list and links.

| Component | Qty | Notes |
| :--- | :---: | :--- |
| **Arduino Uno R4 minima** | 1 | Main microcontroller |
| **Ultrasonic Distance Sensor (3-pin PING)))** | 1 | Single-pin Trigger/Echo (`Pin 7`) |
| **Micro Servo (SG90 / MG90S)** | 1 | Drives the physical status pointer (`Pin 8`) |
| **Common-Cathode RGB LED** | 1 | Visual distance status (`Pins 4, 5, 6` with resistors) |
| **Piezo Buzzer** | 1 | Audio alert when leaning in too close (`Pin 9`) |
| **Breadboard & Jumper Wires** | 1 set | Prototyping connections |
| **3D-Printed Case & Pointer** | 1 set | Custom monitor mount *(planned)* |

##  Wiring / Pinout (Arduino Uno)

| Component | Pin on Component | Arduino Pin | Notes |
| :--- | :--- | :--- | :--- |
| **RGB LED (Red)** | Red leg (via resistor) | `D4` | Digital/PWM output |
| **RGB LED (Green)** | Green leg (via resistor) | `D5` | PWM output |
| **RGB LED (Blue)** | Blue leg (via resistor) | `D6` | PWM output |
| **Ultrasonic Sensor** | `SIG` (Signal) | `D7` | Shared Trigger & Echo pin |
| **Micro Servo** | Signal (Yellow/Orange) | `D8` | Servo PWM control |
| **Piezo Buzzer** | Positive (`+`) | `D9` | Tone output |
| **All Components** | `5V` / `VCC` | `5V` | Power rail on breadboard |
| **All Components** | `GND` | `GND` | Common ground rail |

##  Repository Structure

```text
StatusDial/
├── images/
│   ├── circuit-v1.png          # Initial Tinkercad wiring (has power polarity bug)
│   ├── circuit-v2.png          # Fixed wiring + RGB LED test
│   └── circuit-v3.png          # Final circuit with piezo buzzer replacing vibration motor
├── test_code/
│   ├── buzzer/
│   │   ├── piezo.ino           # Piezo tone test sketch
│   │   └── piezo-info.md       # Notes on wiring and tone() usage
│   ├── rgb_led/
│   │   ├── rgb.ino             # RGB color mixing test sketch
│   │   └── rgb-led-info.md     # Pinout and resistor notes
│   ├── servo/
│   │   ├── servo.ino           # Servo angle calibration sketch
│   │   └── servo-info.md       # Servo angle & horn alignment notes
│   └── ultrasonic-sensor/
│       ├── ultrasonic-sensor.ino       # Distance measurement test sketch
│       └── ultrasonic-sensor-info.md   # Pulse timing & cm conversion notes
├── BOM.md                      # Bill of Materials
├── JOURNAL.md                  # Build log across sessions
├── main.ino                    # Full StatusDial firmware
└── README.md                   # Project overview & wiring guide
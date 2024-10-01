
# Body Conductivity Measurement Project

This Arduino project measures body conductivity using a metal probe and displays the results with an LED strip. It utilizes the Adafruit NeoPixel library to control the LED effects based on the measured resistance.

## Features

- Measures body resistance through a conductive probe.
- Visualizes resistance values with LED effects.
- Includes a button to activate or deactivate the measurement.

## Requirements

- Arduino board (e.g., Arduino Uno, Nano, etc.)
- Metal probe for measuring body resistance
- Adafruit NeoPixel library
- LED strip
- A button

## Installation

1. **Install the Arduino IDE**: Download and install the [Arduino IDE](https://www.arduino.cc/en/software).

2. **Install the Adafruit NeoPixel Library**:
   - Open the Arduino IDE.
   - Go to **Sketch** > **Include Library** > **Manage Libraries**.
   - In the Library Manager, search for "Adafruit NeoPixel" and install it.

3. **Connect the Hardware**:
   - Connect the metal probe to analog pin A2 on the Arduino.
   - Connect the LED strip to the appropriate digital pins (11, 9, 10).
   - Connect a button to digital pin 8.

## Usage

1. Open the `body_c.ino` file in the Arduino IDE.
2. Upload the code to your Arduino board.
3. Press the button to start measuring body conductivity.
4. Observe the LED strip changing colors based on the resistance values.

## Code Overview

The code reads the resistance value from the metal probe and adjusts the LED strip's effects according to the measurement. It includes initialization for the LED strip and the button state.

### Example Code Snippet

```cpp
#include <Adafruit_NeoPixel.h>

int sensore = A2; // Pin for body resistance measurement
int val = 0;

// LED strip and transistor pin definitions
int led = 11;
int pin = 9; 
int pin2 = 10;
int num2 = 12;
int num = 12; 

// Variables for LED strip effects
int salto = 4;
int i;
int f;

// Button pin and state
int button = 8;
int pulsante;

void setup() {
    // Initialize the LED strip and button
}

void loop() {
    // Measure resistance and control LED effects
}
```

## Customization

You can modify the pin numbers and the number of LEDs in the strip by changing the relevant definitions in the code. Additionally, you can implement your own LED effects based on the measured resistance.

## License

This project is licensed under CC-BY-SA license
Project made by Luca Passarini

/*
  ******************************************************************************
  SNES Controller to XInput Converter for Arduino Leonardo(Pro Micro)
  ------------------------------------------------------------------------------
  2023.11 @kiyokura
  ******************************************************************************
  Reference：
  - snes_gamepad_arduino
    - https://github.com/ka-zuu/snes_gamepad_arduino
  - Arduino XInput Library
    - https://github.com/dmadison/ArduinoXInput
  ===================================================
  Mapping:
  ----------------------------------------
  XBOX 360             <- SNES
  ----------------------------------------
  L Stick(XY Axis)     <- Directional Pad
  R Stick(XY Rotation) <- N/A
  D-Pad(POV)           <- N/A
  A Button             <- A Button 
  B Button             <- B Button 
  X Button             <- X Button 
  Y Button             <- Y Button 
  L Button             <- L Button 
  R Button             <- R Button 
  L3 Button            <- N/A
  L3 Button            <- N/A
  L Trigger(Z Axis)    <- N/A
  R Trigger(Z Axis)    <- N/A
  ===================================================
  SNES Controller Pinout:
  ------------------
  | 1 2 3 4 | 5 6 7|
  ------------------
  Pin 1 : VCC(+5V)
  Pin 2 : Data Clock
  Pin 3 : Data Latch 
  Pin 4 : Data Serial
  Pin 5 : N/A
  Pin 6 : N/A
  Pin 7 : GND
  ===================================================
  Arduino Leonardo(Pro Micro) Pin Assign:
  --------------------------------------
  GND   : GND              (SNES Pin 7)
  VCC   : VCC              (SNES Pin 1)
  Pin 7 : SNES Data Clock  (SNES Pin 2)
  Pin 8 : SNES Data Latch  (SNES Pin 3)
  Pin 9 : SNES Data Serial (SNES Pin 4)
  ===================================================
  SNES Controller Serial Data:
  --------------------------------
  Clock : Button
  --------------------------------
  1     : B
  2     : Y
  3     : SELECT
  4     : START
  5     : UP
  6     : DOWN
  7     : LEFT
  8     : RIGHT
  9     : A
  10    : X
  11    : L
  12    : R
  13    : N/A
  14    : N/A
  15    : N/A
  16    : N/A
 ===================================================
*/
#include <XInput.h>

// Arduino pins
#define DATA_CLOCK  7  // Wiring SNES Data Clock
#define DATA_LATCH  8  // Wiring SNES Data Latch
#define DATA_SERIAL 9  // Wiring SNES Data Serial

// SNES buttons index
#define SNES_BUTTON_B      0
#define SNES_BUTTON_Y      1
#define SNES_BUTTON_SEL    2
#define SNES_BUTTON_ST     3
#define SNES_BUTTON_UP     4
#define SNES_BUTTON_DOWN   5
#define SNES_BUTTON_LEFT   6
#define SNES_BUTTON_RIGHT  7
#define SNES_BUTTON_A      8
#define SNES_BUTTON_X      9
#define SNES_BUTTON_L     10
#define SNES_BUTTON_R     11

// Data store for current state of SNES buttons
int buttons[12];

void setup() {
  // Set DATA_CLOCK normally HIGH
  pinMode (DATA_CLOCK, OUTPUT);
  digitalWrite (DATA_CLOCK, HIGH);
  
  // Set DATA_LATCH normally LOW
  pinMode (DATA_LATCH, OUTPUT);
  digitalWrite (DATA_LATCH, LOW);
  
  // Set DATA_SERIAL normally HIGH
  pinMode (DATA_SERIAL, OUTPUT);
  digitalWrite (DATA_SERIAL, HIGH);
  pinMode (DATA_SERIAL, INPUT_PULLUP);  
  
  // Initialize XInput Library
  XInput.setJoystickRange(-1, 1);
  XInput.begin();
}

void loop() {
  // Latch
  digitalWrite(DATA_LATCH, HIGH);
  digitalWrite(DATA_LATCH, LOW);
  
  // Read data bit by bit from SR
  for (int i = 0; i < 16; i++) {
    digitalWrite (DATA_CLOCK, LOW);
    if (i <= 11) {
      buttons[i] = digitalRead (DATA_SERIAL);
    }
    digitalWrite (DATA_CLOCK, HIGH);
  }
  
  // -----------------------------------------
  // Set Joystick buttons state
  // -----------------------------------------
  // Directional Pad
  if (buttons[SNES_BUTTON_UP] == 0){
    XInput.setJoystickY(JOY_LEFT, 1);
  } else if (buttons[SNES_BUTTON_DOWN] == 0){
    XInput.setJoystickY(JOY_LEFT, -1);
  } else {
    XInput.setJoystickY(JOY_LEFT, 0);
  }
  if (buttons[SNES_BUTTON_RIGHT] == 0){
    XInput.setJoystickX(JOY_LEFT, 1);
  } else if (buttons[SNES_BUTTON_LEFT] == 0){
    XInput.setJoystickX(JOY_LEFT, -1);
  } else {
    XInput.setJoystickX(JOY_LEFT, 0);
  }
  
  // Buttons
  XInput.setButton(BUTTON_A,     !buttons[SNES_BUTTON_A]);
  XInput.setButton(BUTTON_B,     !buttons[SNES_BUTTON_B]);
  XInput.setButton(BUTTON_X,     !buttons[SNES_BUTTON_X]);
  XInput.setButton(BUTTON_Y,     !buttons[SNES_BUTTON_Y]);
  XInput.setButton(BUTTON_LB,    !buttons[SNES_BUTTON_L]);
  XInput.setButton(BUTTON_RB,    !buttons[SNES_BUTTON_R]);
  XInput.setButton(BUTTON_BACK,  !buttons[SNES_BUTTON_SEL]);
  XInput.setButton(BUTTON_START, !buttons[SNES_BUTTON_ST]);

  delay(10);
}

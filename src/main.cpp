#include <Arduino.h>
#include <HID-Project.h>
#include <HID-Settings.h>

// function prototypes
void rightStep();
void leftStep();
void rotaryEncoder();

// global variables
bool pin2State = HIGH;
bool pin3State = HIGH;
bool buttonState = HIGH;
bool lastButtonState = HIGH;
unsigned long lastButtonDebounceTime = 0;
unsigned long buttonPressStartTime = 0;
int buttonPressCount = 0;
unsigned long lastPressTime = 0;
bool buttonHeld = false;

const unsigned long debounceDelay = 50; // Debounce delay in ms
const unsigned long doubleClickWindow = 300; // Time window for double click in ms

void setup() {
  Serial.begin(115200);// Initialize serial communication at 115200 baud rate

  Consumer.begin(); // Initialize the Consumer control for HID

  // Set pin modes
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  // Read initial states
  pin2State = digitalRead(2);
  pin3State = digitalRead(3);
  buttonState = digitalRead(7);
  lastButtonState = buttonState;

  // Attach interrupts for encoder
  attachInterrupt(digitalPinToInterrupt(2), rotaryEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), rotaryEncoder, CHANGE);
}

void loop() {
  // Read button state
  bool reading = digitalRead(7);

  // Debounce button
  if (reading != lastButtonState) {
    lastButtonDebounceTime = millis();
  }

  if ((millis() - lastButtonDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) { // Button pressed
        buttonPressStartTime = millis();
        buttonHeld = true;
      } else { // Button released
        if (buttonHeld) {
          unsigned long pressDuration = millis() - buttonPressStartTime;
          if (pressDuration < 1000) { // Short press
            if (millis() - lastPressTime < doubleClickWindow) {
              buttonPressCount++;
            } else {
              buttonPressCount = 1;
            }
            lastPressTime = millis();
          }
          buttonHeld = false;
        }
      }
    }
  }

  lastButtonState = reading;

  // Check for completed button presses
  if (buttonPressCount > 0 && (millis() - lastPressTime) > doubleClickWindow) {
    if (buttonPressCount == 1) {
      Serial.println("Single Button Press Detected");
      Consumer.write(MEDIA_PLAY_PAUSE);
    } else if (buttonPressCount == 2) {
      Serial.println("Double Button Press Detected");
      Consumer.write(MEDIA_VOL_MUTE);
    }
    buttonPressCount = 0;
  }
}

void rotaryEncoder() {
  // Read current states
  bool pin2Current = digitalRead(2);
  bool pin3Current = digitalRead(3);

  // Check for change in pin 2
  if (pin2Current != pin2State) {
    pin2State = pin2Current;
    if (pin2Current == LOW) {
      if (pin3Current == HIGH) {
        leftStep();
      } else {
        rightStep();
      }
    }
  }

  // Update pin3 state
  pin3State = pin3Current;
} 



void rightStep() {
  if (digitalRead(7) == LOW) { // Button is pressed
    Serial.println("Right Step with Button Pressed");
    Consumer.write(MEDIA_NEXT);
  } else {
    Serial.println("Right Step without Button Pressed");
    Consumer.write(MEDIA_VOLUME_UP);
  }
}

void leftStep() {
  if (digitalRead(7) == LOW) { // Button is pressed
    Serial.println("Left Step with Button Pressed");
    Consumer.write(MEDIA_PREVIOUS);
  } else {
    Serial.println("Left Step without Button Pressed");
    Consumer.write(MEDIA_VOLUME_DOWN);
  }
}
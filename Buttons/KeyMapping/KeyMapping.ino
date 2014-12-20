#include "Arduino.h"

// Ubuntu
// to upload there must be a-star.rules in /etc/udev/rules.d
// to run remove/rename file
// reset the board after each change


// constants won't change. They're used here to 
// set pin numbers:
const int buttonPinRed = 1;    // the number of the red pushbutton pin
const int buttonPinBlack = 0;    // the number of the black pushbutton pin


boolean currentStateRed = LOW;//stroage for current measured button state
boolean lastStateRed = LOW;//storage for last measured button state
boolean debouncedStateRed = LOW;//debounced button state

boolean currentStateBlack = LOW;//stroage for current measured button state
boolean lastStateBlack = LOW;//storage for last measured button state
boolean debouncedStateBlack = LOW;//debounced button state


int debounceInterval = 20;//wait in Ams for button pin to settle
unsigned long timeOfLastButtonEventRed = 0;//store the last time the button state changed
unsigned long timeOfLastButtonEventBlack = 0;//store the last time the button state changed

void setup(){
  Serial.begin(9600);
  pinMode(buttonPinRed, INPUT_PULLUP);
  pinMode(buttonPinBlack, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  unsigned long currentTime = millis();    

  //Red  
  currentStateRed = digitalRead(buttonPinRed);

  if (currentStateRed != lastStateRed){
    timeOfLastButtonEventRed = currentTime;
  }

  if (currentTime - timeOfLastButtonEventRed > debounceInterval){//if enough time has passed
    if (currentStateRed != debouncedStateRed){//if the current state is still different than our last stored debounced state
      debouncedStateRed = currentStateRed;//update the debounced state

      //trigger an event
      if (debouncedStateRed == HIGH){
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_F10);
        //Keyboard.press('R');
        Keyboard.releaseAll();
        delay(50);
      }
    }
  }
  lastStateRed = currentStateRed;

  //Black
  currentStateBlack = digitalRead(buttonPinBlack);

  if (currentStateBlack != lastStateBlack){
    timeOfLastButtonEventBlack = currentTime;
  }

  if (currentTime - timeOfLastButtonEventBlack > debounceInterval){//if enough time has passed
    if (currentStateBlack != debouncedStateBlack){//if the current state is still different than our last stored debounced state
      debouncedStateBlack = currentStateBlack;//update the debounced state

      //trigger an event
      if (debouncedStateBlack == HIGH){
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_F9);
        //Keyboard.press('B');
        Keyboard.releaseAll();
        delay(50);
      }
    }
  }

  lastStateBlack = currentStateBlack;
}







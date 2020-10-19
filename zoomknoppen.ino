/*******************************************************************
Stach Redeker
Lifehacker_NEDERLAND
www.stachredeker.nl
 *******************************************************************/
 
#include "Keyboard.h"
// https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h
#include <Keypad.h>
// Zoek in de library manager op 'keypad'
// installeer de library van Mark Stanley and Alexander Brevig
// https://playground.arduino.cc/Code/Keypad/

const byte ROWS = 3; //drie 'rows'
const byte COLS = 2; //twee 'columns'

// Even de knoppen definiëren:
char keys[ROWS][COLS] = {
  {'1', '2'},
  {'3', '4'},
  {'5', '6'},
};

byte rowPins[ROWS] = {2, 3, 4}; 
byte colPins[COLS] = {6, 7}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}


void sendMacroCommand(uint8_t key) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(key);
}

void loop() {
  char key = keypad.getKey();


// Hieronder kun je je eigen sneltoetsen instellen
// Check hier de namen van 'bijzondere' toetsen: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
// Doordat de 'Keyboard.press'-functie wordt gebruikt, worden alle toetsen tegelijkertijd ingedrukt


  if (key) {
    Serial.println(key);
    switch (key) {
      case '1':
        Keyboard.press (KEY_LEFT_ALT);
        Keyboard.press (KEY_F1);
        break;
      case '2':
        Keyboard.press (KEY_LEFT_ALT);
        Keyboard.press (KEY_F2);
        break;
      case '3':
        Keyboard.press (KEY_LEFT_ALT);
        Keyboard.press ('n');
        break;
      case '4':
        Keyboard.press (KEY_LEFT_ALT);
        Keyboard.press ('y');
        break;
      case '5':
        Keyboard.press (KEY_LEFT_ALT);
        Keyboard.press ('v');
        break;
      case '6':
        Keyboard.press (KEY_LEFT_ALT);
        Keyboard.press ('a');
        break;
    }

    delay(100);
    Keyboard.releaseAll();
  }
}

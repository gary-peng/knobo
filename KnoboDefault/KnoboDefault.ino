#include "Knobo.h"
#include "Key.h"
#include <Encoder.h>
#include <Keyboard.h>

Key key1 = Key(13, 10, 500);
Key key2 = Key(5, 10, 500);
Key key3 = Key(9, 10, 500);
Key key4 = Key(8, 10, 500);
Key key5 = Key(6, 10, 500);
Key key6 = Key(4, 10, 500);
Key key7 = Key(10, 10, 500);
Key key8 = Key(12, 10, 500);

Key keyD = Key(11, 10, 500);
Encoder encoder = Encoder(2,3);
long oldPosition = -999;
bool wordSelect;

Knobo knobo = Knobo(key1, key2, key3, key4, key5, key6, key7, key8);

#define ledPin 7

void setup() {
    Serial.begin(9600);

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
}

void loop() {
    if(knobo.brailleUpdate()) {
        knobo.configBraille();
        knobo.configSpecialKeys();
    }

    configEncoder();
}

void configEncoder() {
    long newPosition = encoder.read() / 2;
    
    if (newPosition != oldPosition) {
        if (newPosition < oldPosition) {
            if(wordSelect) {
                //        Keyboard.press(KEY_LEFT_ALT);
                Keyboard.press(KEY_LEFT_CTRL);
                Keyboard.press(KEY_LEFT_ARROW);
                Keyboard.release(KEY_LEFT_ARROW);
                delay(100);
                Keyboard.release(KEY_LEFT_CTRL);
            } else
                Keyboard.write(KEY_LEFT_ARROW);
        }
    
        else if (newPosition > oldPosition) {
            if(wordSelect) {
                //        Keyboard.press(KEY_LEFT_ALT);
                Keyboard.press(KEY_LEFT_CTRL);
                Keyboard.press(KEY_RIGHT_ARROW);
                Keyboard.release(KEY_RIGHT_ARROW);
                delay(100);
                Keyboard.release(KEY_LEFT_CTRL);
            } else
                Keyboard.write(KEY_RIGHT_ARROW);
        }
        
        oldPosition = newPosition;
    }
    
    if (keyD.keyUpdate()) {
        keyD.keyDown();
        if (keyD.keyUp() == 1) {
            if (wordSelect == true)
                wordSelect = false;
            else
                wordSelect = true;
        }
    }
}

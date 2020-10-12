#include "Key.h"
#include "Arduino.h"
#include <Bounce2.h>

Key::Key() {
    
}

Key::Key(int pin, unsigned long bounceTime, unsigned long pressTime) {
    pinMode(pin, INPUT_PULLUP);
    this->pin = pin;
    this->bounceTime = bounceTime;
    this->pressTime = pressTime;
    key = Bounce(pin, bounceTime);
}

bool Key::keyUpdate() {
    return key.update();
}

bool Key::keyDown() {
    if (key.fallingEdge()) {
        pressStart = millis();
        return true;
    }

    return false;
}

int Key::keyUp() {
    if (key.risingEdge()) {
        if(millis() - pressStart >= pressTime)
            return 2;
        else
            return 1;
    }

    return 0;
}

#ifndef Key_h
#define Key_h

#include "Arduino.h"
#include <Bounce2.h>

class Key {
    public:
        Key();
        Key(int pin, unsigned long bounceTime, unsigned long pressTime);
        bool keyUpdate();
        bool keyDown();
        int keyUp();
        
    private:
        int pin;
        unsigned long bounceTime;
        unsigned long pressStart;
        unsigned long pressTime;
        Bounce key;
};

#endif

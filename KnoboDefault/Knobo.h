#ifndef Knobo_h
#define Knobo_h

#include "Arduino.h"
#include "Key.h"

class Knobo {
    public:
        Knobo(Key &key1, Key &key2, Key &key3, Key &key4, Key &key5, Key &key6, Key &key7, Key &key8);
        bool brailleUpdate();
        void configBraille();
        void configSpecialKeys();

    private:
        byte out = 0b000000;
        Key key1;
        Key key2;
        Key key3;
        Key key4;
        Key key5;
        Key key6;
        Key key7;
        Key key8;
        void printBraille(byte input);
};

#endif

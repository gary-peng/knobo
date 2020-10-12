#include "Knobo.h"
#include "Arduino.h"
#include "Key.h"
#include <Keyboard.h>

Knobo::Knobo(Key &key1, Key &key2, Key &key3, Key &key4, Key &key5, Key &key6, Key &key7, Key &key8) {
    this->key1 = key1;
    this->key2 = key2;
    this->key3 = key3;
    this->key4 = key4;
    this->key5 = key5;
    this->key6 = key6;
    this->key7 = key7;
    this->key8 = key8;
    
    Keyboard.begin();
}

bool Knobo::brailleUpdate() {
    return key1.keyUpdate() || key2.keyUpdate() || key3.keyUpdate() || key4.keyUpdate() || key5.keyUpdate() || key6.keyUpdate()|| key7.keyUpdate() || key8.keyUpdate();
}

void Knobo::configBraille() {
    if (key1.keyDown())
        bitWrite(out, 5, 1);    
    if (key2.keyDown())
        bitWrite(out, 4, 1);   
    if (key3.keyDown())
        bitWrite(out, 3, 1);
    if (key4.keyDown())
        bitWrite(out, 2, 1);
    if (key5.keyDown())
        bitWrite(out, 1, 1);    
    if (key6.keyDown())
        bitWrite(out, 0, 1);

    if(key1.keyUp() == 1 || key2.keyUp() == 1 || key3.keyUp() == 1 || key4.keyUp() == 1 || key5.keyUp() == 1 || key6.keyUp() == 1) {
        printBraille(out);

        for(int i=0; i<6; i++)
            bitClear(out, i);
    }
}
    
void Knobo::printBraille(byte input) {
    switch (input) {
        case 0b100000:
            Keyboard.write('a');
        break;
        case 0b101000:
            Keyboard.write('b');
        break;
        case 0b110000:
            Keyboard.write('c');
        break;
        case 0b110100:
            Keyboard.write('d');
        break;
        case 0b100100:
            Keyboard.write('e');
        break;
        case 0b111000:
            Keyboard.write('f');
        break;
        case 0b111100:
            Keyboard.write('g');
        break;
        case 0b101100:
            Keyboard.write('h');
        break;
        case 0b011000:
            Keyboard.write('i');
        break;
        case 0b011100:
            Keyboard.write('j');
        break;
        case 0b100010:
            Keyboard.write('k');
        break;
        case 0b101010:
            Keyboard.write('l');
        break;
        case 0b110010:
            Keyboard.write('m');
        break;
        case 0b110110:
            Keyboard.write('n');
        break;
        case 0b100110:
            Keyboard.write('o');
        break;
        case 0b111010:
            Keyboard.write('p');
        break;
        case 0b111110:
            Keyboard.write('q');
        break;
        case 0b101110:
            Keyboard.write('r');
        break;
        case 0b011010:
            Keyboard.write('s');
        break;
        case 0b011110:
            Keyboard.write('t');
        break;
        case 0b100011:
            Keyboard.write('u');
        break;
        case 0b101011:
            Keyboard.write('v');
        break;
        case 0b011101:
            Keyboard.write('w');
        break;
        case 0b110011:
            Keyboard.write('x');
        break;
        case 0b110111:
            Keyboard.write('y');
        break;
        case 0b100111:
            Keyboard.write('z');
        break;
    }
}

void Knobo::configSpecialKeys() {
    key7.keyDown();
    key8.keyDown();
    
    if (key7.keyUp() == 1)
         Keyboard.write(0x20);
    if (key7.keyUp() == 2)
        Keyboard.write(0xB3);
    if (key8.keyUp() == 1)
         Keyboard.write(0xB2);
    if (key8.keyUp() == 2)
        Keyboard.write(0xB0);
}

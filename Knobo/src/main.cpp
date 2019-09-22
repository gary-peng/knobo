#include <Keyboard.h>
#include <Bounce2.h>
#include <Encoder.h>

#define ledPin 7

#define bounceTime 10
unsigned long pressStart;
#define pressTime 500

#define key1Pin 13
Bounce key1 = Bounce(key1Pin, bounceTime);

#define key2Pin 5
Bounce key2 = Bounce(key2Pin, bounceTime);

#define key3Pin 9
Bounce key3 = Bounce(key3Pin, bounceTime);

#define key4Pin 8
Bounce key4 = Bounce(key4Pin, bounceTime);

#define key5Pin 6
Bounce key5 = Bounce(key5Pin, bounceTime);

#define key6Pin 4
Bounce key6 = Bounce(key6Pin, bounceTime);

#define key7Pin 10
Bounce key7 = Bounce(key7Pin, bounceTime);

#define key8Pin 12
Bounce key8 = Bounce(key8Pin, bounceTime);

byte out = 0b000000;

void printKeys()
{
  switch (out)
  {
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

void runKeys()
{
    if (key1.fallingEdge())
    {
       bitWrite(out, 5, 1);
    }

    if (key2.fallingEdge())
    {
      bitWrite(out, 4, 1);
    }

    if (key3.fallingEdge())
    {
      bitWrite(out, 3, 1);
    }

    if (key4.fallingEdge())
    {
      bitWrite(out, 2, 1);
    }

    if (key5.fallingEdge())
    {
      bitWrite(out, 1, 1);
    }

    if (key6.fallingEdge())
    {
      bitWrite(out, 0, 1);
    }

    if (key7.fallingEdge() || key8.fallingEdge())
      pressStart = millis();


    if (key7.risingEdge())
    {
      if(millis() - pressStart >= pressTime)
        Keyboard.write(KEY_TAB);
      else
        Keyboard.write(32);
    }

    if (key8.risingEdge())
    {
      if(millis() - pressStart >= pressTime)
        Keyboard.write(KEY_RETURN);
      else
        Keyboard.write(KEY_BACKSPACE);
    }

    if(key1.risingEdge() || key2.risingEdge() || key3.risingEdge() || key4.risingEdge() || key5.risingEdge() || key6.risingEdge())
    {
      Serial.println(out, BIN);
      printKeys();

      for(int i=0; i<6; i++)
        bitClear(out, i);
    }
}

#define key10_pin 11
Bounce key10 = Bounce(key10_pin, 10);

Encoder knob(2, 3);
long old_position  = -999;
bool hold;
bool wordSelect;

void runKnob()
{
  long new_position = knob.read() / 2;

  if (new_position != old_position)
  {
    if (new_position < old_position)
    {
      if(wordSelect)
      {
//        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ARROW);
        Keyboard.release(KEY_LEFT_ARROW);
        delay(100);
        Keyboard.release(KEY_LEFT_CTRL);
      }

      else
        Keyboard.write(KEY_LEFT_ARROW);
    }

    else if (new_position > old_position)
    {
      if(wordSelect)
      {
//        Keyboard.press(KEY_LEFT_ALT);

        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_RIGHT_ARROW);
        Keyboard.release(KEY_RIGHT_ARROW);
        delay(100);
        Keyboard.release(KEY_LEFT_CTRL);
      }

      else
        Keyboard.write(KEY_RIGHT_ARROW);
    }

    old_position = new_position;
  }

  if (key10.update())
  {
    if (key10.risingEdge())
    {
      if(wordSelect == true)
        wordSelect = false;
      else
        wordSelect = true;
    }
  }
}

void setup()
{
  pinMode(ledPin, OUTPUT);

  pinMode(key1Pin, INPUT_PULLUP);
  pinMode(key2Pin, INPUT_PULLUP);
  pinMode(key3Pin, INPUT_PULLUP);
  pinMode(key4Pin, INPUT_PULLUP);
  pinMode(key5Pin, INPUT_PULLUP);
  pinMode(key6Pin, INPUT_PULLUP);
  pinMode(key7Pin, INPUT_PULLUP);
  pinMode(key8Pin, INPUT_PULLUP);
  pinMode(key10_pin, INPUT_PULLUP);

  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);

  Keyboard.begin();
}
void loop()
{
  if(key1.update() || key2.update() || key3.update() || key4.update() || key5.update() || key6.update() || key7.update() || key8.update())
  {
    runKeys();
  }

  runKnob();
}

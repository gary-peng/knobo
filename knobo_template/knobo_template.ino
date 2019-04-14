#include <HID-Project.h>
#include <HID-Settings.h>
#include <Bounce2.h>
#include <Encoder.h>

#define led_pin 7

#define key1_pin 13
Bounce key1 = Bounce(key1_pin, 10);

#define key2_pin 5
Bounce key2 = Bounce(key2_pin, 10);

#define key3_pin 10
Bounce key3 = Bounce(key3_pin, 10);

#define key4_pin 9
Bounce key4 = Bounce(key4_pin, 10);

#define key5_pin 8
Bounce key5 = Bounce(key5_pin, 10);

#define key6_pin 12
Bounce key6 = Bounce(key6_pin, 10);

#define key7_pin 6
Bounce key7 = Bounce(key7_pin, 10);

#define key8_pin 4
Bounce key8 = Bounce(key8_pin, 10);

void run_keys()
{
  if (key1.update())
  {
    if (key1.fallingEdge())
    {
      // macro for key 1 goes here
      
    }
  }

  if (key2.update())
  {
    if (key2.fallingEdge())
    { 
      // macro for key 2 goes here
      
    }
  }

  if (key3.update())
  {
    if (key3.fallingEdge())
    {
      // macro for key 3 goes here
      
    }
  }

  if (key4.update())
  {
    if (key4.fallingEdge())
    {
      // macro for key 4 goes here
      
    }
  }


  if (key5.update())
  {
    if (key5.fallingEdge())
    {
      // macro for key 5 goes here
      
    }
  }

  if (key6.update())
  {
    if (key6.fallingEdge())
    {
      // macro for key 6 goes here
      
    }
  }

  if (key7.update())
  {
    if (key7.fallingEdge())
    {
      // macro for key 7 goes here
      
    }
  }

  if (key8.update())
  {
    if (key8.fallingEdge())
    {
      // macro for key 8 goes here
      
    }
  }
}

Encoder knob(2, 3);

#define key10_pin 11
Bounce key10 = Bounce(key10_pin, 10);

long old_position  = -999;

bool hold;

void run_knob()
{
  long new_position = knob.read() / 2;
  
  if (new_position != old_position)
  {
    if (new_position < old_position)
    {
      if (digitalRead(key10_pin) == LOW)
      {
        // macro for hold and turn counter clockwise goes here
        
        hold = true;
      }

      else
      {
        // macro for turn counter clockwise goes here
      }
    }

    else if (new_position > old_position)
    {
      if (digitalRead(key10_pin) == LOW)
      {
        // macro for hold and turn clockwise goes here

        hold = true;
      }

      else
      {
        // macro for turn clockwise goes here
        
      }
    }
    
    old_position = new_position;
  }

  if (key10.update())
  {
    if (key10.risingEdge())
    {
      if (hold == false)
      {
        // macro for knob press goes here
        
      }

      else
      {
        hold = false;    
      }  
    }
  }
}

void setup()
{
  pinMode(led_pin, OUTPUT);
  
  pinMode(key1_pin, INPUT_PULLUP);
  pinMode(key2_pin, INPUT_PULLUP);
  pinMode(key3_pin, INPUT_PULLUP);
  pinMode(key4_pin, INPUT_PULLUP);
  pinMode(key5_pin, INPUT_PULLUP);
  pinMode(key6_pin, INPUT_PULLUP);
  pinMode(key7_pin, INPUT_PULLUP);
  pinMode(key8_pin, INPUT_PULLUP);
  pinMode(key10_pin, INPUT_PULLUP);

  digitalWrite(led_pin, HIGH);
  delay(1000);
  digitalWrite(led_pin, LOW);

  Keyboard.begin();
}
void loop()
{
  run_keys();
  run_knob();
}

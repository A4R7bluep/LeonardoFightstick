/*
 * Pins are grounded when pressed
 * Pin A0 = UP
 * Pin A1 = DOWN
 * Pin A2 = LEFT
 * Pin A3 = RIGHT
 * 
 * Pin D2 = A
 * Pin D3 = B
 * Pin D4 = X
 * Pin D5 = Y
 * 
 * Pin D6 = Button 5
 * Pin D7 = Button 6
 * Pin D8 = Button 7
 * Pin D9 = Button 8
 * 
 * Pin D10 = Start
 * Pin D11 = Select
 */

#include <Joystick.h>

const uint8_t pins[14] = {A0, A1, A2, A3, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int stickX = 0;
int stickY = 0;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   10, 0,                 // Button Count, Hat Switch Count
                   true, true, false,     // X and Y, but no Z Axis
                   false, false, false,   // No Rx, Ry, or Rz
                   false, false,          // No rudder or throttle
                   false, false, false);  // No accelerator, brake, or steering

void setup()
  {
    Serial.begin(9600);

    // Initialize Button Pins
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);

    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);

    pinMode(6, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);

    pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);

    // Initialize Joystick Library
    Joystick.begin();
    Joystick.setXAxisRange(-1, 1);
    Joystick.setYAxisRange(-1, 1);
  }

void loop()
  {
    // Check pins
    for (int index = 0; index < 14; index++)
    {
      int currentState = !digitalRead(pins[index]);

      switch (index + 1)
      {
        // Analog / Stick pins
        case 1:
          if (currentState == 1)
          {
            stickY -= 1;
            Serial.println("UP");
          }
          // else
          // {
          //   Joystick.setYAxis(0);
          // }
          break;
        
        case 2:
          if (currentState == 1)
          {
            stickY += 1;
            Serial.println("DOWN");
          }
          // else
          // {
          //   Joystick.setYAxis(0);
          // }
          break;

        case 3:
          if (currentState == 1)
          {
            stickX -= 1;
            Serial.println("LEFT");
          }
          // else
          // {
          //   Joystick.setXAxis(0);
          // }
          break;
        
        case 4:
          if (currentState == 1)
          {
            stickX += 1;
            Serial.println("RIGHT");
          }
          // else
          // {
          //   Joystick.setXAxis(0);
          // }
          break;

        // Digital / Button pins
        case 5:
          if (currentState == 1)
          {
            Joystick.setButton(0, currentState);
            Serial.println("A");
          }
          else
          {
            Joystick.setButton(0, 0);
          }
          break;

        case 6:
          if (currentState == 1)
          {
            Joystick.setButton(1, currentState);
            Serial.println("B");
          }
          else
          {
            Joystick.setButton(1, 0);
          }
          break;
        
        case 7:
          if (currentState == 1)
          {
            Joystick.setButton(2, currentState);
            Serial.println("X");
          }
          else
          {
            Joystick.setButton(2, 0);
          }
          break;

        case 8:
          if (currentState == 1)
          {
            Joystick.setButton(3, currentState);
            Serial.println("Y");
          }
          else
          {
            Joystick.setButton(3, 0);
          }
          break;
        
        case 9:
          if (currentState == 1)
          {
            Joystick.setButton(4, currentState);
            Serial.println("Button 5");
          }
          else
          {
            Joystick.setButton(4, 0);
          }
          break;

        case 10:
        if (currentState == 1)
          {
            Joystick.setButton(5, currentState);
            Serial.println("Button 6");
          }
          else
          {
            Joystick.setButton(5, 0);
          }
          break;
        
        case 11:
        if (currentState == 1)
          {
            Joystick.setButton(6, currentState);
            Serial.println("Button 7");
          }
          else
          {
            Joystick.setButton(6, 0);
          }
          break;

        case 12:
          if (currentState == 1)
          {
            Joystick.setButton(7, currentState);
            Serial.println("Button 8");
          }
          else
          {
            Joystick.setButton(7, 0);
          }
          break;
        
        case 13:
          if (currentState == 1)
          {
            Joystick.setButton(9, currentState);
            Serial.println("Start");
          }
          else
          {
            Joystick.setButton(9, 0);
          }
          break;
        
        case 14:
          if (currentState == 1)
          {
            Joystick.setButton(10, currentState);
            Serial.println("Select");
          }
          else
          {
            Joystick.setButton(10, 0);
          }
          break;

        default:
          Serial.println("Wildcard activated");
          break;
      }
    }

    if (stickX > 0)
    {
      stickX = min(stickX, 1);
    }
	  else if (stickX < 0)
    {
      stickX = max(stickX, -1);
    }

    if (stickY > 0)
    {
      stickY = min(stickY, 1);
    }
	  else if (stickX < 0)
    {
      stickY = max(stickY, -1);
    }

    Joystick.setXAxis(stickX);
    Joystick.setYAxis(stickY);

    stickX = 0;
    stickY = 0;

    //delay(10);
  }


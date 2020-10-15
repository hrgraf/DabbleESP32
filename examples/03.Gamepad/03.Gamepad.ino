/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

static bool logging = true;
static long last_ms = 0;
static int num_run = 0, num_updates = 0;
static float last_x = 0, last_y = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Serial.println("Dabble Gamepad Demo");

  Dabble.begin("MyEsp32");       //set bluetooth name of your device

  Serial.println("Wait for Dabble app connection");
  Dabble.waitForAppConnection();
  Serial.println("Connected!");

  last_ms = millis();
}

void loop() 
{
  Dabble.processInput();
  if (! Dabble.isAppConnected())
  {
    Serial.println("Not connected");
    Dabble.delay(4000);
    last_ms = millis();
    return;
  }

  byte scr = Dabble.getScreenId();
  byte mod = Dabble.readModuleId();

  if (logging)
  {
    Serial.print("Module: ");
    Serial.print(mod);
    Serial.print(", Screen: ");
    Serial.print(scr);
  }

  if (mod != GAMEPAD_ID)
  {
    Serial.println(", not Gamepad\n");
    Dabble.delay(4000);
    last_ms = millis();
    return;
  }

  num_run++;

  int   a = GamePad.getAngle();
  int   r = GamePad.getRadius();
  float x = GamePad.getXaxisData();
  float y = GamePad.getYaxisData();

  if ((x != last_x) || (y != last_y))
    num_updates++;

  if (logging)
  {
      Serial.print(", Pressed: ");
      if (GamePad.isUpPressed())
      {
        Serial.print("Up");
      }

      if (GamePad.isDownPressed())
      {
        Serial.print("Down");
      }

      if (GamePad.isLeftPressed())
      {
        Serial.print("Left");
      }

      if (GamePad.isRightPressed())
      {
        Serial.print("Right");
      }

      if (GamePad.isSquarePressed())
      {
        Serial.print("Square");
      }

      if (GamePad.isCirclePressed())
      {
        Serial.print("Circle");
      }

      if (GamePad.isCrossPressed())
      {
        Serial.print("Cross");
      }

      if (GamePad.isTrianglePressed())
      {
        Serial.print("Triangle");
      }

      if (GamePad.isStartPressed())
      {
        Serial.print("Start");
      }

      if (GamePad.isSelectPressed())
      {
        Serial.print("Select");
      }

      Serial.print(", Angle: ");
      Serial.print(a);
      Serial.print(", Radius: ");
      Serial.print(r);
      Serial.print(", X: ");
      Serial.print(x);
      Serial.print(", Y: ");
      Serial.print(y);

      Serial.println();

      Dabble.delay(1000); // ms
  }
  else
  {
    long ms = millis();
    if (ms - last_ms >= 1000)
    {
        Serial.printf("Run %d times per second with %d updates\n", num_run, num_updates);
        num_run = num_updates = 0;
        last_ms += 1000;
    }
  }
  
  last_x = x;
  last_y = y;
}

/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Serial.println("Dabble Gamepad Demo");

  Dabble.begin("MyEsp32");       //set bluetooth name of your device

  Serial.println("Wait for Dabble app connection");
  Dabble.waitForAppConnection();
  Serial.println("Connected!");
}

void loop() 
{
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  if (! Dabble.isAppConnected())
  {
    Serial.println("Not connected");
    Dabble.delay(4000);
    return;
  }

  byte scr = Dabble.getScreenId();
  byte mod = Dabble.readModuleId();
  Serial.print("Module: ");
  Serial.print(mod);
  Serial.print(", Screen: ");
  Serial.print(scr);

  if (mod != GAMEPAD_ID)
  {
    Serial.println(", not Gamepad\n");
    Dabble.delay(4000);
    return;
  }

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
  Serial.print(", ");

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print(", ");
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print(", ");
  float c = GamePad.getXaxisData();
  Serial.print("X: ");
  Serial.print(c);
  Serial.print(", ");
  float d = GamePad.getYaxisData();
  Serial.print("Y: ");
  Serial.println(d);
  //Serial.println();

  Dabble.delay(1000); // ms
}

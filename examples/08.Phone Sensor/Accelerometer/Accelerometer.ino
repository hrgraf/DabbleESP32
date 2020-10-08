/*
   Accelerometer block of Phone sensor module allows you to access your smartphone's accelerometer values.

   You can reduce the size of library compiled by enabling only those modules that you wan to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/phone-sensors-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_SENSOR_MODULE
#include <DabbleESP32.h>


void setup() 
{
  Serial.begin(115200);    // make sure your Serial Monitor is also set at this baud rate.
  Serial.println("Dabble Phone Accelerometer Demo");

  Dabble.begin("MyEsp32");   //set bluetooth name of your device

  Serial.println("Wait for Dabble app connection");
  Dabble.waitForAppConnection();
  Serial.println("Connected!");
}

void loop() 
{
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  print_Accelerometer_data();
}

void print_Accelerometer_data()
{
  Serial.print("X: ");
  Serial.print(Sensor.getAccelerometerXaxis(), 4);
  Serial.print(", ");
  Serial.print("Y: ");
  Serial.print(Sensor.getAccelerometerYaxis(), 4);
  Serial.print(", ");
  Serial.print("Z: ");
  Serial.print(Sensor.getAccelerometerZaxis(), 4);
  Serial.println();
}

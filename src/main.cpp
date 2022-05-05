// Import required libraries
#include <LittleFS.h>
#include <FS.h>
#include "route.h"
#include "wifi.h"

const char* feedBarChart() {
  const char s[] PROGMEM =  R"=====(
    asdasd
  )=====";
  return s;
}

void setup()
{
  Serial.begin(115200);
  blockingWifiConnection(SSID, PASSWORD);
  runServer(80);
}

void loop()
{
  delay(1000);
  long randNumber; 
  randNumber = random(300) % 300;
  Serial.println(String(randNumber));
}

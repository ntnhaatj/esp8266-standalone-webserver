#include "route.h"

// Replaces placeholder with LED state value
String processor(const String &var)
{
  static String ledState;
  if (var == "GPIO_STATE")
  {
    if (digitalRead(LED_PIN))
    {
      ledState = "OFF";
    }
    else
    {
      ledState = "ON";
    }
    Serial.print(ledState);
    return ledState;
  }
  return String();
}

void initLocalStatic()
{
  // Initialize LittleFS
  if (!LittleFS.begin())
  {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }
}

void setRoutes(AsyncWebServer *server)
{
  // Route for root / web page
  server->on("/", HTTP_GET, [](AsyncWebServerRequest *request)
             { request->send(LittleFS, "/index.html", String(), false, processor); });

  // Routes to load local static files
  server->on("/chart.js", HTTP_GET, [](AsyncWebServerRequest *request)
             { request->send(LittleFS, "/chart.js", "text/javascript"); });

  server->on("/me.js", HTTP_GET, [](AsyncWebServerRequest *request)
             { request->send(LittleFS, "/me.js", "text/javascript"); });

  server->on("/barchart.js", HTTP_GET, [](AsyncWebServerRequest *request)
             { request->send(LittleFS, "/barchart.js", "text/javascript"); });
}

void initServer(AsyncWebServer *server) {
  setRoutes(server);
  pinMode(LED_PIN, OUTPUT);
  initLocalStatic();
}

AsyncWebServer* runServer(uint16_t port) {
  AsyncWebServer* server = new AsyncWebServer(port);

  initServer(server);
  server->begin();
  return server;
}

#include "wifi.h"


int blockingWifiConnection(const char *pSsid, const char *pPassphrase)
{
    // Connect to Wi-Fi
    WiFi.begin(pSsid, pPassphrase);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }

    // Print ESP32 Local IP Address
    Serial.println(WiFi.localIP());
    return 1;
}

int wifiConnection()
{
    return 1;
}

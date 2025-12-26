#include <Arduino.h>
#include <WiFi.h>
#include <MoonPhase.hpp>

const char *wifissid = "network name";
const char *wifipsk = "network password";

MoonPhase moonPhase;

struct tm timeinfo{};

void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println();
    Serial.println("moonPhase esp32-sntp example.");
    Serial.print("Connecting to ");
    Serial.println(wifissid);
    WiFi.begin(wifissid, wifipsk);
    while (!WiFi.isConnected())
        delay(10);
    Serial.println();

    Serial.println("Connected. Syncing NTP...");

    // find your local timezone string at  
    // https://remotemonitoringsystems.ca/time-zone-abbreviations.php

    // timezone: Amsterdam, Netherlands
    const char timeZone[]{"CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00"}; 

    const char countryCode[]{"nl"};

    char ntpPool[64];
    snprintf(ntpPool, sizeof(ntpPool), "%s.pool.ntp.org", countryCode);

    configTzTime(timeZone, ntpPool); 

    while (!getLocalTime(&timeinfo, 0))
        delay(10);
}

void loop()
{
    getLocalTime(&timeinfo);
    Serial.print(asctime(&timeinfo));

    moonData_t moon = moonPhase.getPhase();

    Serial.print("Moon phase angle: ");
    Serial.print(moon.angleDeg); // angleDeg is a integer between 0-360
    Serial.println("° (Where 0° is new moon and 180° is full moon)");

    Serial.print("Illuminated: ");
    Serial.print(moon.amountLit * 100); // amountlit is a real between 0-1
    Serial.println("% as seen from Earth");
    Serial.println();
    delay(1000);
}

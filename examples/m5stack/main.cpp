#include <Arduino.h>
#include <SD.h>
#include <M5Unified.h>
#include <WiFi.h>
#include <time.h>
#include <MoonPhase.hpp>

constexpr const char *WIFI_SSID{"network name"};
constexpr const char *WIFI_PASS{"network pass"};

// timezone: Amsterdam, Netherlands
constexpr const char *TZ_INFO{"CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00"};
// find your local timezone string at
// https://remotemonitoringsystems.ca/time-zone-abbreviations.php

MoonPhase moonPhase;

void waitForTime()
{
    configTzTime(TZ_INFO, "pool.ntp.org");

    struct tm timeinfo{};
    while (!getLocalTime(&timeinfo))
    {
        Serial.println("Waiting for SNTP...");
        delay(10);
    }
}

void drawMoonImage(int angle)
{
    char path[32];
    snprintf(path, sizeof(path), "/images/%03d.png", angle);

    if (!M5.Display.drawPngFile(SD, path, 0, 0))
    {
        Serial.printf("Failed to draw %s\n", path);
    }
}

void setup()
{
    auto cfg = M5.config();
    cfg.clear_display = true;
    cfg.internal_imu = false;
    cfg.internal_rtc = true;
    cfg.internal_spk = false;

    M5.begin(cfg);

    Serial.begin(115200);
    Serial.println("MoonPhase M5Stack example");

    if (!SD.begin(4))
    {
        Serial.println("SD card mount failed");
        while (true)
            delay(1000);
    }

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(10);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");

    waitForTime();
}

void loop()
{
    struct tm now;
    getLocalTime(&now);

    moonData_t moon = moonPhase.getPhase();

    Serial.printf(
        "Moon angle: %lu°, illuminated: %.1f%%\n",
        moon.angleDeg,
        moon.amountLit * 100.0f);

    drawMoonImage(moon.angleDeg);

    char buffer[6]; // "HH:MM"
    strftime(buffer, sizeof(buffer), "%H:%M", &now);

    M5.Display.setTextColor(TFT_WHITE);
    M5.Display.setTextDatum(CC_DATUM);
    M5.Display.drawCenterString(buffer, M5.Display.width() / 2, M5.Display.height() / 2, &DejaVu24);

    delay(60 * 1000);
}

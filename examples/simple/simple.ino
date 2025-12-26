#include <Arduino.h>
#include <MoonPhase.hpp>

MoonPhase moonPhase; // include a MoonPhase instance
moonData_t moon;     // variable to receive the data

void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println("moonPhase simple example.");

    moon = moonPhase.getPhase(); // gets the current moon phase ( 1/1/1970 at 00:00:00 UTC )

    Serial.print("Moon phase angle: ");
    Serial.print(moon.angleDeg); // angleDeg is a integer between 0-360
    Serial.println("° (Where 0° is new moon and 180° is full moon)");

    Serial.print("Illuminated: ");
    Serial.print(moon.amountLit * 100); // amountlit is a real between 0-1
    Serial.println("% as seen from Earth");
    Serial.println();
}

void loop()
{
    // put your main code here, to run repeatedly:
}

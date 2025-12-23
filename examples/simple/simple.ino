#include <Arduino.h>
#include <moonPhase.h>

MoonPhase moonPhase; // include a MoonPhase instance
moonData_t moon;     // variable to receive the data

void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println("moonPhase simple example.");

    moon = moonPhase.getPhase(); // gets the current moon phase ( 1/1/1970 at 00:00:00 UTC )

    Serial.print("Moon phase angle: ");
    Serial.print(moon.angleDeg); // angle is a integer between 0-360
    Serial.println(" degrees.");
    Serial.print("Moon surface fraction lit: ");
    Serial.print(moon.amountLit); // amountLit is a real between 0-1
}

void loop()
{
    // put your main code here, to run repeatedly:
}

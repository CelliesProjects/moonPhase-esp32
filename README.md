### moonPhase

A library for esp32 to get the moon phase angle and percentage of the moon that is illuminated. (as seen from Earth)  
The easiest method to install this library is to use the Arduino IDE library manager. 

For esp8266 non-os or avr (Arduino) you can use the [steve-sienk fork](https://github.com/steve-sienk/moonPhaser-avr).

#### Add to PlatformIO project

```c++
lib_deps = celliesprojects/moonPhase-esp32@^2.0.0
```

#### Functions

- `getPhase()` Get the current moon phase. (First set freeRTOS system time - see the esp32-sntp example)  
- `getPhase( time_t t )` Get the moon phase at time `t`.  

#### Example code

```c++
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
    Serial.print("Moon surface amount lit: ");
    Serial.print(moon.amountLit); // amountLit is a real between 0-1
}

void loop()
{
    // put your main code here, to run repeatedly:
}
```

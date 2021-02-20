[![Codacy Badge](https://api.codacy.com/project/badge/Grade/8bc0dca32db84bb5a3b762be8d48d2b3)](https://www.codacy.com/manual/CelliesProjects/moonPhase?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=CelliesProjects/moonPhase&amp;utm_campaign=Badge_Grade)
### moonPhase

A library for esp32 to get the moon phase angle and percentage of the moon that is illuminated. (as seen from Earth)
<br>Preferred methods to install is to use the Arduino IDE library manager. 

For esp8266 non-os or avr (Arduino) you can use the [steve-sienk fork](https://github.com/steve-sienk/moonPhaser-avr).


#### Manual install

1. Download the latest release and unpack in the Arduino `libraries` folder.
2. Restart the Arduino IDE.

#### Functions

- `getPhase()` Get the current moon phase. (First set freeRTOS system time - see the esp32-sntp example)

- `getPhase( time_t t )` Get the moon phase as it was at time `t`.

#### Example code

```c++
#include <moonPhase.h>

moonPhase moonPhase;                       // include a MoonPhase instance

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println( "moonPhase simple example." );

  moonData_t moon;                        // variable to receive the data

  moon = moonPhase.getPhase();            // gets the current moon phase ( 1/1/1970 at 00:00:00 UTC )

  Serial.print( "Moon phase angle: " );
  Serial.print( moon.angle );             // angle is a integer between 0-360
  Serial.println( " degrees." );
  Serial.print( "Moon surface lit: " );
  Serial.print( moon.percentLit * 100 );  // percentLit is a real between 0-1
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

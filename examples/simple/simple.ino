#include "MoonPhase.h"

const int year = 2018;
const int month = 4;
const int day = 4;
const float hour = 22.5; /* 22:30 */

MoonPhase MoonPhase; /* include a MoonPhase instance */

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println( "MoonPhase simple example." );

  MoonPhase::moonData moon; /* variable to receive the data */

  moon = MoonPhase.getInfo( year, month, day, hour );

  Serial.print( "Moon phase angle: " );
  Serial.print( moon.angle );
  Serial.println( " degrees." );
  Serial.print( "Moon surface lit: " );
  Serial.print( moon.percentLit );
  Serial.println( "%." );
}

void loop() {
  // put your main code here, to run repeatedly:

}

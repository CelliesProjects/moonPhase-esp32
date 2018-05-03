#include "MoonPhase.h"

const int year = 2018;
const int month = 4;
const int day = 12;
const double hour = 22.50; /* 22:30 */

MoonPhase MoonPhase; /* include a MoonPhase instance */

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println( "MoonPhase simple example." );

  MoonPhase::moonData moon; /* variable to receive the data */

  moon = MoonPhase.getInfo( year, month, day, hour );

  Serial.print( "Moon phase angle: " );
  Serial.print( moon.angle );                       /* angle is a integer between 0-360  */
  Serial.println( " degrees." );
  Serial.print( "Moon surface lit: " );
  Serial.printf( "%.0f%%", moon.percentLit * 100 ); /* percentLit is a real between 0-1  */
}

void loop() {
  // put your main code here, to run repeatedly:

}

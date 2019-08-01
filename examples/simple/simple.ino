#include <moonPhase.h>

moonPhase moonPhase; // include a MoonPhase instance

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

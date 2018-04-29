/*
  MoonPhase.h - Library to get moon phase angle 
  and percentage illuminated. (as seen from Earth)
  Created by Marcel Timmer, April 28, 2018.
  Code adapted from http://www.voidware.com/phase.c
  A big thanks to Hugh at voidware from granting permission.
  Released under MIT license.
*/
#ifndef MoonPhase_h
#define MoonPhase_h

#include "Arduino.h"

class MoonPhase
{
  public:

    struct moonData
    {
      int angle;
      float percentLit;
    };

    moonData getInfo( const int year, const int month, const int day, const double hour );

  private:

    double _Julian( int year, int month, double day );

    double _sun_position( const double j );

    double _moon_position( double j, double ls );
};
#endif

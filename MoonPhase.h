/*
  MoonPhase.h - Library to get moon phase angle 
  and percentage illuminated. (as seen from Earth)
  Created by Marcel Timmer, April 28, 2018.
  Code adapted from http://www.voidware.com/phase.c
  A big thanks to Hugh at voidware for granting permission.
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
      int32_t angle;
      double percentLit;
    };

    moonData getInfo( const int32_t year, const int32_t month, const int32_t day, const double hour );

  private:

    double _Julian( int32_t year, int32_t month, double day );

    double _sun_position( const double j );

    double _moon_position( double j, double ls );
};
#endif

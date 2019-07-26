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

struct moonData_t
{
  int32_t angle;
  double  percentLit;
};

class moonPhase
{
public:
  moonData_t getPhase();
  moonData_t getPhase( const time_t t );
private:
  moonData_t _getPhase( const int32_t &year, const int32_t &month, const int32_t &day, const double &hour );
  double     _fhour( const struct tm &timeinfo );
  double     _Julian( int32_t year, int32_t month, const double &day );
  double     _sun_position( const double &j );
  double     _moon_position( const double &j, const double &ls );
};
#endif

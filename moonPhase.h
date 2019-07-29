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
  moonData_t getPhase(){ return getPhase( time(NULL) ); };
  moonData_t getPhase( const time_t t );
};
#endif

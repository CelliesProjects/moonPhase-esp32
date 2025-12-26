/*
  MoonPhase.hpp - Library to get moon phase angle
  and amount illuminated. (as seen from Earth)
  Created by Marcel Timmer, April 28, 2018.
  Code adapted from http://www.voidware.com/phase.c
  A big thanks to Hugh at voidware for granting permission.
  Released under MIT license.
*/
#ifndef MoonPhase_hpp
#define MoonPhase_hpp

#include <Arduino.h>

struct moonData_t
{
    int32_t angleDeg;
    double amountLit;
};

class MoonPhase
{
public:
    moonData_t getPhase(const time_t t)
    {
        struct tm timeinfo;
        gmtime_r(&t, &timeinfo);
        return _getPhase(1900 + timeinfo.tm_year, 1 + timeinfo.tm_mon, timeinfo.tm_mday, _fhour(timeinfo));
    }

    moonData_t getPhase()
    {
        return getPhase(time(NULL));
    }

private:
    double _fhour(const struct tm &timeinfo);
    moonData_t _getPhase(const int32_t year, const int32_t month, const int32_t day, const double &hour);
};
#endif

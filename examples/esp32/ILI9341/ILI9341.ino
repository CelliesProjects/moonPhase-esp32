/*
  // Creative commons pics? https://commons.wikimedia.org/wiki/User:JayTanner/lunar-near-side-phase-set

  // pics: http://neoprogrammics.com/moon/
*/
#include "MoonPhase.h"
#include "WiFi.h"
#include "Adafruit_ILI9341.h"

#define SPI_TFT_DC_PIN            27  // Goes to TFT DC
#define SPI_SCK_PIN               25  // Goes to TFT SCK/CLK
#define SPI_MOSI_PIN              32  // Goes to TFT MOSI
#define SPI_TFT_RST_PIN           12  // Goes to TFT RESET
#define SPI_TFT_CS_PIN             4  // Goes to TFT CS
#define SPI_MISO_PIN              14  // Goes to TFT MISO

#define TFT_BACKLIGHT_PIN          2

#include "phases/phase_000.c"
#include "phases/phase_015.c"
#include "phases/phase_030.c"
#include "phases/phase_045.c"
#include "phases/phase_060.c"
#include "phases/phase_075.c"
#include "phases/phase_090.c"
#include "phases/phase_105.c"
#include "phases/phase_120.c"
#include "phases/phase_135.c"
#include "phases/phase_150.c"
#include "phases/phase_165.c"
#include "phases/phase_180.c"
#include "phases/phase_195.c"
#include "phases/phase_210.c"
#include "phases/phase_225.c"
#include "phases/phase_240.c"
#include "phases/phase_255.c"
#include "phases/phase_270.c"
#include "phases/phase_285.c"
#include "phases/phase_300.c"
#include "phases/phase_315.c"
#include "phases/phase_330.c"
#include "phases/phase_345.c"
#include "phases/phase_360.c"

const char* wifi_sid = "..........";
const char* wifi_psk = "..........";

MoonPhase MoonPhase;

Adafruit_ILI9341 tft = Adafruit_ILI9341( SPI_TFT_CS_PIN, SPI_TFT_DC_PIN, SPI_TFT_RST_PIN );

void setup()
{
  Serial.begin( 115200 );

  SPI.begin( SPI_SCK_PIN, SPI_MISO_PIN, SPI_MOSI_PIN );

  tft.begin( 10000000, SPI );

  pinMode( TFT_BACKLIGHT_PIN, OUTPUT );
  digitalWrite( TFT_BACKLIGHT_PIN, HIGH );
  tft.setTextColor( ILI9341_WHITE, ILI9341_BLACK );
  tft.fillScreen( ILI9341_BLACK );
  tft.setRotation( 3 );
  tft.setCursor( 110, 0);
  tft.println( "MoonPhase" );

  Serial.printf( "Connecting to '%s' with psk '%s'\n" , wifi_sid, wifi_psk );

  WiFi.begin( wifi_sid, wifi_psk );

  uint32_t timeout = millis() + 5000;
  while ( !WiFi.isConnected() && millis() - timeout > 0 )
  {
    Serial.print( "." );
    delay( 500 );
  }
  Serial.println();
  Serial.println( "Connected." );


  if ( WiFi.status() != WL_CONNECTED )
  {
    tft.setCursor( 80, 180 );
    tft.println( "WiFi not connected." );
    tft.setCursor( 50, 200 );
    tft.printf( "SSID: %s PSK: %s", wifi_sid, wifi_psk );
  }
  else
  {
    configTzTime( "UTC", "0.pool.ntp.org", "1.pool.ntp.org" );    
  }
}

void loop()
{
  time_t now;
  time( &now );
  struct tm timeinfo;
  gmtime_r( &now, &timeinfo ); /* moon phase is calculated using UTC! */

  double hourSecondPrecision = timeinfo.tm_hour + mapFloat( ( timeinfo.tm_min * 60 ) + timeinfo.tm_sec, 1, 3600, 0, 1 );

  MoonPhase::moonData moon = MoonPhase.getInfo( 1900 + timeinfo.tm_year,
                             timeinfo.tm_mon + 1,
                             timeinfo.tm_mday,
                             hourSecondPrecision );
  static int previousAngle;

  if ( previousAngle != moon.angle )
  {
    showMoonTft( moon.angle );
    previousAngle = moon.angle;  
  }

  tft.setCursor( 20, 120 );
  tft.printf( "%i%c %s UTC", moon.angle, char(247), asctime( &timeinfo ) );
  tft.setCursor( 120, 105 );
  tft.printf( "%.4f%%", moon.percentLit * 100 );

  delay( 1000 );
}

float mapFloat( float x, const float in_min, const float in_max, const float out_min, const float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void showMoonTft(  uint16_t phase )
{
  // see example sketch .../Arduino/libraries/AdaFruit_ILI9341/examples/pictureEmbed

  phase = ( phase / 15 ) * 15;  /* only 1 on 15 'frames' really exists */

  switch ( phase)  {
    case 0: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_000.pixel_data, 80, 80);
      break;
    case 15: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_015.pixel_data, 80, 80);
      break;
    case 30: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_030.pixel_data, 80, 80);
      break;
    case 45: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_045.pixel_data, 80, 80);
      break;
    case 60: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_060.pixel_data, 80, 80);
      break;
    case 75: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_075.pixel_data, 80, 80);
      break;
    case 90: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_090.pixel_data, 80, 80);
      break;
    case 105: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_105.pixel_data, 80, 80);
      break;
    case 120: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_120.pixel_data, 80, 80);
      break;
    case 135: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_135.pixel_data, 80, 80);
      break;
    case 150: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_150.pixel_data, 80, 80);
      break;
    case 165: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_165.pixel_data, 80, 80);
      break;
    case 180: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_180.pixel_data, 80, 80);
      break;
    case 195: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_195.pixel_data, 80, 80);
      break;
    case 210: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_210.pixel_data, 80, 80);
      break;
    case 225: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_225.pixel_data, 80, 80);
      break;
    case 240: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_240.pixel_data, 80, 80);
      break;
    case 255: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_255.pixel_data, 80, 80);
      break;
    case 270: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_270.pixel_data, 80, 80);
      break;
    case 285: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_285.pixel_data, 80, 80);
      break;
    case 300: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_300.pixel_data, 80, 80);
      break;
    case 315: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_315.pixel_data, 80, 80);
      break;
    case 330: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_330.pixel_data, 80, 80);
      break;
    case 345: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_345.pixel_data, 80, 80);
      break;
    case 360: tft.drawRGBBitmap( 100, 20, (uint16_t *)phase_360.pixel_data, 80, 80);
      break;
    default:
      Serial.printf( "showMoonTft - unexpected phase %i\n", phase );
      break;
  }
}

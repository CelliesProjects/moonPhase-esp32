# MoonPhase

An Arduino library to get the moon phase angle and percentage of the moon that is illuminated.

## Usage:

1. Download the latest release and unpack in the Arduino `libraries` folder.
2. Restart the Arduino IDE.

A simple example that should run on most Arduino IDE supported boards is included.

A more elaborate example only suitable for an ESP32 with an ILI9341 tft display can be found in the `esp32/ILI9341` folder.

## Issues:

Precision will be smaller on 8 bit Arduino boards, as these have no real `double` data type available.

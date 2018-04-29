## MoonPhase

A simple POC to show the moonphases on a ILI9341 tft board as an series of bitmap images stored in the flash rom.

### Hardware

- ESP32

- SPI ILI9341 320x240 tft board ( some come included with a SD card reader )

### Software

- The latest version Arduino IDE.

- You will need to install the [Adafruit ILI9341 library](https://github.com/adafruit/Adafruit_ILI9341).
<br>Just use the one from the Arduino IDE.
<br>Go to `Include library -> Manage libraries` and search for `adafruit 9341`.
<br>Install the latest version.

### Lunar images license:

Lunar Images Rendered by Jay Tanner Using POV-Ray and obtained from [http://neoprogrammics.com/pov-ray_lunar_explorer/](http://neoprogrammics.com/pov-ray_lunar_explorer/)

Unless otherwise indicated, all rendered images are released under the provisions of the Creative Commons Attribution-ShareAlike 4.0 International license.
<br>[creative commons legalcode](https://creativecommons.org/licenses/by-sa/4.0/legalcode)

The original renders can be found on [http://neoprogrammics.com/pov-ray_lunar_explorer/](http://neoprogrammics.com/pov-ray_lunar_explorer/)

### Convert to bmp

The png renders were converted to bmp with [gimp](https://www.gimp.org/) and [David's batch processor](http://members.ozemail.com.au/~hodsond/dbp.html).

In Linux Mint you can install both with the following command:

    sudo apt-get install gimp gimp-plugin-registry

Batch processing can be found in gimp menu:

    Filters->Batch->Batch process

### Convert images to .c file

Converting from `*.bmp` to `*.c` can be done with [gimp](https://www.gimp.org/).

1. `File -> Export As`<br>Make sure to save in the `phases` subfolder.

2. In Export Image dialog, use `C source code (*.c)` as filetype.

3. Press export to get the export options dialog.

4. Type the desired variable name into the `prefixed name` box.

5. Uncheck `GLIB types (guint8*)`

6. Check `Save as RGB565 (16-bit)`

7. Press export to save your image.

Assuming `image_name` was typed in the `prefixed name` box of step 4, and you included the c file, then the image can be used with:

    tft.drawRGBBitmap(0, 0, (uint16_t *)image_name.pixel_data, image_name.width, image_name.height);

See also [https://forum.pjrc.com/threads/35575-Export-for-ILI9341_t3-with-GIMP](https://forum.pjrc.com/threads/35575-Export-for-ILI9341_t3-with-GIMP)


# SNES Controller to XInput Converter for Arduino Leonardo(Pro Micro)

## overview
-This is a sketch of a converter that connects a Super Nintendo (SFC/SNES) gamepad to an Arduino Leonardo-compatible Pro Micro microcontroller board via USB as an XInput device.
- https://github.com/ka-zuu/snes_gamepad_arduino This is a modified version that uses the Arduino XInput Library.

## Note
- To use the Arduino XInput Library, you need the XInput USB Core for Arduino AVR
- For details, see the Arduino XInput Library documentation
- You must select "Arduino Leonardo w/XInput" as the board to be written to
- After writing to the device once, you must reset it if you want to write again
- For Pro Micro compatible boards that do not have a reset button, you can reset it by shorting GND and RST twice when writing starts after compilation (when Uploading... is displayed)

## References
- https://zenn.dev/kazuu/articles/560c403d5be17a
- snes_gamepad_arduino
- https://github.com/ka-zuu/snes_gamepad_arduino
- ArduinoXInput
- https://github.com/dmadison/ArduinoXInput
  
## 謝辞
本ソースコードはkazuu氏による記事 https://zenn.dev/kazuu/articles/560c403d5be17a をベースにArduino XInput Libraryを使用するように改修したものです。
記事を執筆及びスケッチを作成されたkazuu氏及びArduino XInput Libraryの作者Dave Madison氏に感謝いたします。

## Acknowledgements
This source code is based on the article by kazuu https://zenn.dev/kazuu/articles/560c403d5be17a and has been modified to use the Arduino XInput Library.
We would like to thank kazuu for writing the article and creating the sketch, and Dave Madison, the author of the Arduino XInput Library.


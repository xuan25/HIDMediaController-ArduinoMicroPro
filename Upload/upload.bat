@echo off
set/p PORT=<port.txt
supports\avrdude -C supports\avrdude.conf -v -p atmega32u4 -c avr109 -P %PORT% -b 57600 -D -U flash:w:supports\MediaController.hex:i
pause >nul

all : firmware.hex
	@true

main.o : main.cpp
	@echo [93mmain.cpp[0m
	avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 \
	-I/usr/share/arduino/hardware/arduino/cores/arduino \
	-ffunction-sections -fdata-sections -g -Os -w \
	-I/usr/share/arduino/hardware/arduino/variants/standard \
	-I/usr/share/arduino/hardware/arduino/cores/arduino \
	-fno-exceptions  -o $@ -c main.cpp

motordriver_4wd.o : motordriver_4wd.cpp
	@echo [93mmotordriver_4wd.cpp[0m
	avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c motordriver_4wd.cpp

seeed_pwm.o : seeed_pwm.cpp
	@echo [93msrc/seeed_pwm.cpp[0m
	avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c seeed_pwm.cpp

uart.o : uart.c
	@echo [93msrc/uart.cpp[0m
	avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 \
	-I/usr/share/arduino/hardware/arduino/cores/arduino \
	-ffunction-sections -fdata-sections -g -Os -w \
	-I/usr/share/arduino/hardware/arduino/variants/standard \
	-I/usr/share/arduino/hardware/arduino/cores/arduino \
	-fno-exceptions -o $@ -c uart.c

motorDriverDemo.o : motorDriverDemo.cpp
	@echo [93mmotorDriverDemo.cpp[0m
	avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions -iquote src  -o $@ -c motorDriverDemo.cpp
#include .build/pro5v328/src/motorDriverDemo.d

firmware.elf : main.o motordriver_4wd.o seeed_pwm.o motorDriverDemo.o uart.o
	@echo [92mLinking firmware.elf[0m
	avr-gcc -mmcu=atmega328p -Wl,-Os -Wl,--gc-sections -o $@ $^

firmware.hex : firmware.elf
	@echo [92mConverting to firmware.hex[0m
	avr-objcopy -O ihex -R .eeprom $^ $@

upload : firmware.hex
	@echo [92mDummy flash uploading to target[0m
	avrdude -C /usr/share/arduino/hardware/tools/avrdude.conf -p atmega328p -P /dev/ttyUSB0 -c arduino -b 57600 -D -U flash:w:firmware.hex:i

clean :
	@echo [92mCleaning directory...[0m
	rm -f *.o *.hex *.elf





















.build/pro5v328/arduino/WInterrupts.o : /usr/share/arduino/hardware/arduino/cores/arduino/WInterrupts.c
	@echo [93marduino/WInterrupts.c[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/WInterrupts.c
include .build/pro5v328/arduino/WInterrupts.d

.build/pro5v328/arduino/wiring_digital.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring_digital.c
	@echo [93marduino/wiring_digital.c[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring_digital.c
include .build/pro5v328/arduino/wiring_digital.d

.build/pro5v328/arduino/wiring_analog.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring_analog.c
	@echo [93marduino/wiring_analog.c[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring_analog.c
include .build/pro5v328/arduino/wiring_analog.d

.build/pro5v328/arduino/wiring_shift.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring_shift.c
	@echo [93marduino/wiring_shift.c[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring_shift.c
include .build/pro5v328/arduino/wiring_shift.d

.build/pro5v328/arduino/wiring_pulse.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring_pulse.c
	@echo [93marduino/wiring_pulse.c[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring_pulse.c
include .build/pro5v328/arduino/wiring_pulse.d

.build/pro5v328/arduino/wiring.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring.c
	@echo [93marduino/wiring.c[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring.c
include .build/pro5v328/arduino/wiring.d






.build/pro5v328/arduino/WMath.o : /usr/share/arduino/hardware/arduino/cores/arduino/WMath.cpp
	@echo [93marduino/WMath.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/WMath.cpp
include .build/pro5v328/arduino/WMath.d

.build/pro5v328/arduino/WString.o : /usr/share/arduino/hardware/arduino/cores/arduino/WString.cpp
	@echo [93marduino/WString.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/WString.cpp
include .build/pro5v328/arduino/WString.d

.build/pro5v328/arduino/Print.o : /usr/share/arduino/hardware/arduino/cores/arduino/Print.cpp
	@echo [93marduino/Print.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/Print.cpp
include .build/pro5v328/arduino/Print.d

.build/pro5v328/arduino/main.o : /usr/share/arduino/hardware/arduino/cores/arduino/main.cpp
	@echo [93marduino/main.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/main.cpp
include .build/pro5v328/arduino/main.d

.build/pro5v328/arduino/HID.o : /usr/share/arduino/hardware/arduino/cores/arduino/HID.cpp
	@echo [93marduino/HID.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/HID.cpp
include .build/pro5v328/arduino/HID.d

.build/pro5v328/arduino/USBCore.o : /usr/share/arduino/hardware/arduino/cores/arduino/USBCore.cpp
	@echo [93marduino/USBCore.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/USBCore.cpp
include .build/pro5v328/arduino/USBCore.d

.build/pro5v328/arduino/CDC.o : /usr/share/arduino/hardware/arduino/cores/arduino/CDC.cpp
	@echo [93marduino/CDC.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/CDC.cpp
include .build/pro5v328/arduino/CDC.d

.build/pro5v328/arduino/Stream.o : /usr/share/arduino/hardware/arduino/cores/arduino/Stream.cpp
	@echo [93marduino/Stream.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/Stream.cpp
include .build/pro5v328/arduino/Stream.d

.build/pro5v328/arduino/Tone.o : /usr/share/arduino/hardware/arduino/cores/arduino/Tone.cpp
	@echo [93marduino/Tone.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/Tone.cpp
include .build/pro5v328/arduino/Tone.d

.build/pro5v328/arduino/new.o : /usr/share/arduino/hardware/arduino/cores/arduino/new.cpp
	@echo [93marduino/new.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/new.cpp
include .build/pro5v328/arduino/new.d

.build/pro5v328/arduino/IPAddress.o : /usr/share/arduino/hardware/arduino/cores/arduino/IPAddress.cpp
	@echo [93marduino/IPAddress.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/IPAddress.cpp
include .build/pro5v328/arduino/IPAddress.d

.build/pro5v328/arduino/HardwareSerial.o : /usr/share/arduino/hardware/arduino/cores/arduino/HardwareSerial.cpp
	@echo [93marduino/HardwareSerial.cpp[0m
	@mkdir -p .build/pro5v328/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/HardwareSerial.cpp
include .build/pro5v328/arduino/HardwareSerial.d



.build/pro5v328/arduino/libarduino.a : .build/pro5v328/arduino/WInterrupts.o .build/pro5v328/arduino/wiring_digital.o .build/pro5v328/arduino/wiring_analog.o .build/pro5v328/arduino/wiring_shift.o .build/pro5v328/arduino/wiring_pulse.o .build/pro5v328/arduino/wiring.o .build/pro5v328/arduino/WMath.o .build/pro5v328/arduino/WString.o .build/pro5v328/arduino/Print.o .build/pro5v328/arduino/main.o .build/pro5v328/arduino/HID.o .build/pro5v328/arduino/USBCore.o .build/pro5v328/arduino/CDC.o .build/pro5v328/arduino/Stream.o .build/pro5v328/arduino/Tone.o .build/pro5v328/arduino/new.o .build/pro5v328/arduino/IPAddress.o .build/pro5v328/arduino/HardwareSerial.o
	@echo [92mLinking libarduino.a[0m
	@/usr/bin/avr-ar rcs $@ $^















.build/pro5v328/src/motordriver_4wd.o : src/motordriver_4wd.cpp
	@echo [93msrc/motordriver_4wd.cpp[0m
	@mkdir -p .build/pro5v328/src
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c src/motordriver_4wd.cpp
include .build/pro5v328/src/motordriver_4wd.d

.build/pro5v328/src/seeed_pwm.o : src/seeed_pwm.cpp
	@echo [93msrc/seeed_pwm.cpp[0m
	@mkdir -p .build/pro5v328/src
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c src/seeed_pwm.cpp
include .build/pro5v328/src/seeed_pwm.d

.build/pro5v328/src/motorDriverDemo.o : .build/pro5v328/src/motorDriverDemo.cpp
	@echo [93msrc/motorDriverDemo.cpp[0m
	@mkdir -p .build/pro5v328/src
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions -iquote src  -o $@ -c .build/pro5v328/src/motorDriverDemo.cpp
include .build/pro5v328/src/motorDriverDemo.d







.build/pro5v328/firmware.elf : .build/pro5v328/src/motordriver_4wd.o .build/pro5v328/src/seeed_pwm.o .build/pro5v328/src/motorDriverDemo.o .build/pro5v328/arduino/libarduino.a
	@echo [92mLinking firmware.elf[0m
	@/usr/bin/avr-gcc -mmcu=atmega328p -Wl,-Os -Wl,--gc-sections -o $@ $^ -lm


.build/pro5v328/firmware.hex : .build/pro5v328/firmware.elf
	@echo [92mConverting to firmware.hex[0m
	@/usr/bin/avr-objcopy -O ihex -R .eeprom $^ $@

include .build/pro5v328/src/dependencies.d .build/pro5v328/arduino/dependencies.d

all : .build/pro5v328/firmware.hex
	@true


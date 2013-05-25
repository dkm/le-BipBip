CC=msp430-gcc
CFLAGS=-g -Os -Wall -I/usr/msp430/include -mmcu=msp430g2553 -fmessage-length=0
LDFLAGS=-lm

SOURCES=bluetooth.c buzzer.c filter.c ms5607.c power.c sink.c timer.c vario.c button.c charge_pump.c lebipbip.c oscillator.c sensor.c spi.c uart.c vario_settings.c
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

main: solarclimb.elf

solarclimb.elf: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) solarclimb.elf
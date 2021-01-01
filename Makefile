CC?=msp430-gcc


ifeq ($(MSP430_GCC_INCLUDE_DIR),)
$(error Missing MSP430_GCC_INCLUDE_DIR)
else
export MSP430_GCC_INCLUDE_DIR
endif

CFLAGS?=-g -Os -Wall  -mmcu=msp430g2553 -ffunction-sections -fdata-sections -flto
LDFLAGS?=-lm  -Wl,-gc-sections -flto

SOURCES=buzzer.c \
	filter.c \
	ms5607.c \
	power.c \
	sink.c \
	timer.c \
	vario.c \
	button.c \
	charge_pump.c \
	lebipbip.c \
	oscillator.c \
	sensor.c \
	spi.c \
	uart.c \
	vario_settings.c

OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

main: solarclimb.elf

solarclimb.elf: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) solarclimb.elf

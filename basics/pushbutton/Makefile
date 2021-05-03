MCU   = atmega328p
F_CPU = 1000000UL  
BAUD  = 9600UL

PROGRAMMER=avrisp
PROGRAMMER_ARGS= -P /dev/ttyACM0 -b 19200

CC = avr-gcc
AVRDUDE = avrdude
OBJCOPY = avr-objcopy
AVRSIZE = avr-size

TARGET= pb

SOURCES=$(wildcard *.c)

CPPFLAGS = -DF_CPU=$(F_CPU) 
# -DBAUD=$(BAUD)

CFLAGS = -Os -g -std=gnu99 -Wall

CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums 

CFLAGS += -ffunction-sections -fdata-sections 

LDFLAGS = -Wl,-Map,$(TARGET).map 

LDFLAGS += -Wl,--gc-sections 

TARGET_ARCH = -mmcu=$(MCU)

.PHONY: all flash size clean check
all: $(TARGET).hex

%.o: $(SOURCES) 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $^

%.elf: %.o
	$(CC) $(LDFLAGS) $(TARGET_ARCH) -o $@ $^

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@


clean:
	-rm $(TARGET).o $(TARGET).map $(TARGET).elf $(TARGET).hex

check:
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) $(PROGRAMMER_ARGS) -vn

size: $(TARGET).elf
	$(AVRSIZE) -C --mcu=$(MCU) $< 


flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) $(PROGRAMMER_ARGS) -U flash:w:$<:i

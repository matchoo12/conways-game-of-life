CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
PREFIX ?= $(HOME)/conway-install
TARGET = conway
OBJS = main.o conway.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c conway.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

install: $(TARGET)
	install -d $(PREFIX)/bin
	install -m 755 $(TARGET) $(PREFIX)/bin/$(TARGET)

.PHONY: all clean install

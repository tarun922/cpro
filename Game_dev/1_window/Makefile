# Standard Makefile used by every chapter in this course.
# It links all SDL3 libraries so every chapter's Makefile looks identical.

CC = gcc
CFLAGS = -Wall -std=c11 $(shell pkg-config --cflags sdl3 sdl3-image sdl3-ttf sdl3-net)
LDFLAGS = $(shell pkg-config --libs sdl3 sdl3-image sdl3-ttf sdl3-net)
TARGET = main

$(TARGET): main.c
	$(CC) main.c -o $(TARGET) $(CFLAGS) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean

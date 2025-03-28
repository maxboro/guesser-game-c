# unity build
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src
TARGET = exec

all: $(TARGET)

$(TARGET): $(SRC)/main.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)


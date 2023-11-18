# Compiler and Compiler Flags
CC = gcc
CFLAGS = -Wall -g

# Target executable name
TARGET = main

# Directory for binaries
BINDIR = bin

# Source files and object files
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Default target
$(BINDIR)/$(TARGET): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

# To obtain object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# To remove generated files
clean:
	rm -f $(OBJS) $(BINDIR)/$(TARGET)

.PHONY: clean


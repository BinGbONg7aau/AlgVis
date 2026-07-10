# Makefile for AlgVis

CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -g
LDFLAGS ?=
PREFIX ?= /usr/local
TARGET ?= algvis

SRCS = main.c helperFunctions.c \
       algs/binarySearch.c algs/linearSearch.c \
       algs/insertionSort.c algs/mergeSort.c

OBJS = $(SRCS:.c=.o)

.PHONY: all clean dist check distcheck install uninstall

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

check: all
	@echo "No runtime tests configured."

distcheck: all
	@echo "No distcheck target configured."

clean:
	rm -f $(OBJS) $(TARGET)

install: all
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

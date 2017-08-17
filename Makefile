CFILES := $(wildcard *.c)
PROGS := $(patsubst %.c,%,$(CFILES))
CFLAGS := -fno-stack-protector
CC := gcc

all: $(PROGS)
	@echo $(PROGS)

stack: stack.c
	$(CC) -o $@ $(CFLAGS) $<
	sudo chmod 4755 stack


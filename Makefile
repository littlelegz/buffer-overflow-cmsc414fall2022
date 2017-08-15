CFILES := $(wildcard *.c)
PROGS := $(patsubst %.c,%,$(CFILES))
CFLAGS := -fno-stack-protector
CC := gcc

all: $(PROGS)
	@echo $(PROGS)


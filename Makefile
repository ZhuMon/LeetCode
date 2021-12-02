CC = gcc
CFLAGS = -O1 -g -Wall -Werror -I.
CFLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-common
LDFLAGS += -fsanitize=address

ifeq ("$(VERBOSE)","1")
    Q :=
    VECHO = @true
else
    Q := @
    VECHO = @printf
endif

all: main
	
main: main.o
	$(VECHO) "  LD\t$@\n"
	$(Q)$(CC) $(LDFLAGS) -o $@ $^
	./main
main.o: main.c
	$(VECHO) "  CC\t$@\n"
	$(Q)$(CC) -o $@ $(CFLAGS) -c $^

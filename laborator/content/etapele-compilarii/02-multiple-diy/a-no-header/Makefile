CFLAGS = -fno-PIC -m32 -g
LDFLAGS = -no-pie -m32

.DEFAULT_GOAL: all

.PHONY: all clean

all: main

main: main.o div.o mul.o
	$(CC) $(LDFLAGS) -o $@ $^

div.o: div.c

mul.o: mul.c

main.o: main.c

clean:
	-rm -f main main.o div.o mul.o
	-rm -f *~

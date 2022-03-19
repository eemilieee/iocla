CFLAGS = -fno-PIC -m32 -g
LDFLAGS = -nostdinc -nostdlib -no-pie -m elf_i386
AS = nasm
ASFLAGS = -f elf32

.DEFAULT_GOAL: all

.PHONY: all clean

all: hello

hello: name.o start.o puts.o
	ld $(LDFLAGS) name.o start.o puts.o -o name

name.o: name.c
	gcc $(CFLAGS) -c name.c -o name.o

start.o: start.asm
	$(AS) $(ASFLAGS) -o $@ $<

puts.o: puts.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	-rm -f name name.o start.o puts.o
	-rm -f *~

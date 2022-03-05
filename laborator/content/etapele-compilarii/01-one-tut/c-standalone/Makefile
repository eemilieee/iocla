CFLAGS = -fno-PIC -m32 -g
LDFLAGS = -nostdinc -nostdlib -no-pie -m elf_i386
AS = nasm
ASFLAGS = -f elf32

.DEFAULT_GOAL: all

.PHONY: all clean

all: hello

hello: hello.o start.o puts.o
	ld $(LDFLAGS) hello.o start.o puts.o -o hello

hello.o: hello.c
	gcc $(CFLAGS) -c hello.c -o hello.o

start.o: start.asm
	$(AS) $(ASFLAGS) -o $@ $<

puts.o: puts.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	-rm -f hello hello.o start.o puts.o
	-rm -f *~

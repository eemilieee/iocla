%include "../utils/printf32.asm"

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov eax, 211    ; to be broken down into powers of 2
    mov ebx, 1      ; stores the current power
    mov ecx, 0

 ; TODO - print the powers of 2 that generate number stored in EAX

sarim:
    cmp ebx, 0
    je out
    mov edx, ebx
    and edx, eax
    cmp edx, 0
    jne print
    shl ebx, 1
    add ecx, 1
    jmp sarim

print:
    PRINTF32 `%d\n\x0`, edx;
    shl ebx, 1
    add ecx, 1
    jmp sarim

out:
    leave
    ret

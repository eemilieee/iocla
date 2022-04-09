%include "../utils/printf32.asm"

section .data
    num dd 100
    print_format1 db "Sum(", 0
    print_format2 db "): ", 0

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov ecx, [num]     ; Use ecx as counter for computing the sum.
    xor edx, edx       ; Use edx to store the sum. Start from 0.

add_squares:
    cmp ecx, 0
    je out
    mov eax, ecx
    xor ebx, ebx
    jmp square

back:
    add edx, ebx
    sub ecx, 1
    jmp add_squares

square:
    cmp eax, 0
    je back
    add ebx, ecx
    sub eax, 1
    jmp square

out:

    mov ecx, [num]
    PRINTF32 `%s\x0`, print_format1
    PRINTF32 `%u\x0`, ecx
    PRINTF32 `%s\x0`, print_format2
    PRINTF32 `%u\n\x0`, edx

    leave
    ret

%include "../utils/printf32.asm"

%define ARRAY_SIZE    10

section .data
    byte_array dd 1, 2, -3, 4, 5, -6, 7, 8, -9, 10
    print_format1 db "Number of positive numbers is ", 0
    print_format2 db "Number of negative numbers is ", 0

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov ecx, ARRAY_SIZE     ; Use ecx as loop counter.
    xor eax, eax            ; Use edx to store the sum.
    xor edx, edx
    xor ebx, ebx

loop:
    cmp ecx, 0
    je out
    mov eax, dword [byte_array + 4*(ecx - 1)]
    cmp eax, 0
    jg positive
    cmp eax, 0
    jl negative
back:
    sub ecx, 1
    jmp loop

positive:
    add ebx, 1
    jmp back

negative:
    add edx, 1
    jmp back

out:
    PRINTF32 `%s\x0`, print_format1
    PRINTF32 `%u\n\x0`, ebx
     PRINTF32 `%s\x0`, print_format2
    PRINTF32 `%u\n\x0`, edx

    leave
    ret

%include "../utils/printf32.asm"

%define ARRAY_SIZE    10

section .data
    byte_array db 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    print_format db "Array sum is ", 0

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

add_byte_array_element:
    xor eax, eax
    mov al, byte [byte_array + ecx - 1]
    mov bl, byte [byte_array + ecx - 1]
    mul bl
    add edx, eax
    loop add_byte_array_element ; Decrement ecx, if not zero, add another element.

    PRINTF32 `%s\x0`, print_format
    PRINTF32 `%u\n\x0`, edx

    leave
    ret

%include "../utils/printf32.asm"

%define ARRAY_1_LEN 5
%define ARRAY_2_LEN 7
%define ARRAY_OUTPUT_LEN 12

section .data

array_1 db 27, 46, 55, 83, 84
array_2 db 1, 4, 21, 26, 59, 92, 105
array_output times 12 db 0


section .text

extern printf
global main
main:
    mov eax, 0 ; counter used for array_1
    mov ebx, 0 ; counter used for array_2
    mov ecx, 0 ; counter used for the output array

    push ebp
    mov ebp, esp

    sub esp, ARRAY_OUTPUT_LEN * 4

merge_arrays:
    xor edx, edx
    mov dl, byte [array_1 + eax]
    mov dh, byte [array_2 + ebx]
    cmp dl, dh
    jg array_2_lower

array_1_lower:
    ;mov byte [array_output + ecx], dl

    mov dword[esp + ecx * 4], 0
    mov byte[esp + ecx * 4], dl

    inc ecx
    inc eax
    jmp verify_array_end

array_2_lower:
    ;mov byte [array_output + ecx], dh

    mov dword[esp + ecx * 4], 0
    mov byte[esp + ecx * 4], dh

    inc ecx
    inc ebx

    jmp verify_array_end

verify_array_end:
    cmp eax, ARRAY_1_LEN
    je copy_array_2
    cmp ebx, ARRAY_2_LEN
    je copy_array_1
    jmp merge_arrays

copy_array_1:
    cmp eax, ARRAY_1_LEN
    je print_array

    xor edx, edx
    mov dl, byte [array_1 + eax]

    ;mov byte [array_output + ecx], dl

    mov dword[esp + ecx * 4], 0
    mov byte[esp + ecx * 4], dl

    inc ecx
    inc eax

    jmp copy_array_1

copy_array_2:
    cmp ebx, ARRAY_2_LEN
    je print_array

    xor edx, edx
    mov dh, byte [array_2 + ebx]

    ;mov byte [array_output + ecx], dh

    mov dword[esp + ecx * 4], 0
    mov byte[esp + ecx * 4], dh

    inc ecx
    inc ebx

    jmp copy_array_2

print_array:
    PRINTF32 `Array merged:\n\x0`
    xor ecx, ecx

print:
    cmp ecx, ARRAY_OUTPUT_LEN
    je out

    ;mov al, byte [array_output + ecx]

    xor eax, eax
    mov eax, dword [esp + ecx * 4]

    PRINTF32 `%d \x0`, eax

    inc ecx
    jmp print

out:
    PRINTF32 `\n\x0`

    add esp, ARRAY_OUTPUT_LEN * 4

    mov esp, ebp
    pop esp

    xor eax, eax
    leave
    ret
    
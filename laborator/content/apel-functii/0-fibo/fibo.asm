%include "../utils/printf32.asm"

%define NUM_FIBO 10

section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO - replace below instruction with the algorithm for the Fibonacci sequence
    ; sub esp, NUM_FIBO * 4

    mov ecx, NUM_FIBO

    xor eax, eax
    mov ebx, 1
    push eax
    push ebx
    
    sub ecx, 2

fibo:
    cmp ecx, 0
    je out
    xor edx, edx
    mov edx, eax
    add edx, ebx
    push edx
    mov eax, ebx
    mov ebx, edx
    sub ecx, 1
    jmp fibo

out:
    mov ecx, NUM_FIBO

print:
    mov eax, dword [esp + (ecx - 1) * 4]
    PRINTF32 `%d \x0`, eax
    dec ecx
    cmp ecx, 0
    ja print

    PRINTF32 `\n\x0`
    mov esp, ebp
    xor eax, eax
    ret

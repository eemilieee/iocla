%include "printf32.asm"

section .data
    myString: db "Hello, World!", 0
    myString2: db "Goodbye, World!", 0

section .text
    global main
    extern printf

main:
    mov ecx, 6                      ; N = valoarea registrului ecx
    mov eax, 2
    mov ebx, 1
    mov edx, 0
    cmp eax, ebx
    jg print                        ; TODO1: eax > ebx?
    ret

print:
    cmp edx, ecx
    jne loop
    PRINTF32 `%s\n\x0`, myString2   ; TODO2.2: afisati "Hello, World!" de N ori
    ret                             ; TODO2.1: afisati "Goodbye, World!"

loop:
    PRINTF32 `%s\n\x0`, myString
    add edx, 1
    jmp print

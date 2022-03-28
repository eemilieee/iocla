%include "printf32.asm"

section .text
    global main
    extern printf

main:
    ;cele doua multimi se gasesc in eax si ebx

    mov eax, 139
    mov ebx, 169
    PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime
    PRINTF32 `%u\n\x0`, ebx ; afiseaza cea de-a doua multime

    ; prima multime (eax) contine {0, 1, 3 , 7}
    ; a doua multime (ebx) contine {0, 3, 5 , 7}

    ; TODO1: reuniunea a doua multimi (eax si ebx)

    mov ecx, eax
    or ecx, ebx
    PRINTF32 `%u\n\x0`, ecx      ; {0, 1, 3, 5 , 7}

    ; TODO2: adaugarea unui element in multime (eax)

    ; adaug {2, 4}
    ; sau cu masca
    or eax, 4    ; (2^2)
    or eax, 16   ; (2^4)
    PRINTF32 `%u\n\x0`, eax      ; {0, 1, 2, 3, 4, 7}

    ; TODO3: intersectia a doua multimi (eax si ebx)

    mov edx, eax
    and edx, ebx
    PRINTF32 `%u\n\x0`, edx      ; {0, 3, 7}

    ; TODO4: complementul unei multimi (eax)

    mov ecx, eax
    not ecx
    PRINTF32 `%u\n\x0`, ecx      ; {5, 6, 8, 9, ..., 31}

    ; TODO5: eliminarea unui element (din eax)

    ; elimin {2}
    ;si cu masca negata

    mov edx, 4    ; (2^2)
    not edx
    and eax, edx
    PRINTF32 `%u\n\x0`, eax       ; {0, 1, 3, 4, 7}

    ; TODO6: diferenta de multimi EAX-EBX

    ; xor dintre eax si intersectie

    mov edx, eax
    and edx, ebx
    xor edx, eax
    PRINTF32 `%u\n\x0`, edx       ; {1, 4}

    xor eax, eax
    ret

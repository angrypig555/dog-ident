global _start


section .bss:
    ; buffers go here
    coatbuffer resb 10

section .text:
_start:
    mov eax, 0x4 ; prints welcome message
    mov ebx, 1
    mov ecx, message_welcome
    mov edx, message_welcome_leng
    int 0x80

    mov eax, 0x3
    mov ebx, 0
    lea ecx, [coatbuffer]
    mov edx, 10
    int 0x80

    lea esi, [coatbuffer]
    lea edi, [coat_type]
    mov ecx, 10
    rep movsb
    
    mov eax, 0x4
    mov ebx, 1
    mov ecx, coat_type
    mov edx, 10
    int 0x80

    mov eax, 0x1 ; exits or else its a segfault
    mov ebx, 0
    int 0x80

section .data:
    ; place for variables
    coat_type: times 10 db 0
    message_welcome: db "dog-ident v1, made for woof", 0xA
    message_welcome_leng: equ $-message_welcome
    question1: db "Does your dog have double, silky, smooth, wire or wool coat?", 0xA
    question1_leng: equ $-question1
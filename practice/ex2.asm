global _start

; this will allow us inline data into the program
; that we can reference in the code by name

section .data 
    msg db "hello, world!", 0x0a    ;0x0a is hex for 10 & code for the new line char
    len equ $ - msg                 ;use equ not db allows you to change the message
                                    ;without needing to changing the len

section .text
_start:
    mov eax, 4                      ; sys_write system call
    mov ebx, 1                      ; stdout file descriptor
    mov ecx, msg                    ; bytes to sys_write
    mov edx, len                    ; number of bytes to sys_write
    int 0x80                        ; perform system call
    mov eax, 1                      ; sys_exit system call
    mov ebx, 0                      ; exit status is 0
    int 0x80

global _start

section .data
    addr db "yellow"        ; addr is a pointer to some memory address
                            ; which is a string taht contains the word "yellow"

section .text
_start:
    mov [addr], byte 'H'    ; access the 0 position & add 'H' to the position
    mov [addr + 5], byte '!'; access the 5th position ('w') & add '!' to the position
    mov eax, 4              ; sys_write system call
    mov ebx, 1              ; stdout file descriptor
    mov ecx, addr           ; bytes to sys_write
    mov edx, 6              ; number of bytes to write
    int 0x80                ; perform system call
    mov eax, 1              ; system_exit system call
    mov ebx, 0              ; exit status is 0
    int 0x80
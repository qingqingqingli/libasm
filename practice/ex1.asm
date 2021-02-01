global _start

_start:
        mov eax, 1      ; performs a move
        mov ebx, 42
        sub ebx, 29     ; performs a subtraction. It is done in place and alters the value in ebx
        int 0x80        ; performs an interrupt
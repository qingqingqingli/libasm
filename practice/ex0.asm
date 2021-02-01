global _start       ; entry point for the program

_start:
    mov eax, 1      ; the system call made that is determined by this register. 1 means system exit call
    mov ebx, 42     ; set the exit code
    int 0x80        ; The processor will transfer control to an interrupt handle specified by (0x80), which means system calls
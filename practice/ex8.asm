global _start

_start:
    call func
    mov eax, 1
    mov ebx, 0
    int 0x80

func:
    push ebp                ; preserve the old value of ebp onto the stack
    mov ebp, esp            ; esp is the top of the stack
                            ; in this way, we can reserve the top of the stack before
                            ; reaching the return operation
    sub esp, 2              ; allocate 2 bytes on the stack
    mov [esp], byte 'H'
    mov [esp + 1], byte 'i'
    mov eax, 4                  ; sys_write
    mov ebx, 1                  ; stdout file descriptor
    mov ecx, esp                ; pointer to bytes to sys_write
    mov edx, 2                  ; number of bytes to write
    int 0x80
    mov esp, ebp                ; store the right location on the top of the stack
    pop ebp                     ; pop the original value into ebp, so you don't mess up with the value
                                ; push & pop ebp help nested function calls without the functions
                                ; interfering with each other's stack
    ret
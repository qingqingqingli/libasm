global	_start		; entry point for the program

section .data
	hello db "Welcome back", 0x0a
	len equ $ - hello

section .text
_start:
	mov rax, 4
	mov rbx, 1
	mov rcx, hello
	mov rdx, len
	int 0x80
	mov rax, 1
	mov rbx, 0
	int 0x80

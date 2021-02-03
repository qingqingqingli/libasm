section	.data
		text db "Hello, world", 10, 0 	; index with 0
		text1 db "test test", 10, 0 	; index with 0

section	.text
		global _start

_start:
		mov 	rax, text
		call	_print

		mov 	rax, text1
		call	_print

		mov 	rax, 60
		mov 	rdi, 0
		syscall

; input: rax as pointer to string (store memory address)
; output: print string at rax

_print:
		push	rax	; save rax value for later
		mov		rbx, 0	; use rbx to calculate the strength later

; inner loop
_printLoop:
		inc		rax
		inc		rbx
		mov		cl, [rax]	; every time when we go into the loop
							; it will hold the next value on the string
		cmp		cl, 0
		jne		_printLoop

		mov		rax, 1
		mov		rdi, 1
		pop		rsi
		mov		rdx, rbx
		syscall
		ret

; nasm -felf64 print_string.asm && ld print_string.o && ./a.out
; rm *.o *.out

; section 	.text
; global		ft_strlen		; entry point for the program

; ft_strlen:

; 			mov		rcx, -1
; 			mov 	rsi, rdi		; back up rdi
; 			mov 	rax, 0			; look for \0
; 			repne	scasb			; do the search
; 			sub 	rdi, rsi		; save the srting length
; 			dec 	rdi				; decrement one for \0
; 			mov		rax, rdi		; save the return value
; 			ret

; -> produce a .o file, which needs to be linked to become an executable

; nasm -felf64 ft_strlen.asm
; gcc main.c ft_strlen.o
; ./a.out
; rm *.o *.out


section		.text
global		ft_strlen

ft_strlen:

		push	rbp
		mov		rbp, rsp
		mov 	rax, [rbp + 8]

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

		mov		rsp, rbp		; restore the right location on the top of stack
		pop		rbp				; store the original value into rbp

		ret


			; push	rbp				; preserve the old value of bep onto the stack
			; mov		rbp, rsp		; rsp points to the top of the stack

			; mov		rax, 1
			; mov		rdi, 1
			; mov		rsi, [rbp + 8]	; pop value to eax
			; mov		rdx, 10
			; syscall

			; mov		rsp, rbp		; restore the right location on the top of stack
			; pop		rbp				; store the original value into rbp
			; ret

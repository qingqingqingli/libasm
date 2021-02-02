global		ft_strlen		; entry point for the program

section 	.text

ft_strlen:
	mov		rcx, -1
	mov 	rsi, rdi		; back up rdi
	mov 	rax, 0			; look for \0
	repne	scasb			; do the search
	sub 	rdi, rsi		; save the srting length
	dec 	rdi				; decrement one for \0
	mov		rax, rdi		; save the return value
	ret

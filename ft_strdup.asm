; -------------------------------------------
; [strdup]
; - duplicate a string
; - char *strdup(const char *s);
; - The strdup() function returns a pointer to a new string which is a duplicate
; 	of the string s. Memory for the new string is obtained with malloc, and
;	can be freed with free.
; - On success, it returns a pointer to the duplicated string.
; - It returns NULL if insufficient memory was available, with errno set to
;	indicate the cause of the error.

; [Registers]
; rdi -> char *s
; rax -> return value
; -------------------------------------------

extern 		__errno_location
extern		malloc
extern		ft_strlen
extern		ft_strcpy

section		.text
global		ft_strdup

ft_strdup:
	push	rdi				; save rdi on the stack

_calculate_len:
	call	ft_strlen		; calculate the length
	mov		rcx, rax		; len is saved in rax -> rcx
	inc		rcx				; add one space for \0

_malloc_dest:
	mov		rdi, rcx		; save the required len in rdi
	call	malloc			; call malloc
	cmp		rax, 0			; check if malloc fails
	je		_error			; go to the error routine if it fails

_copy_string:
	mov		rdi, rax		; save the malloced string to rdi
	pop		rsi				; save the original rdi into rsi
	call	ft_strcpy		; call strcpy & result is saved in rax
	ret						; return dst in rax

_error:
	call	__errno_location	; call the function
	mov		[rax], 12		; 12 stands for ENOMEM
	mov		rax, 0
	ret

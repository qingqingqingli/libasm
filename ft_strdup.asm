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

section		.text
global		ft_strdup
extern 		__errno_location
extern		malloc
extern		ft_strlen
extern		ft_strcpy


ft_strdup:
	mov		r8, rdi			; save the src string

_calculate_len:
	call	ft_strlen		; calculate the length
	; mov		rax, r8
	; ret
	mov		rcx, rax		; len is saved in rax -> rcx
	inc		rcx				; add one space for \0

_malloc_dest:
	mov		rdi, rcx		; save the required len in rdi
	call	malloc
	cmp		rax, 0			; if the result is null
	je		_error

_copy_string:
	mov		rdi, rax
	mov		rsi, r8
	call	ft_strcpy

_error:
	neg		rax
	mov		rdx, rax
	call	__errno_location
	mov		[rax], rdx
	mov		rax, -1
	ret

_return:
	ret


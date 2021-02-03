; -------------------------------------------
; [strcmp]
; - compare two strings
; - int strcmp(const char *s1, const char *s2);
; - The strcmp() function compares the two strings s1 and s2. It returns an
;   integer less than, equal to, or greater than zero if s1 is found, respectively,
;   to be less than, to match, or be greater than s2.
; - The strcmp() function return an integer less than, equal to, or greater than
;   zero if s1 is found, respectively, to be less than, to match, or be greater than s2.

; [Registers]
; rdi -> char *s1
; rsi -> char *s2
; rax -> return value
; -------------------------------------------

section		.text
global		ft_strcmp

ft_strcmp:
	mov		rax, 0
	mov		rcx, 0

_loop:
	mov		al, byte[rdi + rcx]
	mov		cl, byte[rsi + rcx]
	cmp		al, cl
	jne		_subtract
	inc		rcx
	jmp		_loop

_subtract:
	sub 	rax, rcx
	ret

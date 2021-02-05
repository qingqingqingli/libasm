; -------------------------------------------
; [strcmp]
; - compare two strings
; - int strcmp(const char *s1, const char *s2);
; - The strcmp() function compares the two strings s1 and s2. It returns an
;   integer less than, equal to, or greater than zero if s1 is found, respectively,
;   to be less than, to match, or be greater than s2.

; [Registers]
; rdi -> char *s1
; rsi -> char *s2
; rax -> return value
; -------------------------------------------

section		.text
global		ft_strcmp

ft_strcmp:
	mov		rax, 0
	mov		rdx, 0
	mov		rcx, -1

_check:
	inc		rcx
	mov		al, byte[rdi + rcx]
	mov		dl, byte[rsi + rcx]
	cmp		al, 0
	je		_return
	cmp		dl, 0
	je		_return
	cmp		al, dl
	je		_check

_return:
	sub		rax, rdx
	ret

; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcmp.asm                                      :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/05 12:42:00 by qli           #+#    #+#                  ;
;    Updated: 2021/02/05 12:42:11 by qli           ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

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
	mov		rax, 0					; initialise rax to 0
	mov		rdx, 0					; initialise rdx to 0
	mov		rcx, -1					; initialise rcx to -1

_check:
	inc		rcx						; rcx becomes 0
	mov		al, byte[rdi + rcx]		; save current s1 char to al
	mov		dl, byte[rsi + rcx]		; save current s2 char to dl
	cmp		al, 0					; check if s1 char is \0
	je		_return					; if \0, go to return process
	cmp		dl, 0					; check if s2 char is \0
	je		_return					; if \0, go to return process
	cmp		al, dl					; compare s1 and s2 char
	je		_check					; if equal, start the loop again

_return:
	sub		rax, rdx				; subtract s1 char with s2 char
	ret								; return value saved in rax

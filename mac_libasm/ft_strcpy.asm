; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcpy.asm                                      :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/03 17:44:07 by qli           #+#    #+#                  ;
;    Updated: 2021/02/05 14:52:25 by qli           ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; -------------------------------------------
; [strcpy]
; - copy a string
; - char *strcpy(char *dest, const char *src);
; - The strcpy() function copies the string pointed to by src, including the
;   terminating '\0', to the buffer pointed to by dest. Strings may not overlap.
;   The destination string dest must be large enough to receive the copy.
; - The strcpy() return a pointer to the destination string dest.

; [Registers]
; rdi -> char *dest
; rsi -> char *src
; rax -> return value
; -------------------------------------------

section		.text
global		_ft_strcpy

_ft_strcpy:
	mov		rax, 0					; initialise rax to 0
	mov 	rcx, 0					; initialise counter to 0

_loop:
	mov		al, byte[rsi + rcx]		; save src char into al
	mov		[rdi + rcx], al			; save al into dest
	inc		rcx						; increment counter
	cmp		al, 0					; check if it is \0
	jne		_loop					; if not the end, start the loop again

_return:
	mov		rax, rdi				; save dst into rax
	ret								; a pointer to dst will be returned

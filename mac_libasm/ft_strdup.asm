; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strdup.asm                                      :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/05 12:52:34 by qli           #+#    #+#                  ;
;    Updated: 2021/02/05 14:54:05 by qli           ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

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

extern 		___error
extern		malloc
extern		_ft_strlen
extern		_ft_strcpy

section		.text
global		_ft_strdup

_ft_strdup:
	push	rdi				; save rdi on the stack

_calculate_len:
	call	_ft_strlen		; calculate the length
	mov		rcx, rax		; len is saved in rax and copied into rcx
	inc		rcx				; add one space for \0

_malloc_dest:
	mov		rdi, rcx		; save the required len in rdi
	call	malloc			; call malloc
	cmp		rax, 0			; check if malloc fails
	je		_set_error			; go to the error routine if it fails

_copy_string:
	mov		rdi, rax		; save the malloced string to rdi
	pop		rsi				; save the original rdi into rsi
	call	_ft_strcpy		; call strcpy & result is saved in rax
	ret						; return dst in rax

_set_error:
	pop		rdi				; clean up stack if malloc fails
	call	___error		; call the errno function
	mov		rdx, 12			; 12 stands for ENOMEM
	mov		[rax], rdx		; save errro code into rax
	mov		rax, 0			; change rax to 0
	ret						; NULL is returned when malloc fails

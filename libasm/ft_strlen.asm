; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.asm                                      :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/03 17:43:33 by qli           #+#    #+#                  ;
;    Updated: 2021/02/05 12:48:29 by qli           ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; -------------------------------------------
; [strlen]
; - calculate the length of a string
; - size_t strlen(const char *s);
; - strlen() calculates the length of the string pointed to by s, excluding '\0'
; - Returns the number of bytes in the string pointed to by s.

; [Registers]
; rdi -> char *s
; rax -> return value
; current char -> byte[rdi + rax]
; -------------------------------------------

section		.text
global		ft_strlen

ft_strlen:

	mov rax, -1					; initialise the rax to -1

_loop:
	inc rax						; increment rax to 0
	cmp byte[rdi + rax], 0		; compare the current src char to 0
	jne _loop					; start the loop again if not the end

_return:
	ret							; return length in rax

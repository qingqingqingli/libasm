; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.asm                                      :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/03 17:43:33 by qli           #+#    #+#                  ;
;    Updated: 2021/02/03 19:16:41 by qli           ########   odam.nl          ;
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

	mov rax, 0					; initialise the rax (return value) to 0

	cmp byte[rdi + rax], 0		; compare the 0 index char
	je _return					; return if it is an empty string

_loop:
	inc rax						; otherwise, it will come into the loop
	cmp byte[rdi + rax], 0		; compare the current index char
	jne _loop					; return to the loop if not 0

_return:
	ret							; when the loop reaches 0 and ends
								; come to this line and return rax

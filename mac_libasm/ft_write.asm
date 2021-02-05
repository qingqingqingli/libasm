; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.asm                                       :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/05 12:52:43 by qli           #+#    #+#                  ;
;    Updated: 2021/02/05 12:52:47 by qli           ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; -------------------------------------------
; [write]
; - write to a file descriptor
; - ssize_t write(int fd, const void *buf, size_t count);
; - write() writes up to count bytes from the buffer starting at buf to the file
;   referred to by the file descriptor fd.
; - On success, the number of bytes written is returned.
; - On error, -1 is returned, and errno is set appropriately.

; [Registers]
; rdi -> int fd
; rsi -> void *buf
; rdx -> size_t count
; rax -> return value
; -------------------------------------------

extern 		__errno_location

section		.text
global		ft_write

ft_write:
	mov		rax, 1				; 1 is syscall id for write
	syscall
	test	rax, rax			; set condition codes
	js		_error				; jump if negative (meaning an error occured)
	ret

_error:
	neg		rax					; negate negative rax to positive
	mov		rdx, rax			; save code to rdx to store
	call	__errno_location	; call errno
	mov		[rax], rdx			; save error code to rax
	mov		rax, -1				; set rax to -1 as return value
	ret

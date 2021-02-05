; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.asm                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/05 12:42:06 by qli           #+#    #+#                  ;
;    Updated: 2021/02/05 14:43:22 by qli           ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

; -------------------------------------------
; [read]
; - read from a file descriptor
; - ssize_t read(int fd, void *buf, size_t count);
; - read() attempts to read up to count bytes from file descriptor fd into the
;   buffer starting at buf.
; - On success, the number of bytes read is returned (zero indicates end of file)
; - On error, -1 is returned, and errno is set appropriately.

; [Registers]
; rdi -> int fd
; rsi -> void *buf
; rdx -> size_t count
; rax -> return value
; -------------------------------------------

extern 		__errno_location	; include external errno

section		.text
global		ft_read

ft_read:
	mov		rax, 0x02000003		; syscall id for read
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

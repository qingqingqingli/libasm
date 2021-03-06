; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.asm                                       :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/05 12:52:43 by qli           #+#    #+#                  ;
;    Updated: 2021/02/05 15:45:59 by qli           ########   odam.nl          ;
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

extern 		___error			; include external error

section		.text
global		_ft_write

_ft_write:
	mov		rax, 0x02000004		; syscall id for write
	syscall
	jc		_set_error			; jump if carry flag is set
	ret

_set_error:
	push	rax					; push rax on the stack
	call	___error			; call errno
	pop		rdx					; pop rax value into rdx
	mov		[rax], rdx			; save error code to rax
	mov		rax, -1				; set rax to -1 as return value
	ret

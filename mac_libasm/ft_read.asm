; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.asm                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: qli <qli@student.codam.nl>                   +#+                      ;
;                                                    +#+                       ;
;    Created: 2021/02/05 12:42:06 by qli           #+#    #+#                  ;
;    Updated: 2021/02/05 15:44:54 by qli           ########   odam.nl          ;
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

extern 		___error			; include external error

section		.text
global		_ft_read

_ft_read:
	mov		rax, 0x02000003		; syscall id for read
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

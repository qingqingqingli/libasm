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
	mov		rax, 0				; 0 is the syscall id for read
	syscall
	test	rax, rax			; set condition codes
	js		_error				; jump if negative (meaning an error occured)
	ret

_error:
	neg		rax
	mov		rdx, rax
	call	__errno_location
	mov		[rax], rdx
	mov		rax, -1
	ret

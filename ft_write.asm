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

section		.text
global		ft_write
extern 		__errno_location

ft_write:
	mov		rax, 1
	syscall
	test	rax, rax
	js		_error
	ret

_error:
	neg		rax
	mov		rdx, rax
	call	__errno_location
	mov		[rax], rdx
	mov		rax, -1
	ret

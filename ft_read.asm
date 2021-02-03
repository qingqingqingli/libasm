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


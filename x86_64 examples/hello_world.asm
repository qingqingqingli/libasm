; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
; To assemble and run:
;
;	 nasm -felf64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

;           global    _start

;           section   .text
; _start:   mov       rax, 1                  ; system call for write
;           mov       rdi, 1                  ; file handle 1 is stdout
;           mov       rsi, message            ; address of string to output
;           mov       rdx, 13                 ; number of bytes
;           syscall                           ; invoke operating system to do the write
;           mov       rax, 60                 ; system call for exit
;           mov       rdi, 0               	; exit code 0
;           ;xor       rdi, rdi                ; exit code 0
;           syscall                           ; invoke operating system to exit

;           section   .data
; message:  db        "Hello, World", 10      ; note the newline at the end

; db stands for "define bytes", which means we will define some raw bytes
; of data to insert into our code

; 10 is a newline character. Each character in the text is a single byte


; option 2

section	.data
		message:  db	"Hello, World", 10

section	.text
		global	_start

_start:
		call _printHello

		mov		rax, 60
		mov		rdi, 0
		syscall

_printHello		; called subroutine
		mov		rax, 1
		mov		rdi, 1
		mov		rsi, message
		mov		rdx, 13
		syscall
		ret		; return to where printHello was called


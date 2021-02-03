; rdi -> string
; rax -> return value
; current char -> byte[rdi + rax]

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


; nasm -felf64 ft_strlen.asm && gcc main.c ft_strlen.o && ./a.out
; rm *.o *.out

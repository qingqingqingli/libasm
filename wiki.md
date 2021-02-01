## Table of content

- [Registers]()
- [Instruction pointer]()
- [Memory access and stack operation]()
- [Functions]()
- []()
- []()
- []()
- [Resources]()

### Intro to assembly language

- Each assembly language is specific to a particular computer architecture. Assembly language is also called `symbolic machine code`. It usually has one statement per machine instruction (1:1).

- Because assembly depends on the machine code instructions, every assembler has its own assembly language which is designed for exactly one specific computer architecture.

### NASM (Netwide Assembler)

- Assembly code is converted into executable machine code by a utility program referred to as an assembler. The conversion process is referred to as `assembly`.

- NASM is an assembler for the x86 CPu architecture portable to nearly every modern platform, and with code generation for many platforms old and new.


### Operaands

- There are three kinds of operands:
	- Register operands
	- Memory operands
	- Immediate operands

### Registers

```asm
mov ebx, 123    ; ebx = 123 (assignment)
mov eax, ebx    ; eax = ebx (assignment)
add ebx, ecx    ; ebx += ecx (add in place)
sub ebx, edx    ; ebx -= edx (subtract in place)
mul ebx         ; eax *= ebx (always apply to the eax register)
div edx         ; eax /= edx (always apply to the eax register)
```

### Instruction pointer

- Assembly lacks the usual constructs for iteration, conditions and function calls. Instead, the programmer needs to build this kind of behaviour using `jump instructions`.

- `Instruction pointer` is an internal pointer in the process that is often labeled as `EIP`. As your program runs, this pointer hold the location for your machine code that the processor is executing. This means the processer can jump around to different location of code, by altering this pointer.

- You can't use this pointer like a register with `mov`, `add` and etc. Instead, the instruction pointer is changed by using `jump operations`.

> `jump instruction` overview

```asm
je	A, B 	; Jump if Equal
jne	A, B 	; Jump if Not Equal
jg	A, B 	; Jump if Greater
jge	A, B 	; Jump if Greater or Equal
jl	A, B 	; Jump if Less
jle	A, B 	; Jump if Less or Equal
```

> Example of `unconditional` jump instructions

```asm
global _start

section .text
_start:
    mov ebx, 42         ; exit status is 42
    mov eax, 1          ; sys_exit system call
    jmp skip            ; jump to "skip" label
    mov ebx, 13         ; exit status is 13
			; this reserves as an error check
			; if the jump works, the 'ebx' will stay as 42

skip:			; creating a label
    int 0x80
```

```shell
echo $?
42
```

> Example of `conditional` jump instructions

```asm
global _start

section .text
_start:
	mov ecx, 101		; set ecx to 101
	mov ebx, 42		; exit status is 42
	mov eax, 1		; sys_exit system call
	cmp ecx, 100		; compare ecx to 100 (set flags based on the comparison)
	jl skip			; jump if less than
	mov ebx, 13		; exit status is 13 (error check)

skip:				; creating a label
    int 0x80
```

```shell
echo $?
13
```

> Example of iteration

```asm
global _start

section .text
_start:
	mov ebx, 1		; start ebx at 1
	mov ecx, 6		; number of iterations

label:
	add ebx, ebx		; ebx += ebx
	dec ecx			; ecx -= 1 (decrement)
	cmp ecx, 0		; compare ecx with 0
	jg label		; jump to label if greater
	mov eax, 1		; sys_exit system call
	int 0x80
```

```shell
echo $?
64
```

### Memory access and stack operation

- Stack pointer (`ESP`) starts high in address in memory and moves down with pushes and back up with pops

- Push operation is the same as moving the stack pointer and moves a value to the where the stack pointer points to

```asm
; same effect
push 357

sub esp, 4
mov [esp], dword 357	; dword tells assembler that it's moving 4 bytes to the memory location

; same effect
pop eax			; it pops the top value on the stack to the eax register

mov eax, dword [esp]
add esp, 4


```

> Example of common data types

```asm

section	.data
	; bd is 1 byte

	name1 db "string"
	name2 db 0xff	; hex value
	name3 db 100

	; bw is 2 bytes
	name4 dw 0x1234
	name3 dw 1000

	; bd is 4 bytes
	name3 dd 10000
```


> Example of accessing memory

```asm
global _start

section .data
    addr db "yellow"        ; addr is a pointer to some memory address
                            ; which is a string taht contains the word "yellow"

section .text
_start:
    mov [addr], byte 'H'    ; access the 0 position & add 'H' to the position
    mov [addr + 5], byte '!'; access the 5th position ('w') & add '!' to the position
    mov eax, 4              ; sys_write system call
    mov ebx, 1              ; stdout file descriptor
    mov ecx, addr           ; bytes to sys_write
    mov edx, 6              ; number of bytes to write
    int 0x80                ; perform system call
    mov eax, 1              ; system_exit system call
    mov ebx, 0              ; exit status is 0
    int 0x80
```

```shell
hello
```

> Example of allocating memory on stack

```asm
global _start

_start:
	sub esp, 4			; allocat 4 bytes on the stack
	mov [esp], byte 'H'
	mov [esp + 1], byte 'e'
	mov [esp + 2], byte 'y'
	mov [esp + 3], byte '!'
	mov eax, 4			; sys_write
	mov ebx, 1			; stdout file descriptor
	mov ecx, esp			; pointer to bytes to sys_write
	mov edx, 4			; number of bytes to write
	int 0x80
	mov eax, 1			; sys_exit
	mov ebx, 0			; exit status is 0
    int 0x80
```

```shell
Hey
```

### Functions

- `call`: pushes EIP to stack, which allows you to jump back to the location you make the call. It allows the code to jump to and jump back to where the function was called.

- There is a practice to preserve the stack using the `base pointer` (`ebp`): `mov ebp, esp`. It will store the `esp` value in `ebp`, afterwards, you are free to work with `esp`

> Example of a function call

```asm
global _start

_start:
	call func
	mov eax, 1
	int 0x80

func:
	mov ebx, 42
	; pop eax	; ret does the same
	; jmp eax	; ret does the same
	ret		; ret stands for return
```

```shell
42
```

> Example of reserving stack pointer

```asm
global _start

_start:
	call func
	mov eax, 1
	mov ebx, 0
	int 0x80

func:
	push ebp		; preserve the old value of ebp onto the stack
	mov ebp, esp		; esp is the top of the stack
				; in this way, we can reserve the top of the stack before
				; reaching the return operation
	sub esp, 2		; allocate 2 bytes on the stack
	mov [esp], byte 'H'
	mov [esp + 1], byte 'i'
	mov eax, 4		; sys_write
	mov ebx, 1		; stdout file descriptor
	mov ecx, esp		; pointer to bytes to sys_write
	mov edx, 2		; number of bytes to write
	int 0x80
	mov esp, ebp		; store the right location on the top of the stack
	pop ebp			; pop the original value into ebp, so you don't mess up with the value
				; push & pop ebp help nested function calls without the functions
				; interfering with each other's stack
	ret
```

### Handle return value

- A function that pushes data to the stack is also responsible for removing that data

> Example of calling a function

```asm
global _start

_start:
	push 21
	call times2
	mov ebx, eax
	mov eax, 1
	int 0x80

times2:
	push ebp
	mov ebp, esp
	mov eax, [ebp+8]
	add eax, eax
	mov esp, ebp
	pop ebp
	ret
```

> Example of calling an external function in C

```asm
global main		; main lable for C
extern printf	; use an external function from C

section .data
	msg db "Testing %i...", 0x0a, 0x00
	; hold the format string to call printf with
	; 0x0a -> newline character
	; 0x00 -> end of string

main:
	push ebp
	mov ebp, esp
	push 123	; push in reverse order
	push msg	; push in reverse order
	call printf
	mov eax, 0	; exit status. 0 means things went correctly
	mov esp, ebp
	pop ebp
	ret
```

```shell

$ nasm -f elf32 ex10.asm -o ex10.o
$ gcc -m32 ex10.o -o ex10
$ ./ex10
Testing 123...
```

### Resources
- [Intro to x86 Assembly Language](https://www.youtube.com/watch?v=wLXIWKUWpSs&list=PLmxT2pVYo5LB5EzTPZGfFN0c2GDiSXgQe)
- [X86 assembly wikibook](https://en.wikibooks.org/wiki/X86_Assembly)
- [NASM tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
- [Introduction to x64 Assembly](https://software.intel.com/content/www/us/en/develop/articles/introduction-to-x64-assembly.html)
- [x64 Cheat Sheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)
- [x86 Assembly, 64 bit](https://aaronbloomfield.github.io/pdr/book/x86-64bit-asm-chapter.pdf)
- [x86-64 assembly from scratch](https://www.conradk.com/codebase/2017/06/06/x86-64-assembly-from-scratch/)
- [x86 Assembly Guide](https://www.cs.virginia.edu/~evans/cs216/guides/x86.html)
- [What is stack frame in assembly?](https://stackoverflow.com/questions/3699283/what-is-stack-frame-in-assembly)
- []()
- []()
- []()
- []()
- []()
- []()
- []()
- []()

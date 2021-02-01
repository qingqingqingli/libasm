## Table of content

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
$ echo $?
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
$ echo $?
13
```

### Resources
- [Intro to x86 Assembly Language (Part 1)](https://www.youtube.com/watch?v=wLXIWKUWpSs)
- [Intro to x86 Assembly Language (Part 2)](https://www.youtube.com/watch?v=cFGJhn97e3s)

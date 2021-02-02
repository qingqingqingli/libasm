## Table of content

- [Intro to assembly language]()
- [NASM (Netwide Assembler)]()
- [Compilation stages]()
- [80x86 instructions]()
- [X86 architecture]()
- [Operands]()
- [Registers]()
- [Instruction pointer]()
- [Memory access and stack operation]()
- [Functions]()
- [Handle return value]()
- [Resources]()

### Intro to assembly language

- Each assembly language is specific to a particular computer architecture. Assembly language is also called `symbolic machine code`. It usually has one statement per machine instruction (1:1).

- Because assembly depends on the machine code instructions, every assembler has its own assembly language which is designed for exactly one specific computer architecture.

- What’s right with assembly language: `speed`, `space`, `capability` and `knowledge`. Assembly language programs are often less than one-half the size of comparable HLL programs.

- Good assembly language programmers make better HLL programmers because they understand the limitations of the compiler and they know what it’s doing with their code. Those who don’t know assembly language will accept the poor performance their compiler produces and simply shrug it off.

### NASM (Netwide Assembler)

- Assembly code is converted into executable machine code by a utility program referred to as an assembler. The conversion process is referred to as `assembly`.

- NASM is an assembler for the x86 CPU architecture portable to nearly every modern platform, and with code generation for many platforms old and new.


### Compilation stages

[![compilation_stage](https://github.com/qingqingqingli/libasm/blob/main/images/compilation_stages.png)](https://github.com/qingqingqingli/libasm)


### 80x86 instructions

- 80x86 instructions can be (roughly) divided into eight different classes:

1) Data movement instructions
	- `mov`, `lea`, `les`, `push`, `pop`, `pushf`, `popf`
2) Conversions
	- `cbw`, `cwd`, `xlat`
3) Arithmetic instructions
	- `add`, `inc`, `sub`, `dec`, `cmp`, `neg`, `mul`, `imul`, `div`, `idiv`
4) Logical, shift, rotate, and bit instructions
	- `and`, `or`, `xor`, `not`, `shl`, `shr`, `rcl`, `rcr`
5) I/O instructions
	- `in`, `out`
6) String instructions
	- `movs`, `stos`, `lods`
7) Program flow control instructions
	- `jmp`, `call`, `ret`, conditional jumps
8) Miscellaneous instructions.
	- `clc`, `stc`, `cmc`

### X86 architecture

- The x86 architecture has 8 General-Purpose Register (GPR), 6 Segment Registers, 1 Flags Register and an Instruction Pointer. 64-bit x86 has additional register.

- **General-Purpose Register(GPR) - 16-bit naming convention**

1. `Accumulator register` (`AX`). Used in arithmetic operations
2. `Counter register` (`CX`). Used in shift/rotate instructions and loops.
3. `Data register` (`DX`). Used in arithmetic operations and I/O operations.
4. `Base register` (`BX`). Used as a pointer to data (located in segment register DS, when in segmented mode).
5. `Stack Pointer register` (`SP`). Pointer to the top of the stack.
6. `Stack Base Pointer register` (`BP`). Used to point to the base of the stack.
7. `Source Index register` (`SI`). Used as a pointer to a source in stream operations.
8. `Destination Index register` (`DI`). Used as a pointer to a destination in stream operations.

- In `32-bit` mode, this two-letter abbreviation is prefixed with an 'E'
(extended). In the `64-bit` version, the 'E' is replaced with an 'R' (register)

- 64-bit x86 adds `8 more general-purpose registers`, named R8, R9, R10 and so on up to R15.

    9. `R8–R15` are the new 64-bit registers.
    10. `R8D–R15D` are the lowermost 32 bits of each register.
    11. `R8W–R15W` are the lowermost 16 bits of each register.
    12. `R8B–R15B` are the lowermost 8 bits of each register.

- **Segment Registers**

	- `Stack Segment` (`SS`). Pointer to the stack.
	- `Code Segment` (`CS`). Pointer to the code.
	- `Data Segment` (`DS`). Pointer to the data.
	- `Extra Segment` (`ES`). Pointer to extra data ('E' stands for 'Extra').
	- `F Segment` (`FS`). Pointer to more extra data ('F' comes after 'E').
	- `G Segment` (`GS`). Pointer to still more extra data ('G' comes after 'F').

- **EFLAGS Register**

	- The EFLAGS is a `32-bit` register used as a collection of bits representing Boolean values to store the results of operations and the state of the processor.

- **Instruction Pointer**

	- `RIP`: This is the full 64-bit instruction pointer and should be used instead of EIP.

### Operands

- There are three kinds of operands:
	- Register operands
	- Memory operands
	- Immediate operands


### Registers

- A register is a storage inside the processor core. It can be accessed at much higher speeds than conventional memory.

```asm
mov ebx, 123    ; ebx = 123 (assignment)
mov eax, ebx    ; eax = ebx (assignment)
add ebx, ecx    ; ebx += ecx (add in place)
sub ebx, edx    ; ebx -= edx (subtract in place)
mul ebx         ; eax *= ebx (always apply to the eax register)
div edx         ; eax /= edx (always apply to the eax register)
```

- **How to pick different registers?** [source](https://www.swansontec.com/sregisters.html)

	- Using registers according to Intel's original plan allows the code to take full advantage of these optimizations.

	- `EAX: The Accumulator`
		- Most calculations occur in the accumulator.
		- All nine basic operations (ADD, ADC, AND, CMP, OR, SBB, SUB, TEST, and XOR) have special one-byte opcodes for operations between the accumulator and a constant.
		- Specialized operations, such as `multiplication`, `division`, `sign extension`, and `BCD correction` can only occur in the accumulator.
		- In your code, **try to perform as much work in the accumulator as possible**. As you will see, the remaining seven general-purpose registers exist primarily to support the calculation occurring in the accumulator.

	- `EDX: The Data Register`
		- EDX, is most closely tied to the accumulator. Instructions that deal with over sized data items, such as `multiplication`, `division`, `CWD`, and `CDQ`, store the most significant bits in the data register and the least significant bits in the accumulator.
		- The data register also plays a part in `IO instructions`. In this case, the accumulator holds the data to read or write from the port, and the data register holds the port address.
		- In your code, the data register is most useful for **storing data related to the accumulator's calculation**.

	- `ECX: The Count Register`
		- ECX, is the x86 equivalent of the ubiquitous variable `i`. **Every counting-related instruction in the x86 uses ECX.**
		- The most obvious counting instructions are `LOOP`, `LOOPZ`, and `LOOPNZ`. Another counter-based instruction is `JCXZ`, which, as the name implies, jumps when the counter is 0.
		- The count register also appears in some `bit-shift` operations, where it holds the number of shifts to perform.
		- Finally, the count register controls the string instructions through the `REP`, `REPE`, and `REPNE` prefixes. In this case, the count register determines the maximum number of times the operation will repeat.
		- The only problem is that **this register counts downward** instead of up as in high level languages.

	- `EDI: The Destination Index`
		- Every loop that generates data must store the result in memory, and doing so requires a moving pointer. The destination index, EDI, is that pointer.
		- **The destination index holds the implied write address of all string operations.**
		- Many coders treat the destination index as no more than extra storage space. This is a mistake. Use the stack or some other register for storage, and **use EDI as your global write pointer**.

	- `ESI: The Source Index`
		- ESI has the same properties as the destination index. The only difference is that **the source index is for reading instead of writing**. Although all data-processing routines write, not all read, so the source index is not as universally useful.

		- In situations where your code does not read any sort of data, using the source index for convenient storage space is acceptable.

	- `ESP and EBP: The Stack Pointer and the Base Pointer`
		- These two registers are the heart of the x86 function-call mechanism. When a block of code calls a function, it pushes the parameters and the return address on the stack.
		- Once inside, function sets the base pointer equal to the stack pointer and then places its own internal variables on the stack. From that point on, the function refers to its parameters and variables relative to the base pointer rather than the stack pointer.
		- **In your code, there is never a reason to use the stack pointer for anything other than the stack.** The base pointer, however, is up for grabs. If your routines pass parameters by register instead of by stack (they should), there is no reason to copy the stack pointer into the base pointer. The base pointer becomes a free register for whatever you need.

	- `EBX: The Base Register`
		- Of all the general-purpose registers, EBX is the only register without an important dedicated purpose. It is a good place to store an extra pointer or calculation step, but not much more.


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
global main		; main label for C
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

###

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
- [Use of EAX register in system calls](https://stackoverflow.com/questions/47692516/what-is-the-use-of-eax-register-in-the-context-of-system-calls-in-linux)
- [The Art of Picking Intel Registers](https://www.swansontec.com/sregisters.html)
- []()
- []()

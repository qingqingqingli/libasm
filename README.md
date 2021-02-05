[![Logo](https://github.com/qingqingqingli/readme_images/blob/master/codam_logo_1.png)](https://github.com/qingqingqingli/libasm)

# libasm

***The aim of this project is to get familiar with assembly language.***

## Technical considerations

- The project is written in `64 bits` ASM, compiled with [NASM](https://www.nasm.us/)

- It follows the `Intel` syntax

- The following functions are rewritten in assembly:
	- `ft_strlen`: calculate the length of a string
	- `ft_strcpy`: copy a string
	- `ft_strcmp`: compare two strings
	- `ft_write`: write to a file descriptor
	- `ft_read`: read from a file descriptor
	- `ft_strdup`: duplicate a string

- `Errors` during syscalls need to be checked and `Errno` to be set properly

## wiki

- You can check my learnings on assembly on the [wiki page](https://github.com/qingqingqingli/libasm/wiki#calling-an-asm-function-from-c-source)

[![Logo](https://github.com/qingqingqingli/readme_images/blob/master/codam_logo_1.png)](https://github.com/qingqingqingli/libasm)

# libasm

***The aim of this project is to get familiar with assembly language.***

## Technical considerations

- The project is written in `64 bits` ASM, compiled with [NASM](https://www.nasm.us/)

- It follows the `Intel` syntax

- The following functions are rewritten in assembly:
	- `ft_strlen`
	- `ft_strcpy`
	- `ft_strcmp`
	- `ft_write`
	- `ft_read`
	- `ft_strdup`

- `Errors` during syscalls need to be checked and set properly

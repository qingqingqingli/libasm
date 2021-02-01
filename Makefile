all:
	nasm -f elf64 -o ft_strlen.o ft_strlen.asm
	ld -o ft_strlen ft_strlen.o

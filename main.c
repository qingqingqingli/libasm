#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *s);

int main(void)
{
	char *string1 = "123456789";
	char *string2 = "asdfasdfasdfasdf";
	char *string3 = "";
	char *string4 = "------------------9";
	char *string5 = NULL;

	ft_strlen(string1);
	printf("original is [%ld] \t test is [%ld]\n", strlen(string1), ft_strlen(string1));
	printf("original is [%ld] \t test is [%ld]\n", strlen(string2), ft_strlen(string2));
	printf("original is [%ld] \t test is [%ld]\n", strlen(string3), ft_strlen(string3));
	printf("original is [%ld] \t test is [%ld]\n", strlen(string4), ft_strlen(string4));
	//printf("original is [%ld] \t test is [%ld]\n", strlen(string5), ft_strlen(string5)); // will seg
	return 0;
}

// nasm -felf64 ft_strlen.asm && gcc main.c ft_strlen.o && ./a.out

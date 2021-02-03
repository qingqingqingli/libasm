#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 200

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);

int main(void)
{
	char *string1 = "123456789";
	char *string2 = "asdfasdfasdfasdf";
	char *string3 = "";
	char *string4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	char *string5 = NULL;

	// printf("--------------ft_strlen---------------\n");
	// printf("original is [%ld] \t test is [%ld]\n", strlen(string1), ft_strlen(string1));
	// printf("original is [%ld] \t test is [%ld]\n", strlen(string2), ft_strlen(string2));
	// printf("original is [%ld] \t test is [%ld]\n", strlen(string3), ft_strlen(string3));
	// printf("original is [%ld] \t test is [%ld]\n", strlen(string4), ft_strlen(string4));
	// //printf("original is [%ld] \t test is [%ld]\n", strlen(string5), ft_strlen(string5)); // will seg

	printf("--------------ft_strcpy---------------\n");

	char *dest = (char *)malloc(sizeof(char) * SIZE);
	// strcpy(dest, string1);
	// printf("original is \t [%s]\n", dest);
	ft_strcpy(dest, string1);
	printf("copy is \t [%s]\n", dest);
	printf("[%c]\n", string1[9]);
	printf("[%c]\n", dest[9]);

	// strcpy(dest, string2);
	// printf("original is \t [%s]\n", dest);
	ft_strcpy(dest, string2);
	printf("copy is \t [%s]\n", dest);

	// strcpy(dest, string3);
	// printf("original is \t [%s]\n", dest);
	ft_strcpy(dest, string3);
	printf("copy is \t [%s]\n", dest);

	// strcpy(dest, string4);
	// printf("original is \t [%s]\n", dest);
	ft_strcpy(dest, string4);
	printf("copy is \t [%s]\n", dest);

	// strcpy(dest, string5);
	// printf("original is \t [%s]\n", dest);
	// ft_strcpy(dest, string5);
	// printf("copy is \t [%s]\n", dest);

	free(dest);
	return 0;
}

// nasm -felf64 ft_strlen.asm && gcc main.c ft_strlen.o && ./a.out
// nasm -felf64 ft_strcpy.asm && gcc main.c ft_strcpy.o && ./a.out

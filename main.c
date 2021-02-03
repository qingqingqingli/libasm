#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 200

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	char *str1 = "123456789";
	char *str2 = "asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	char *str5 = NULL;

	// printf("--------------ft_strlen---------------\n");
	// printf("original is [%ld] \t test is [%ld]\n", strlen(str1), ft_strlen(str1));
	// printf("original is [%ld] \t test is [%ld]\n", strlen(str2), ft_strlen(str2));
	// printf("original is [%ld] \t test is [%ld]\n", strlen(str3), ft_strlen(str3));
	// printf("original is [%ld] \t test is [%ld]\n", strlen(str4), ft_strlen(str4));
	// //printf("original is [%ld] \t test is [%ld]\n", strlen(str5), ft_strlen(str5)); // will seg

	// printf("--------------ft_strcpy---------------\n");

	// char *dest = (char *)malloc(sizeof(char) * SIZE);
	// // strcpy(dest, str1);
	// // printf("original is \t [%s]\n", dest);
	// ft_strcpy(dest, str1);
	// printf("custom is \t [%s]\n", dest);

	// // strcpy(dest, str2);
	// // printf("original is \t [%s]\n", dest);
	// ft_strcpy(dest, str2);
	// printf("custom is \t [%s]\n", dest);

	// // strcpy(dest, str3);
	// // printf("original is \t [%s]\n", dest);
	// ft_strcpy(dest, str3);
	// printf("custom is \t [%s]\n", dest);

	// // strcpy(dest, str4);
	// // printf("original is \t [%s]\n", dest);
	// ft_strcpy(dest, str4);
	// printf("custom is \t [%s]\n", dest);

	// strcpy(dest, str5);
	// printf("original is \t [%s]\n", dest);
	// ft_strcpy(dest, str5);
	// printf("custom is \t [%s]\n", dest);

	// free(dest);

	printf("--------------ft_strcmp---------------\n");

	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str1, str2), ft_strcmp(str1, str2));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str3), ft_strcmp(str2, str3));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str4), ft_strcmp(str3, str4));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str4, str3), ft_strcmp(str4, str3));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str2), ft_strcmp(str3, str2));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str1), ft_strcmp(str2, str1));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str1, str1), ft_strcmp(str1, str1));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str2), ft_strcmp(str2, str2));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str3), ft_strcmp(str3, str3));
	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str4, str4), ft_strcmp(str4, str4));

	// printf("original is \t [%d]\n", strcmp(str5, str5));
	// printf("original is \t [%d]\n", strcmp(str4, str5));
	// printf("original is \t [%d]\n", strcmp(str5, str4));
	return 0;
}

// nasm -felf64 ft_strlen.asm && gcc main.c ft_strlen.o && ./a.out
// nasm -felf64 ft_strcpy.asm && gcc main.c ft_strcpy.o && ./a.out
// nasm -felf64 ft_strcmp.asm && gcc main.c ft_strcmp.o && ./a.out

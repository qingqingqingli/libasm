#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);

// void	strlen_test()
// {

// 	// printf("--------------ft_strlen---------------\n");

// 	char *str1 = "123456789";
// 	char *str2 = "asdfasdfasdfasdf";
// 	char *str3 = "";
// 	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
// 	char *str5 = NULL;

// 	printf("original is \t [%ld] \ntest is \t [%ld]\n", strlen(str1), ft_strlen(str1));
// 	printf("original is \t [%ld] \ntest is \t [%ld]\n", strlen(str2), ft_strlen(str2));
// 	printf("original is \t [%ld] \ntest is \t [%ld]\n", strlen(str3), ft_strlen(str3));
// 	printf("original is \t [%ld] \ntest is \t [%ld]\n", strlen(str4), ft_strlen(str4));
// 	//printf("original is \t [%ld] \ntest is \t [%ld]\n", strlen(str5), ft_strlen(str5)); // will seg

// }

// int		strcpy_test()
// {
// 	printf("--------------ft_strcpy---------------\n");

// 	char	dst_one[250];
// 	char	dst_two[250];

// 	char *str1 = "123456789";
// 	char *str2 = "asdfasdfasdfasdf";
// 	char *str3 = "";
// 	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
// 	char *str5 = "test2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatie";
// 	char *str6 = NULL;

// 	printf("original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str1), ft_strcpy(dst_two, str1));
// 	printf("original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str2), ft_strcpy(dst_two, str2));
// 	printf("original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str3), ft_strcpy(dst_two, str3));
// 	printf("original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str4), ft_strcpy(dst_two, str4));
// 	printf("original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str5), ft_strcpy(dst_two, str5));
// 	// printf("original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str6), ft_strcpy(dst_two, str6));
// }

void	strcmp_test()
{
	// printf("--------------ft_strcmp---------------\n");

	char *str1 = "666123456789";
	char *str2 = "666asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	char *str5 = NULL;

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

	// printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str5, str4), ft_strcmp(str5, str4));
}

int 	main(void)
{
	// strlen_test();
	// strcpy_test();
	strcmp_test();
	return 0;
}

// nasm -felf64 ft_strlen.asm && gcc main.c ft_strlen.o && ./a.out
// nasm -felf64 ft_strcpy.asm && gcc main.c ft_strcpy.o && ./a.out
// nasm -felf64 ft_strcmp.asm && gcc main.c ft_strcmp.o && ./a.out
// rm *.o *.out

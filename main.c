#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

extern int errno;

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_read(int fd, void *buf, size_t count);

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

// void	strcmp_test()
// {
// 	// printf("--------------ft_strcmp---------------\n");

// 	char *str1 = "6666123456789";
// 	char *str2 = "6666asdfasdfasdfasdf";
// 	char *str3 = "";
// 	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
// 	char *str5 = NULL;

// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str1, str2), ft_strcmp(str1, str2));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str3), ft_strcmp(str2, str3));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str4), ft_strcmp(str3, str4));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str4, str3), ft_strcmp(str4, str3));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str2), ft_strcmp(str3, str2));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str1), ft_strcmp(str2, str1));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str1, str1), ft_strcmp(str1, str1));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str2), ft_strcmp(str2, str2));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str3), ft_strcmp(str3, str3));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str4, str4), ft_strcmp(str4, str4));
// 	printf("original is \t [%d] \t custom is \t [%d]\n", strcmp(str5, str4), ft_strcmp(str5, str4));
// }

// void	read_test(char **argv)

// {	int		fd_one = 0;
// 	int		fd_two = 0;
// 	int		fd_three = 0;
// 	int		fd_four = 0;
// 	int		fd_five = 0;
// 	char	*buf_one = malloc(sizeof(char) * 50);
// 	char	*buf_two = malloc(sizeof(char) * 50);
// 	int		n;
// 	int		error;

// 	fd_one = open(argv[1], O_RDONLY);
// 	fd_two = open(argv[2], O_RDONLY);
// 	fd_three = open(argv[3], O_RDONLY);
// 	fd_four = open(argv[1], O_RDONLY);
// 	fd_five = open(argv[2], O_RDONLY);
// 	n = 100;
// 	printf("Test 1 -  read %zd\n", read(fd_one, buf_one, n));
// 	printf("buffer    read = %s", buf_one);
// 	// printf("Test 1 - ft_read %d\n", ft_read(fd_two, buf_two, n));
// 	// printf("buffer ft_read = %s", buf_two);
// 	printf("\n\n");
// 	printf("Test 2 -    read %zd\n", read(fd_three, buf_one, n));
// 	// // printf("Test 2 - ft_read %d\n", ft_read(fd_three, buf_two, n));
// 	error = errno;
// 	printf("errno - %d - %s\n\n", error, strerror(error));
// 	printf("Test 3 -  read %zd\n", read(fd_four, 0, n));
// 	// // printf("Test 3 - ft_read %d\n", ft_read(fd_five, 0, n));
// 	error = errno;
// 	printf("errno - %d - %s\n", error, strerror(error));
// }

void 	read_test(void)
{
	printf("--------------ft_read---------------\n");

	char *file1 = "";
	char *file2 = "wiki.md";
	char *buf1 = malloc(sizeof(char) * 50);
	char *buf2 = malloc(sizeof(char) * 50);

	int fd1 = open(file1, O_RDONLY);
	int	fd2 = open(file2, O_RDONLY);
	errno = 0;
	printf("original return value \t [%zd]\n", ft_read(fd1, buf1, 40));
	printf("original read \t\t [%s]\n", buf1);
	printf("original errno \t\t [%d] \t [%s]\n", errno, strerror(errno));

	free(buf1);
	free(buf2);
}

int 	main(void)
{
	// strlen_test();
	// strcpy_test();
	// strcmp_test();
	read_test();
	return 0;
}

// nasm -felf64 ft_strlen.asm && gcc main.c ft_strlen.o && ./a.out
// nasm -felf64 ft_strcpy.asm && gcc main.c ft_strcpy.o && ./a.out
// nasm -felf64 ft_strcmp.asm && gcc main.c ft_strcmp.o && ./a.out
// nasm -felf64 ft_read.asm && gcc -no-pie main.c ft_read.o && ./a.out
// rm *.o *.out

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define Black "\033[0;30m"
#define Red "\033[0;31m"
#define Green "\033[0;32m"
#define Yellow "\033[0;33m"
#define Blue "\033[0;34m"
#define Purple "\033[0;35m"
#define Cyan "\033[0;36m"

extern int errno;

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
char *ft_strdup(const char *s);

// void	strlen_test()
// {

// 	printf("--------------ft_strlen---------------\n");

// 	char *str1 = "123456789";
// 	char *str2 = "asdfasdfasdfasdf";
// 	char *str3 = "";
// 	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
// 	char *str5 = NULL;

// 	printf("Original is \t [%ld] \ntest is \t [%ld]\n", strlen(str1), ft_strlen(str1));
// 	printf("Original is \t [%ld] \ntest is \t [%ld]\n", strlen(str2), ft_strlen(str2));
// 	printf("Original is \t [%ld] \ntest is \t [%ld]\n", strlen(str3), ft_strlen(str3));
// 	printf("Original is \t [%ld] \ntest is \t [%ld]\n", strlen(str4), ft_strlen(str4));
// 	//printf("Original is \t [%ld] \ntest is \t [%ld]\n", strlen(str5), ft_strlen(str5)); // will seg

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

// 	printf("Original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str1), ft_strcpy(dst_two, str1));
// 	printf("Original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str2), ft_strcpy(dst_two, str2));
// 	printf("Original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str3), ft_strcpy(dst_two, str3));
// 	printf("Original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str4), ft_strcpy(dst_two, str4));
// 	printf("Original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str5), ft_strcpy(dst_two, str5));
// 	// printf("Original is \t [%s] \ntest is \t [%s]\n", strcpy(dst_two, str6), ft_strcpy(dst_two, str6));
// }

// void	strcmp_test()
// {
// 	// printf("--------------ft_strcmp---------------\n");

// 	char *str1 = "6666123456789";
// 	char *str2 = "6666asdfasdfasdfasdf";
// 	char *str3 = "";
// 	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
// 	char *str5 = NULL;

// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str1, str2), ft_strcmp(str1, str2));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str3), ft_strcmp(str2, str3));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str4), ft_strcmp(str3, str4));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str4, str3), ft_strcmp(str4, str3));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str2), ft_strcmp(str3, str2));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str1), ft_strcmp(str2, str1));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str1, str1), ft_strcmp(str1, str1));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str2, str2), ft_strcmp(str2, str2));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str3, str3), ft_strcmp(str3, str3));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str4, str4), ft_strcmp(str4, str4));
// 	printf("Original is \t [%d] \t custom is \t [%d]\n", strcmp(str5, str4), ft_strcmp(str5, str4));
// }

// void 	read_test(void)
// {
// 	printf("--------------ft_read---------------\n\n");

// 	char *file1 = "main.c";
// 	char *file2 = "";
// 	char *buf1 = malloc(sizeof(char) * 50);
// 	char *buf2 = malloc(sizeof(char) * 50);
// 	int fd1 = open(file1, O_RDONLY);
// 	int	fd2 = open(file2, O_RDONLY);

// 	errno = 0;
// 	printf(Blue "Original return value \t [%zd]\n", read(fd1, buf1, 40));
// 	printf("Original read \t\t [%s]\n", buf1);
// 	printf("Original errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	errno = 0;
// 	printf(Purple "copy return value \t [%zd]\n", ft_read(fd1, buf1, 40));
// 	printf("copy read \t\t [%s]\n", buf1);
// 	printf("copy errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	printf("\n");

// 	errno = 0;
// 	printf(Blue "Original return value \t [%zd]\n", read(fd2, buf2, 40));
// 	printf("Original read \t\t [%s]\n", buf2);
// 	printf("Original errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	errno = 0;
// 	printf(Purple "copy return value \t [%zd]\n", ft_read(fd2, buf2, 40));
// 	printf("copy read \t\t [%s]\n", buf2);
// 	printf("copy errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	close(fd2);
// 	printf("\n");

// 	errno = 0;
// 	printf(Blue "Original return value \t [%zd]\n", read(fd1, 0, 40));
// 	printf("Original errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	errno = 0;
// 	printf(Purple "copy return value \t [%zd]\n", ft_read(fd1, 0, 40));
// 	printf("copy errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	close(fd1);
// 	printf("\n");

// 	errno = 0;
// 	printf(Blue "Original return value \t [%zd]\n", read(0, buf1, 40));
// 	printf("Original errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	errno = 0;
// 	printf(Purple "copy return value \t [%zd]\n", ft_read(0, buf1, 40));
// 	printf("copy errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	printf("\n");

// 	free(buf1);
// 	free(buf2);
// }

// void	write_test()
// {
// 	printf("--------------ft_write---------------\n\n");
// 	char *buf = "TEST SENTENCE TO TEST WRITE.\n";
// 	int fd = 1;
// 	int n = strlen(buf);
// 	errno = 0;
// 	printf("Original return value \t [%zd]\n", write(fd, buf, n));
// 	printf("Copy return value \t [%zd]\n", ft_write(fd, buf, n));
// 	printf("\n");
// 	errno = 0;
// 	printf(Blue "Original return value \t [%zd]\n", write(fd, 0, n));
// 	printf("Original errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	printf("\n");
// 	errno = 0;
// 	printf(Yellow "Copy return value \t [%zd]\n", ft_write(fd, 0, n));
// 	printf("copy errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	printf("\n");
// 	errno = 0;
// 	printf(Blue "Original return value \t [%zd]\n", write(-1, 0, n));
// 	printf("Original errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	printf("\n");
// 	errno = 0;
// 	printf(Yellow "Copy return value \t [%zd]\n", ft_write(-1, 0, n));
// 	printf("Copy errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
// 	printf("\n");
// }

void	strdup_test()
{
	printf("--------------ft_strdup---------------\n\n");

	char *str1 = "123456789";
	char *str2 = "asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	char *str5 = NULL;

	char *dest1 = ft_strdup(str1);
	char *dest2 = ft_strdup(str2);
	char *dest3 = ft_strdup(str3);
	char *dest4 = ft_strdup(str4);
	char *dest5 = ft_strdup(str5);

	// errno = 0;
	// printf(Blue "Original return \t [%s]\n", strdup(str1));
	// printf("Original errno \t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf(Yellow "Copy return \t\t [%s]\n", dest1);
	printf("Copy errno \t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	// errno = 0;
	// printf(Blue "Original return \t [%s]\n", strdup(str2));
	// printf("Original errno \t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf(Yellow "Copy return \t\t [%s]\n", dest2);
	printf("Copy errno \t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	// errno = 0;
	// printf(Blue "Original return \t [%s]\n", strdup(str3));
	// printf("Original errno \t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf(Yellow "Copy return \t\t [%s]\n", dest3);
	printf("Copy errno \t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	// errno = 0;
	// printf(Blue "Original return \t [%s]\n", strdup(str4));
	// printf("Original errno \t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf(Yellow "Copy return \t\t [%s]\n", dest4);
	printf("Copy errno \t [%d] \t [%s]\n", errno, strerror(errno));
	// printf("Original return \t [%s]\n", strdup(str5)); // seg fault
	printf("Copy return \t [%s]\n", dest5); // seg fault

	// free(dest1);
	// free(dest2);
	// free(dest3);
	// free(dest4);

}

int 	main(void)
{
	// strlen_test();
	// strcpy_test();
	// strcmp_test();
	// read_test();
	// write_test();
	strdup_test();
	return 0;
}

// nasm -felf64 ft_strlen.asm && gcc main.c ft_strlen.o && ./a.out
// nasm -felf64 ft_strcpy.asm && gcc main.c ft_strcpy.o && ./a.out
// nasm -felf64 ft_strcmp.asm && gcc main.c ft_strcmp.o && ./a.out
// nasm -felf64 ft_read.asm && gcc -no-pie main.c ft_read.o && ./a.out
// nasm -felf64 ft_write.asm && gcc -no-pie main.c ft_write.o && ./a.out
// nasm -felf64 ft_strdup.asm && gcc -no-pie main.c ft_strdup.o && ./a.out
// rm *.o *.out

// nasm -felf64 ft_strdup.asm && gcc -no-pie main.c ft_strlen.o ft_strcpy.o ft_strdup.o && ./a.out

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int		ft_strlen(char *string);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
int		ft_read(int fd, void *buf, int n);
int		ft_write(int fd, void *buf, int n);

void	ft_strlen_test(void)
{
	printf("Test 1 - strlen %lu\n", strlen("test1"));
	printf("Test 1 - ft_strlen %d\n", ft_strlen("test1"));
	printf("\n\n");
	printf("Test 2 - strlen %lu\n", strlen("test2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatie"));
	printf("Test 2 - ft_strlen %d\n", ft_strlen("test2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatie"));
	printf("\n\n");
	printf("Test 3 - strlen %lu\n", strlen(""));
	printf("Test 3 - ft_strlen %d\n", ft_strlen(""));
}

void	ft_strcpy_test(void)
{
	char	dst_one[250];
	char	dst_two[250];

	printf("Test 1 - strcpy %s\n", strcpy(dst_one, "test1"));
	printf("Test 1 - ft_strcpy %s\n", ft_strcpy(dst_two, "test1"));
	printf("\n\n");
	printf("Test 2 - strcpy %s\n", strcpy(dst_one, "test2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatie"));
	printf("Test 2 - ft_strcpy %s\n", ft_strcpy(dst_two, "test2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatie"));
	printf("\n\n");
	printf("Test 3 - strcpy %s\n", strcpy(dst_one, ""));
	printf("Test 3 - ft_strcpy %s\n", ft_strcpy(dst_two, ""));
}

void	ft_strcmp_test(void)
{
	char *s1 = malloc(sizeof(char) * 10);
	char *s2 = malloc(sizeof(char) * 10);
	char *s3 = malloc(sizeof(char) * 10);
	char *s4 = malloc(sizeof(char) * 10);

	s1 = "z";
	s2 = "a";
	s3 = "test1";
	s4 = "test";
	printf("Test 1 - strcmp %d\n", strcmp("", "hallo"));
	printf("Test 1 - ft_strcmp %d\n", ft_strcmp("", "hallo"));
	printf("\n\n");
	printf("Test 2 - strcmp %d\n", strcmp("test1", ""));
	printf("Test 2 - ft_strcmp %d\n", ft_strcmp("test1", ""));
	printf("\n\n");
	printf("Test 3 - strcmp %d\n", strcmp("\xff", "\xff"));
	printf("Test 3 - ft_strcmp %d\n", ft_strcmp("\xff", "\xff"));
	printf("\n\n");
	printf("Test 4 - strcmp %d\n", strcmp(s3, s4));
	printf("Test 4 - ft_strcmp %d\n", ft_strcmp(s3, s4));
}

void	ft_strdup_test(void)
{
	printf("Test 1 - strdup %s\n", strdup("test1"));
	printf("Test 1 - ft_strdup %s\n", ft_strdup("test1"));
	printf("\n\n");
	printf("Test 2 - strdup %s\n", strdup("test2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatie"));
	printf("Test 2 - ft_strdup %s\n", ft_strdup("test2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatietest2 met spatie"));
	printf("\n\n");
	printf("Test 3 - strdup %s\n", strdup(""));
	printf("Test 3 - ft_strdup %s\n", ft_strdup(""));
}

void	ft_read_test(char **argc)
{
	int		fd_one;
	int		fd_two;
	int		fd_three;
	int		fd_four;
	int		fd_five;
	char	*buf_one = malloc(sizeof(char) * 50);
	char	*buf_two = malloc(sizeof(char) * 50);
	int		n;
	int		error;

	fd_one = open(argc[1], O_RDONLY);
	fd_two = open(argc[2], O_RDONLY);
	fd_three = open(argc[3], O_RDONLY);
	fd_four = open(argc[1], O_RDONLY);
	fd_five = open(argc[2], O_RDONLY);
	n = 31;
	printf("Test 1 -  read %zd\n", read(fd_one, buf_one, n));
	printf("buffer    read = %s", buf_one);
	printf("Test 1 - ft_read %d\n", ft_read(fd_two, buf_two, n));
	printf("buffer ft_read = %s", buf_two);
	printf("\n\n");
	printf("Test 2 -    read %zd\n", read(fd_three, buf_one, n));
	printf("Test 2 - ft_read %d\n", ft_read(fd_three, buf_two, n));
	error = errno;
	printf("errno - %d - %s\n\n", error, strerror(error));
	printf("Test 3 -  read %zd\n", read(fd_four, 0, n));
	printf("Test 3 - ft_read %d\n", ft_read(fd_five, 0, n));
	error = errno;
	printf("errno - %d - %s\n", error, strerror(error));
}

void	ft_write_test(void)
{
	int		fd;
	char	buf_one[] = "Test string met write\n";
	char	buf_two[] = "Test string met write\n";
	int		n;
	int		error;

	fd = 1;
	n = 22;
	printf("Test 1 - write %zd\n", write(fd, buf_one, n));
	printf("Test 1 - ft_write %d\n", ft_write(fd, buf_two, n));
	printf("\n\n");
	printf("Test 2 - write %zd\n", write(fd, 0, n));
	printf("Test 2 - ft_write %d\n", ft_write(fd, 0, n));
	error = errno;
	printf("errno - %d - %s\n", error, strerror(error));
}

int		main(int argv, char **argc)
{
	if (argv)
	printf("*********** TEST FT_STRLEN ***********\n");
	ft_strlen_test();
	printf("\n\n\n\n");
	printf("*********** TEST FT_STRCPY ***********\n");
	ft_strcpy_test();
	printf("\n\n\n\n");
	printf("*********** TEST FT_STRCMP ***********\n");
	ft_strcmp_test();
	printf("\n\n\n\n");
	printf("*********** TEST FT_STRDUP ***********\n");
	ft_strdup_test();
	printf("\n\n\n\n");
	printf("*********** TEST FT_READ ***********\n");
	ft_read_test(argc);
	printf("\n\n\n\n");
	printf("*********** TEST FT_WRITE ***********\n");
	ft_write_test();
}

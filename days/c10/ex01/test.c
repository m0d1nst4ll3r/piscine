#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*basename(char *path);
char	*dirname(char *path);

int	main(int ac, char **av)
{
	/*int		fd;
	char	t[] = "coucou";
	char	t1[] = "test";
	char	t2[] = "test/";
	char	t3[] = "ft_strcat";
	char	t4[] = "test/z";
	char	t5[] = "test/walla";
	char	t6[] = "../ex01/ft_strcat";

	printf("%s, %s\n", dirname(t), basename(t));
	printf("%s, %s\n", dirname(t1), basename(t1));
	printf("%s, %s\n", dirname(t2), basename(t2));
	printf("%s, %s\n", dirname(t3), basename(t3));
	printf("%s, %s\n", dirname(t4), basename(t4));
	printf("%s, %s\n", dirname(t5), basename(t5));
	printf("%s, %s\n", dirname(t6), basename(t6));*/
	while (*av[1])
		write(1, av[1]++, 1);

	/*fd = open("test", O_RDONLY | O_DIRECTORY);
	printf("fd[%d] errno[%d]\n", fd, errno);
	fd = open("Makefile", O_RDONLY | O_DIRECTORY);
	printf("fd[%d] errno[%d]\n", fd, errno);
	fd = open("hahahahahah", O_RDONLY | O_DIRECTORY);
	printf("fd[%d] errno[%d]\n", fd, errno);*/
}

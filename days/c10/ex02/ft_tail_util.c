#include "ft_tail.h"

//	chan allows for printing on stderr
void	ft_putstr(char *str, int chan)
{
	while (*str)
		write(chan, str++, 1);
}

//	Returns file descriptor after opening
//	or STDIN_FILENO if name points to a NULL adress
int	ft_open(char *file)
{
	int	fd;

	if (! file)
		return (STDIN_FILENO);
	fd = open(file, O_RDONLY);
	return (fd);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
		return (-1);
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

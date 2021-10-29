#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int n);

void	ft_puterr(char *str)
{
	while(*str)
		write(2, str++, 1);
}

int	ft_do_op(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (b == 0 && op == '/')
		ft_puterr("Stop : division by zero\n");
	else if (b == 0 && op == '%')
		ft_puterr("Stop : modulo by zero\n");
	else if (op == '/')
		return (a / b);
	else if (op == '%')
		return (a % b);
	return (0);
}

char	ft_curate_op(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*'
			|| str[0] == '/' || str[0] == '%'))
		return (str[0]);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		a;
	int		b;
	char	op;

	if (ac != 4)
		return (1);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	op = ft_curate_op(av[2]);
	ft_putnbr(ft_do_op(a, b, op));
	return (0);
}

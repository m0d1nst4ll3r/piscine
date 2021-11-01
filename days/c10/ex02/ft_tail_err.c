#include "ft_tail.h"

void	ft_err_bytes(char *name, char *arg)
{
	ft_putstr(name, 2);
	ft_putstr(": invalid number of bytes: '", 2);
	ft_putstr(arg, 2);
	ft_putstr("'\n", 2);
}

void	ft_err_arg(char *name)
{
	ft_putstr(name, 2);
	ft_putstr(": option requires an argument -- 'c'\n", 2);
}

void	ft_err_open(char *name, char *file)
{
	ft_putstr(name, 2);
	ft_putstr(": cannot open '", 2);
	ft_putstr(file, 2);
	ft_putstr("' for reading: ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}

//	Display erros with tail's syntax
int	ft_err(int err, char *name, char *str)
{
	if (err == ERR_CANT_OPEN)
		ft_err_open(name, str);
	else if (err == ERR_NO_ARG)
		ft_err_arg(name);
	else if (err == ERR_INVALID_ARG)
		ft_err_bytes(name, str);
	return (err);
}

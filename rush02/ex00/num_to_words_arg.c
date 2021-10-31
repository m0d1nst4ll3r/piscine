#include "num_to_words.h"

/* -----------------------------------------------------------------------
**		ntw_read_arg
**
**	Reads from stdin and saves what is inputted into an allocated
**		string
**	Uses reallocate to handle unknown input length
**	This is called in case we have no arguments
**
**	Returns the input as a freeable string
** -------------------------------------------------------------------- */
char	*ntw_read_arg()
{
	char	*arg;
	char	buf[BUFSIZE];
	int		size;
	int		i;

	ntw_putstr(STDIN_MSG);
	arg = 0;
	size = read(STDIN_FILENO, buf, BUFSIZE);
	while (size)
	{
		i = 0;
		while (i < size)
		{
			arg = ntw_realloc(arg, buf[i]);
			i++;
		}
		size = read(STDIN_FILENO, buf, BUFSIZE);
	}
	ntw_putstr("\n");
	return (arg);
}

/* -----------------------------------------------------------------------
**		ntw_check_arg
**
**	Checks the validity of the argument our program received
**	It needs to be a non-empty string of digits bordered by any amount
**		of spaces and tabs.
**	Anything else will be considered invalid
**
**	Returns 1 in case of error, 0 otherwise
** -------------------------------------------------------------------- */
int	ntw_check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ' || arg[i] == '\t')
		i++;
	if (arg[i] < '0' || arg[i] > '9')
		return (1);
	while (arg[i] >= '0' && arg[i] <= '9')
		i++;
	while (arg[i] == ' ' || arg[i] == '\t')
		i++;
	if (arg[i])
		return (1);
	return (0);
}

/* -----------------------------------------------------------------------
**		ntw_format_arg
**
**	Cleans up the number we received as input:
**		- Removes useless 0s
**		- Removes spaces and tabs
**
**	The cleaned up string will be allocated and returned
**	The old dirty string can then be freed
** -------------------------------------------------------------------- */
char	*ntw_format_arg(char *arg)
{
	int		i;
	char	*new;

	new = 0;
	i = 0;
	while (arg[i] == ' ' || arg[i] == '\t')
		i++;
	while (arg[i] == '0')
		i++;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		new = ntw_realloc(new, arg[i]);
		if (! new)
			return (new);
		i++;
	}
	if (! new)
		new = ntw_realloc(new, '0');
	return (new);
}

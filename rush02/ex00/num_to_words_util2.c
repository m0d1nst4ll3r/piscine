#include "num_to_words.h"

/* -----------------------------------------------------------------------
**		ntw_atoi
**
**	Converts a properly formatted string of digits into its
**		corresponding int value
**	We know the string will only contain digits and we know
**		it won't have more than 3
** -------------------------------------------------------------------- */
int	ntw_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

/* -----------------------------------------------------------------------
**		ntw_strlen
**
**	Returns length of str as an int
** -------------------------------------------------------------------- */
int	ntw_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* -----------------------------------------------------------------------
**		ntw_mute
**
**	Since this function does nothing, we will use it as an argument
**		to our main translating function so that it can run once
**		without printing anything to detect potential errors.
** -------------------------------------------------------------------- */
void	ntw_mute(char *str)
{
	(void)str;
}

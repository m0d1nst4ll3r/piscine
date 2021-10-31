/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:30:00 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/30 20:05:53 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num_to_words.h"

/* -----------------------------------------------------------------------
**		ntw_translate
**
**	This function initializes all the values which will be used
**		in all the translating functions
**	It then begins parsing each digit, calling ntw_translate_digit
**		for each iteration, checking the return value and updating
**		t_val values as needed
**
**		params
**
**	- list:		the formatted dictionary as a list of key/word pairs
**	- num:		the number to display as a string
**	- func:		the function we will use to display words
**				will either be a regular pustr
**				or an empty function which prevents anything from
**				being displayed
**				this is used to mute the function during the first
**				dictionary-checking parse
** -------------------------------------------------------------------- */
int	ntw_translate(t_pair *list, char *num, void(*func)(char *))
{
	t_val	val;

	val.i = 0;
	val.sep = 0;
	val.spec = 0;
	val.thou = 0;
	val.len = ntw_strlen(num);
	while (val.i < val.len)
	{
		val.pos = val.len - val.i;
		if (ntw_translate_digit(list, num, &val, func))
			return (1);
		val.i++;
	}
	(*func)("\n");
	return (0);
}

/* -----------------------------------------------------------------------
**		num_to_words
**
**	In order, this function will:
**		1) Check the validity of the dictionary
**		2) Check the validity of the argument
**		3) Format said dictionary into a chained list
**		4) Format the argument into a clean string
**		5) Check whether our dictionary is sufficient
**			to display our number
**		6) Display our number
**		7) Free the allocated list completely
**
**	If at any point this function encounters any problem,
**		it will exit with an error code:
**		1) Dictionary error
**		2) Argument error
**
**		params
**
**	- arg:		the number received as input
**	- dic:		the dictionary's filename
** -------------------------------------------------------------------- */
int	num_to_words(char *arg, char *dic)
{
	t_pair	*list;
	char	*num;

	if (ntw_check_dic(dic))
		return (1);
	if (ntw_check_arg(arg))
		return (2);
	list = ntw_format_dic(dic);
	if (! list)
		return (1);
	num = ntw_format_arg(arg);
	if (ntw_translate(list, num, &ntw_mute))
		return (1);
	ntw_translate(list, num, &ntw_putstr);
	ntw_free_list(list);
	free(num);
	return (0);
}

/* -----------------------------------------------------------------------
**		main
**
**	Sends the correct arguments to the main num_to_words function,
**		the number to convert and the dictionary filename
**
**	If we have 3 arguments, we will use the second one
**		as our dictionary filename
**	Otherwise, we will use the default filename
**
**	If we have 2 or 3 arguments, we will use respectively the second
**		or third one as our number to convert.
**	Otherwise, we will read from stdin to receive it.
**
**	We will also free the allocated string if it was received from stdin
**
**	Finally, this is where we handle errors and print the corresponding
**		error messages.
** -------------------------------------------------------------------- */
int	main(int ac, char **av)
{
	char	*dic;
	char	*arg;
	int		rv;

	dic = DEFAULT_DIC;
	if (ac == 1)
		arg = ntw_read_arg();
	else if (ac == 2)
		arg = av[1];
	else if (ac >= 3)
	{
		arg = av[2];
		dic = av[1];
	}
	rv = num_to_words(arg, dic);
	if (rv == 1)
		ntw_puterr(EBADDIC);
	else if (rv == 2)
		ntw_puterr(EBADARG);
	if (ac == 1)
		free(arg);
	return (rv);
}

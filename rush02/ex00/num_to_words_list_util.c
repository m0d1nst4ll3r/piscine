#include "num_to_words.h"

/* -----------------------------------------------------------------------
**		ntw_create_elem
**
**	Creates a new t_pair, allocates memory for it, set its values
**		accordingly, and then returns its address
**	Next is always set to 0
** -------------------------------------------------------------------- */
t_pair	*ntw_create_elem(char num, char *word)
{
	t_pair	*new;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->num = num;
		new->word = word;
		new->next = 0;
	}
	return (new);
}

/* -----------------------------------------------------------------------
**		ntw_insert_elem
**
**	Creates a new t_pair, sets its values, and inserts it into the
**		provided list
**	The list's address will always be updated as the new element is
**		pushed to the front of the list
** -------------------------------------------------------------------- */
void	ntw_insert_elem(t_pair **begin, char num, char *word)
{
	t_pair	*new;

	if (! begin)
		return ;
	new = ntw_create_elem(num, word);
	if (! new)
		return ;
	new->next = *begin;
	*begin = new;
}

/* -----------------------------------------------------------------------
**		ntw_seek_elem
**
**	Will return the address of the first element of a list
**		which num value is equal to the value passed as argument
**	Will return 0 when no equal value was found
**
**	This is both used to avoid duplicates, and to search for a word
**		by passing its key as argument.
** -------------------------------------------------------------------- */
t_pair	*ntw_seek_elem(t_pair *begin, char num)
{
	while (begin && begin->num != num)
		begin = begin->next;
	return (begin);
}

/* -----------------------------------------------------------------------
**		ntw_free_list
**
**	Completely frees a list and all of its associated strings
**	Used before exiting the program
** -------------------------------------------------------------------- */
void	ntw_free_list(t_pair *begin)
{
	t_pair	*next;

	while (begin)
	{
		next = begin->next;
		free(begin->word);
		free(begin);
		begin = next;
	}
}

/* -----------------------------------------------------------------------
**		ntw_translate_print
**
**	This function will seek an element in our list which corresponds to
**		the key passed as argument
**
**	It will use the provided function on the element's word, if it finds
**		one
**
**	It will return 1 if it hasn't, 0 if it has
**
**		params
**
**	- list:		list in which to seek the key
**	- key:		key to seek in the list
**	- TODO: func:		function which will be used on the word
**				this is used to mute printing, to parse the number once
**				and detect any errors before printing anything
**
**		TODO: returns
**
**	- 1			if the element wasn't found
**	- 0			otherwise
** -------------------------------------------------------------------- */
void	ntw_translate_print(t_pair *list, char key)
{
	t_pair	*elem;

	elem = ntw_seek_elem(list, key);
	if (elem)
		ntw_putstr(elem->word);
}

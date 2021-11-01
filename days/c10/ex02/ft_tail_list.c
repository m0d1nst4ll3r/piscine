#include "ft_tail.h"

static t_byte	*create_elem(char byte)
{
	t_byte	*new;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->byte = byte;
		new->next = 0;
	}
	return (new);
}

void	insert_back(t_byte **begin, char byte)
{
	t_byte	*new;
	t_byte	*last;

	if (! begin)
		return ;
	new = create_elem(byte);
	if (!new)
		return ;
	if (! *begin)
	{
		*begin = new;
		return ;
	}
	last = *begin;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	remove_front(t_byte **begin)
{
	t_byte	*first;
	if (! begin || ! *begin)
		return ;
	first = *begin;
	*begin = first->next;
	free(first);
	
}

int	list_size(t_byte *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	free_list(t_byte *list)
{
	t_byte	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

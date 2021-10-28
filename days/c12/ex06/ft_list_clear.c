#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*elem;

	while (begin_list)
	{
		elem = begin_list;
		begin_list = begin_list->next;
		(*free_fct)(elem->data);
		free(elem);
	}
}

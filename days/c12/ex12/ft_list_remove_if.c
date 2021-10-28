#include "ft_list.h"

t_list	*ft_list_remove(t_list *elem, void (*free_fct)(void *))
{
	t_list	*next;

	next = elem->next;
	(*free_fct)(elem->data);
	free(elem);
	return (next);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*elem;

	if (! begin_list || ! *begin_list)
		return ;
	elem = *begin_list;
	while (elem->next)
	{
		if (! ((*cmp)(elem->next->data, data_ref)))
			elem->next = ft_list_remove(elem->next, free_fct);
		elem = elem->next;
	}
	if (! ((*cmp)((*begin_list)->data, data_ref)))
		*begin_list = ft_list_remove(*begin_list, free_fct);
}

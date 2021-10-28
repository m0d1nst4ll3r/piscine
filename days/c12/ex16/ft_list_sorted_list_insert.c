#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*elem;

	if (! begin_list)
		return ;
	new = ft_create_elem(data);
	if (new == NULL)
		return ;
	if (! *begin_list)
		*begin_list = new;
	if ((*cmp)(data, (*begin_list)->data) <= 0)
	{
		new->next = *begin_list;
		*begin_list = new;
	}
	else
	{
		elem = *begin_list;
		while (elem->next && (*cmp)(data, elem->next->data) > 0)
			elem = elem->next;
		new->next = elem->next;
		elem->next = new;
	}
}

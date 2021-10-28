#include "ft_list.h"

t_list	*ft_list_swap(t_list *elem)
{
	t_list	*elem2;

	elem2 = elem->next;
	elem->next = elem2->next;
	elem2->next = elem;
	return (elem2);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		sorted;
	t_list	*elem;

	if (! begin_list || ! *begin_list || ! (*begin_list)->next)
		return ;
	sorted = 0;
	while (! sorted)
	{
		sorted = 1;
		if ((*cmp)((*begin_list)->data, (*begin_list)->next->data) > 0)
		{
			sorted = 0;
			*begin_list = ft_list_swap(*begin_list);
		}
		elem = *begin_list;
		while (elem->next->next)
		{
			if ((*cmp)(elem->next->data, elem->next->next->data) > 0)
			{
				sorted = 0;
				elem->next = ft_list_swap(elem->next);
			}
			elem = elem->next;
		}
	}
}

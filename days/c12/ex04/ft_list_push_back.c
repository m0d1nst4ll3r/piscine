#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*elem;

	if (! begin_list)
		return ;
	new = ft_create_elem(data);
	if (new == NULL)
		return ;
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		elem = *begin_list;
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
}

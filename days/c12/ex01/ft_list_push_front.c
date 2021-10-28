#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (! begin_list)
		return ;
	new = ft_create_elem(data);
	if (new == NULL)
		return ;
	new->next = *begin_list;
	*begin_list = new;
}

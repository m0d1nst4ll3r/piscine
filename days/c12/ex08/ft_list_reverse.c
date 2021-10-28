#include "ft_list.h"
#include <stddef.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*new;
	t_list	*prev;
	t_list	*cur;

	if (! begin_list || ! *begin_list)
		return ;
	new = *begin_list;
	while (new->next)
		new = new->next;
	cur = new;
	while (cur != *begin_list)
	{
		prev = *begin_list;
		while (prev->next != cur)
			prev = prev->next;
		cur->next = prev;
		cur = prev;
	}
	cur->next = NULL;
	*begin_list = new;
}

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*end;

	if (! begin_list1)
		return ;
	if (! *begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	end = *begin_list1;
	while (end->next)
		end = end->next;
	end->next = begin_list2;
}

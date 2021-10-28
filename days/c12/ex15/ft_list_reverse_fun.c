#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*end;
	t_list	*prev;
	void	*temp;

	if (! begin_list)
		return ;
	end = begin_list;
	while (end->next)
		end = end->next;
	while (end != begin_list)
	{
		temp = end->data;
		end->data = begin_list->data;
		begin_list->data = temp;
		begin_list = begin_list->next;
		prev = begin_list;
		while (prev != end && prev->next != end)
			prev = prev->next;
		end = prev;
	}
}

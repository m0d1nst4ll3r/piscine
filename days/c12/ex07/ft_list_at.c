#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (nbr-- && begin_list)
		begin_list = begin_list->next;
	return (begin_list);
}

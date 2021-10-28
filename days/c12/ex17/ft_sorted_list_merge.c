#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin1, t_list *begin2, int (*cmp)())
{
	t_list	*cur;
	t_list	*cur2;
	t_list	*temp;

	if (! begin1 || ! *begin2)
		return ;
	else if (! *begin1)
		*begin1 = begin2;
	else
	{
		cur = *begin1;
		cur2 = begin2;
		if ((*cmp)(cur2->data, (*begin1)->data) <= 0)
		{
			while (cur2->next && (*cmp)(cur2->next, (*begin1)->data) <= 0)
				cur2 = cur2->next;
			temp = cur2->next;
			cur2->next = *begin1;
			*begin1 = begin2;
			cur2 = temp;
		}
		while()
	}
}

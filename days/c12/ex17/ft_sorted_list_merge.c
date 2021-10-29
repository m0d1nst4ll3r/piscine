#include "ft_list.h"

t_list	*insert(t_list *insert_this, t_list *after_this)
{
	t_list	*temp;

	temp = insert_this->next;
	insert_this->next = after_this->next;
	after_this->next = insert_this;
	return (temp);
}

void	merge(t_list **begin1, t_list *begin2, int (*cmp)())
{
	t_list	*cur1;
	t_list	*cur2;
	t_list	*temp;

	cur1 = *begin1;
	cur2 = begin2;
	if ((*cmp)(begin2->data, (*begin1)->data) <= 0)
	{
		while (cur2->next && (*cmp)(cur2->next->data, (*begin1)->data) <= 0)
			cur2 = cur2->next;
		temp = cur2->next;
		cur2->next = *begin1;
		*begin1 = begin2;
		cur2 = temp;
	}
	while (cur2 && cur1->next)
	{
		if ((*cmp)(cur2->data, cur1->next->data) <= 0)
			cur2 = insert(cur2, cur1);
		cur1 = cur1->next;
	}
	if (cur2)
		cur1->next = cur2;
}

void	ft_sorted_list_merge(t_list **begin1, t_list *begin2, int (*cmp)())
{
	if (! begin1 || ! begin2)
		return ;
	else if (! *begin1)
		*begin1 = begin2;
	else
		merge(begin1, begin2, cmp);
}

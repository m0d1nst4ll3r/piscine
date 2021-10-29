/*
   Use the following bash command if you've done everything:

   g c12_correction.c ex00/ft_create_elem.c ex01/ft_list_push_front.c ex02/ft_list_size.c ex03/ft_list_last.c ex04/ft_list_push_back.c ex05/ft_list_push_strs.c ex07/ft_list_at.c ex08/ft_list_reverse.c ex09/ft_list_foreach.c ex10/ft_list_foreach_if.c ex11/ft_list_find.c ex12/ft_list_remove_if.c ex13/ft_list_merge.c ex14/ft_list_sort.c ex15/ft_list_reverse_fun.c ex16/ft_list_sorted_list_insert.c ex17/ft_sorted_list_merge.c -I .

   Advise to use :

   ./a.out
   ./a.out olol
   ./a.out wlol
   ./a.out olol wlol lolo test elol 99 04

   Some tests have been skipped, like using empty lists to make sure your code doesn't break.
   So just re-read your code and make sure empty lists are being handled appropriately.
   */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)());
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

void	fake_free_lol(void *iwontfreethis)
{
	(void)iwontfreethis;
	return ;
}

void	ft_list_display(t_list *begin)
{
	int	i;

	i = 0;
	while (begin)
	{
		printf("%d: %s\n", i, (char *)begin->data);
		begin = begin->next;
		i++;
	}
}

void	ft_write_o(void *data)
{
	char	*str;

	str = (char *)data;
	str[0] = 'o';
}

void	ft_write_w(void *data)
{
	char	*str;

	str = (char *)data;
	str[0] = 'w';
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	// all exercises compiled

	t_list	*list = 0;
	t_list	*list2 = 0;
	t_list	*list3 = 0;

	ft_list_push_front(&list, "nothing");
	ft_list_push_front(&list, "like");
	ft_list_push_front(&list, "looks");
	ft_list_push_back(&list, "to");
	ft_list_push_back(&list, "me");
	ft_list_push_back(&list2, "23");
	ft_list_push_back(&list2, "42");
	list3 = ft_list_push_strs(ac, av);

	ft_list_display(list); //test 1
	printf("list size: %d\n", ft_list_size(list));
	printf("last is: %s\n", (char *)(ft_list_last(list)->data));
	printf("\n");

	ft_list_display(list2);
	printf("list2 size: %d\n", ft_list_size(list2));
	printf("last2 is: %s\n", (char *)(ft_list_last(list2)->data));
	printf("\n");

	ft_list_display(list3);
	printf("list3 size: %d\n", ft_list_size(list3));
	printf("last3 is: %s\n", (char *)(ft_list_last(list3)->data));
	printf("\n");

	printf("list1 0: %s\n", (char *)(ft_list_at(list, 0)->data));
	printf("list1 2: %s\n", (char *)(ft_list_at(list, 2)->data));
	printf("list1 4: %s\n", (char *)(ft_list_at(list, 4)->data));

	ft_list_reverse(&list3);
	printf("\nreverse test:\n");
	ft_list_display(list3);

	ft_list_foreach(list3, &ft_write_o);
	printf("\nforeach test:\n");
	ft_list_display(list3);

	ft_list_foreach_if(list3, &ft_write_w, "olol", &ft_strcmp);
	printf("\nforeach if test:\n");
	ft_list_display(list3);

	printf("\nfind test: %s\n", (char *)(ft_list_find(list3, "wlol", &ft_strcmp)->data));

	ft_list_remove_if(&list3, "wlol", &ft_strcmp, &fake_free_lol);
	printf("\nremove if test:\n");
	ft_list_display(list3);

	ft_list_remove_if(&list3, "o/a.out", &ft_strcmp, &fake_free_lol);
	printf("\nremove if test2:\n");
	ft_list_display(list3);

	ft_list_merge(&list, list2);
	printf("\nmerge test:\n");
	ft_list_display(list);

	t_list	*list4 = 0;
	ft_list_merge(&list4, list2);
	printf("\nmerge test empty:\n");
	ft_list_display(list4);

	ft_list_sort(&list, &ft_strcmp);
	printf("\nsort test:\n");
	ft_list_display(list);

	ft_list_reverse_fun(list);
	printf("\nreverse fun test:\n");
	ft_list_display(list);

	ft_list_sort(&list, &ft_strcmp);
	ft_sorted_list_insert(&list, "000000longjohnson", &ft_strcmp);
	ft_sorted_list_insert(&list, "Middle", &ft_strcmp);
	ft_sorted_list_insert(&list, "zend", &ft_strcmp);
	printf("\nsorted list insert test:\n");
	ft_list_display(list);

	ft_list_sort(&list3, &ft_strcmp);
	ft_sorted_list_merge(&list3, list, &ft_strcmp);
	printf("\nsorted list merge test:\n");
	ft_list_display(list3);
}

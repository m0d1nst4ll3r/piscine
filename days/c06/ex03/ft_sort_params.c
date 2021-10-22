/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rpohlen <rpohlen@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/20 17:34:31 by rpohlen		   #+#	#+#			 */
/*   Updated: 2021/10/20 17:53:27 by rpohlen          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_str_tab(char **tab, int size)
{
	int		i;
	int		sorted;
	char	*swap;

	sorted = 0;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i < size - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
				sorted = 0;
				break ;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 2)
		ft_sort_str_tab(argv + 1, argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		write(1, "\n", 1);
	}
	return (0);
}

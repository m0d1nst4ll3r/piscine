#include <stdlib.h>
#include <stdio.h>

void	ft_sort_string_tab(char **tab);
void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

int	main()
{
	// ex06

	/*char	**tab;
	tab = malloc(80);
	tab[0] = "Salut";
	tab[1] = "\tles";
	tab[2] = "amis";
	tab[3] = "comment";
	tab[4] = "aaa";
	tab[5] = "303";
	tab[6] = "30";
	tab[7] = "002";
	tab[8] = "001";
	tab[9] = 0;
	ft_sort_string_tab(tab);
	for (int i = 0; i < 9; i++)
		printf("%s\n", tab[i]);*/

	// ex07

	char	**tab;
	tab = malloc(80);
	tab[0] = "Salut";
	tab[1] = "\tles";
	tab[2] = "amis";
	tab[3] = "comment";
	tab[4] = "aaa";
	tab[5] = "303";
	tab[6] = "30";
	tab[7] = "002";
	tab[8] = "001";
	tab[9] = 0;
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	for (int i = 0; i < 9; i++)
		printf("%s\n", tab[i]);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	n;
	int	temp;

	n = size / 2;
	i = 0;
	while (i < n)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	if (! tab || length < 0)
		return (0);
	while(length-- > 1)
	{
		if ((*f)(*tab, *(tab + 1)) > 0)
			return (0);
		tab++;
	}
	return (1);
}

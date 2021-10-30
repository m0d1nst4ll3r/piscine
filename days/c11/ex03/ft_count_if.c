int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;

	if (! tab || length < 0)
		return (0);
	i = 0;
	while (*tab)
	{
		if ((*f)(*(tab++)))
			i++;
	}
	return (i);
}

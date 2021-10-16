char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (i < n)
	{
		if (src[i] == 0)
			end = 1;
		if (end)
			dest[i] = 0;
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}

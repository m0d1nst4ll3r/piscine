#include <unistd.h>

// Prints the char as its hexadecimal value
// Char needs to be between 0 and 15
void	ft_puthex(char h)
{
	if (h < 10)
		h = h + '0'; 
	else
		h = h - 10 + 'a';
	write(1, &h, 1);
}

// Prints the address passed as a string of 16 hexadecimal characters
// Followed by ": "
void	ft_print_addr(void *addr)
{
	long int	addri;
	int			i;

	addri = (long int)addr;
	i = 15;
	while (i >= 0)
	{
		ft_puthex((char)((addri >> i * 4) & 0xf));
		i--;
	}
	write(1, ": ", 2);
}

// Prints bytes in two possible formats
// If hex then bytes will be printed in hexadecimal
// Else bytes will be printed in ascii
void	ft_print_bytes(void *addr, int size, char hex)
{
	int		i;
	char	*addrc;

	i = 0;
	addrc = (char *)addr;
	while (i < size)
	{
		if (hex)
		{
			ft_puthex(((addrc[i] >> 4) & 0xf));
			ft_puthex((addrc[i] & 0xf));
			if (i % 2)
				write(1, " ", 1);

		}
		else
		{
			if (addrc[i] < 32)
				write(1, ".", 1);
			else
				write(1, addrc + i, 1);
		}
		i++;
	}
	while (hex && i++ < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
	}
}

void	*ft_print_memory(void *addr, int size)
{
	int	i;

	if (! size)
		return (addr);
	i = 0;
	while (i <= size / 16)
	{
		if (i == size / 16 && size % 16 == 0)
			break;
		ft_print_addr(addr + i * 16);
		if (i == size / 16)
		{
			ft_print_bytes(addr + i * 16, size % 16, 1);
			ft_print_bytes(addr + i * 16, size % 16, 0);
		}
		else
		{
			ft_print_bytes(addr + i * 16, 16, 1);
			ft_print_bytes(addr + i * 16, 16, 0);
		}
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:56:30 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/21 17:43:44 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// Prints a single byte or two spaces if we are over size
void	ft_print_byte_hex(char byte, int i, int size)
{
	if (i >= size)
		write(1, "  ", 2);
	else
	{
		ft_puthex(((byte >> 4) & 0xf));
		ft_puthex((byte & 0xf));
	}
	if (i % 2)
		write(1, " ", 1);
}

// Prints bytes in two possible formats
// If hex then bytes will be printed in hexadecimal
// Else bytes will be printed in ascii
void	ft_print_bytes(void *addr, int size, char hex)
{
	int		i;
	char	*addrc;

	i = -1;
	addrc = (char *)addr;
	while (++i < 16)
	{
		if (hex)
			ft_print_byte_hex(addrc[i], i, size);
		else
		{
			if (i < size)
			{
				if (addrc[i] < 32 || addrc[i] == 127)
					write(1, ".", 1);
				else
					write(1, addrc + i, 1);
			}
		}
	}
}

void	*ft_print_memory(void *addr, int size)
{
	int	i;

	if (size <= 0)
		return (addr);
	i = 0;
	while (i <= size / 16)
	{
		if (i == size / 16 && size % 16 == 0)
			break ;
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

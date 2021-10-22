/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rpohlen <rpohlen@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/20 18:36:31 by rpohlen		   #+#	#+#			 */
/*   Updated: 2021/10/22 13:25:14 by rpohlen          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*itab;
	int	len;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	itab = malloc(sizeof(*itab) * len);
	if (! itab)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	while (i < len)
	{
		itab[i] = min + i;
		i++;
	}
	*range = itab;
	return (len);
}

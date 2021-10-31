#include "num_to_words.h"

/* -----------------------------------------------------------------------
**		ntw_translate, TODO: ntw_translate_thou, ntw_translate_hun,
**			ntw_translate_ten, ntw_translate_unit
**
**	This function is, along ntw_format_dic, the core of our program
**
**	It will translate the number we receive into words, according to
**		our dictionary which has been conveniently sorted
**		into a chained list
**
**	To do so, the program looks at the position of a digit,
**		and based on its % 3 value, understands whether the digit
**		is a unit, a ten, a hundred, and whether it is at or above
**		one thousand.
**	As such, we consider digits as packets of 3.
**
**	Depending on the current digit, its position, and the surrounding
**		digits, we will know what key to look for, and what values to
**		update.
**
**	We will update the following values:
**		- sep:	The string that separates numbers, TODO: defaults to a space
**				can also be a hyphen or an "and"
**		- TODO: spec:	Whether we are currently waiting on a unit linked to a
**				previous digit (a 1) or not - this will cause the digit
**				to be ignored
**		- thou:	Whether we will need to print a power of 1000 value before
**				the next pack of 3 non-0 digits, and which one it will be
**				(this uses the compressed negative value as formatted)
**				(by ntw_convert_key)
**		- TODO: i:		Our iteration variable
**		- TODO: len:	The total length or the number, in digits
**		- TODO: pos:	the digit at which we currently are, counting from the right
**				1 will be units, 2 tens, 3 hundreds, 4 thousands, etc...
**
**		params
**
**	- list:		the list containing our key / word pairs
**	- num:		the clean number we got as input
**	- TODO: func:		the function we will use to display our words
**				this can either be a regular putstr,
**				or an empty function which will do nothing
**				this is used to verify the validity of our dictionary
**				when compared to our input, first,
**				before printing anything
**	- TODO: val:		the values we will update throughout the functions
**				as described above
**
**		TODO: returns
**
**	- 1			if a printing error was found
**	- 0			otherwise
** -------------------------------------------------------------------- */
void	ntw_translate(t_pair *list, char *num)
{
	int		len;
	int		i;
	int		pos;
	char	thou;
	char 	special;
	char	*sep;

	i = 0;
	sep = 0;
	special = 0;
	thou = 0;
	len = ntw_strlen(num);
	while (i < len)
	{
		pos = len - i; // Update position
		if ((num[i] != '0' || pos == 1) && thou && thou != (-1 * (pos - 1) / 3)) // Display thousands if any
		{
			ntw_putstr(NTW_SPC);
			ntw_translate_print(list, thou);
			thou = 0;
		}
		if (num[i] != '0' && !special)
		{
			if (sep) // Separator (and, hyphen, space)
			{
				ntw_putstr(sep);
				sep = 0;
			}
			if (pos > 3) // Update thousands
				thou = -1 * (pos - 1) / 3;
			if (pos % 3 == 0) // Hundreds
			{
				ntw_translate_print(list, num[i] - 48);
				ntw_putstr(NTW_SPC);
				ntw_translate_print(list, 100);
				sep = NTW_SPC;
				if (num[i + 1] != '0' || num[i + 2] != '0')
					sep = NTW_AND; // And after every hundred unless it's followed by two zeroes
			}
			else if (pos % 3 == 2) // Tens
			{
				if (num[i] == '1' && num[i + 1] != '0') // Eleven, twelve, etc...
				{
					ntw_translate_print(list, 10 + num[i + 1] - 48);
					special = 1; // Don't print next unit
					sep = NTW_SPC;
				}
				else // Ten, twenty, etc...
				{
					ntw_translate_print(list, 10 * (num[i] - 48));
					sep = NTW_SPC;
					if (num[i + 1] != '0') // If next is not 0, hyphen
						sep = NTW_HYP;
				}
			}
			else if (pos % 3 == 1) // Units
			{
				ntw_translate_print(list, num[i] - 48);
				sep = NTW_SPC;
			}
		}
		else if (pos == 3)
			sep = NTW_AND;
		else if (special)
			special = 0;
		else if (thou && pos == 1)
			ntw_translate_print(list, thou);
		else if (len == 1)
			ntw_translate_print(list, 0);
		i++;
	}
	ntw_putstr("\n");
}

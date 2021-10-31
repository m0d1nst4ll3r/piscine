#include "num_to_words.h"

/* -----------------------------------------------------------------------
**		ntw_translate_thou
**
**	Handles all the 1000-related word prints
**
**	Thousands are only printed if thou has been set
**	thou is set at every non-0 digit, if pos > 3
**		meaning, before the last hundred (in the string)
**	When thou is set, it memorizes the "line" it was set on
**		(by line, we mean the number of the pack of 3 digits)
**		and because of this, we can also check if it was set on the same
**		pack-of-3 as the one we're at right now
**	We use this memorized value to determine which power of 1000
**		we are looking to print
**	If it was, we won't print anything
**	We will only print either if the digit we're at is non zero,
**		or if we are at the very last zero of the number
** -------------------------------------------------------------------- */
int	ntw_translate_thou(t_pair *list, char *num, t_val *val,
		void(*func)(char *))
{
	if ((num[val->i] != '0' || val->pos == 1) && val->thou
			&& val->thou != (-1 * (val->pos - 1) / 3))
	{
		(*func)(NTW_DEF);
		if (ntw_translate_print(list, val->thou, func))
			return (1);
		val->thou = 0;
	}
	return (0);
}

/* -----------------------------------------------------------------------
**		ntw_translate_hun
**
**	Handles all the 100-related word prints
**
**	Hundreds are only printed for non-0 digits at the hundred position
**	We know a digit is at the hundred position when pos % 3 == 0
**	We will then print the digit itself, followed by a space, followed
**		by the word for the key 100
**	After a hundred, we will link with the next digit
**		with an "and" if and only if the hundred is not "empty"
**		(meaning if the next two digits are not both 0)
**
**	The very last hundred, if zero, will cause an "and" to be added
**		since something will always precede it anyway
** -------------------------------------------------------------------- */
int	ntw_translate_hun(t_pair *list, char *num, t_val *val,
		void(*func)(char *))
{
	if (num[val->i] != '0' && val->pos % 3 == 0)
	{
		if (ntw_translate_print(list, num[val->i] - 48, func))
			return (1);
		(*func)(NTW_DEF);
		if (ntw_translate_print(list, 100, func))
			return (1);
		if (num[val->i + 1] != '0' || num[val->i + 2] != '0')
			val->sep = NTW_AND;
	}
	else if (val->pos == 3 && num[val->i] == '0')
		val->sep = NTW_AND;
	return (0);
}

/* -----------------------------------------------------------------------
**		ntw_translate_ten
**
**	Handles all the ten-related word prints
**
**	If the digit is 1, and the next digit is not 0, we have the
**		eleven etc... special case
**	We will print the word for 10 + the next digit, and set spec to 1
**	This will indicate the next digit not to print anything, including
**		its preceding space
**
**	If the digit is not 1 nor 0, we will print the regular 10 * digit
**		word, and if the next digit is not 0, we will link with it
**		with a hyphen '-'
** -------------------------------------------------------------------- */
int	ntw_translate_ten(t_pair *list, char *num, t_val *val,
		void(*func)(char *))
{
	if (num[val->i] != '0' && val->pos % 3 == 2)
	{
		if (num[val->i] == '1' && num[val->i + 1] != '0')
		{
			if (ntw_translate_print(list, 10 + num[val->i + 1] - 48, func))
				return (1);
			val->spec = 1;
		}
		else
		{
			if (ntw_translate_print(list, 10 * (num[val->i] - 48), func))
				return (1);
			if (num[val->i + 1] != '0')
				val->sep = NTW_HYP;
		}
	}
	return (0);
}

/* -----------------------------------------------------------------------
**		ntw_translate_unit
**
**	Handles all the unit-related word prints
**
**	Non-0 units are simply printed, unless special was set to 1
**		indicating that preceding the unit, there was a 1, which
**		created a special eleven, etc... case
**
**	0 is only ever printed if len == 1, meaning there is only 1
**		digit in the string and it's 0.
** -------------------------------------------------------------------- */
int	ntw_translate_unit(t_pair *list, char *num, t_val *val,
		void(*func)(char *))
{
	if (val->pos % 3 == 1)
	{
		if (val->len == 1 && num[val->i] == '0')
		{
			if (ntw_translate_print(list, 0, func))
				return (1);
		}
		else if (val->spec)
			val->spec = 0;
		else if (num[val->i] != '0')
		{
			if (ntw_translate_print(list, num[val->i] - 48, func))
				return (1);
		}
	}
	return (0);
}

/* -----------------------------------------------------------------------
 **		ntw_translate_digit, ntw_translate_thou, ntw_translate_hun,
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
 **		- sep:	The string that separates numbers, defaults to a space
 **				can also be a hyphen or an "and"
 **		- spec:	Whether we are currently waiting on a unit linked to a
 **				previous digit (a 1) or not - this will cause the digit
 **				to be ignored
 **		- thou:	Whether we will need to print a power of 1000 value before
 **				the next pack of 3 non-0 digits, and which one it will be
 **				(this uses the compressed negative value as formatted)
 **				(by ntw_convert_key)
 **		- i:		Our iteration variable
 **		- len:	The total length or the number, in digits
 **		- pos:	the digit at which we currently are, counting from the right
 **				1 will be units, 2 tens, 3 hundreds, 4 thousands, etc...
 **
 **		params
 **
 **	- list:		the list containing our key / word pairs
 **	- num:		the clean number we got as input
 **	- val:		the values we will update throughout the functions
 **				as described above
 **	- func:		the function we will use to display our words
 **				this can either be a regular putstr,
 **				or an empty function which will do nothing
 **				this is used to verify the validity of our dictionary
 **				when compared to our input, first,
 **				before printing anything
 **
 **		returns
 **
 **	- 1			if a printing error was found
 **	- 0			otherwise
 ** -------------------------------------------------------------------- */
int		ntw_translate_digit(t_pair *list, char *num, t_val *val,
		void(*func)(char *))
{
	if (ntw_translate_thou(list, num, val, func))
		return (1);
	if (num[val->i] != '0' && val->i != 0 && ! val->spec)
	{
		if (! val->sep)
			(*func)(NTW_DEF);
		else
			(*func)(val->sep);
		val->sep = 0;
	}
	if (ntw_translate_hun(list, num, val, func)
			|| ntw_translate_ten(list, num, val, func)
			|| ntw_translate_unit(list, num, val, func))
		return (1);
	if (val->pos > 3 && num[val->i] != '0')
		val->thou = -1 * (val->pos - 1) / 3;
	return (0);
}

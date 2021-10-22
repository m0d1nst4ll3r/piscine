#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

void	ft_putnbr(int n);
int		ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);

int	main()
{
	// ex03

	/*printf("ft_atoi00: %d\n",ft_atoi("--+-+-25"));
	printf("ft_atoi01: %d\n",ft_atoi("++--2+5"));
	printf("ft_atoi02: %d\n",ft_atoi("+-++-25-"));
	printf("ft_atoi03: %d\n",ft_atoi("      +-25"));
	printf("ft_atoi04: %d\n",ft_atoi("+  -25"));
	printf("ft_atoi05: %d\n",ft_atoi("+-0"));
	printf("ft_atoi06: %d\n",ft_atoi("+-25765"));
	printf("ft_atoi07: %d\n",ft_atoi("  --+++2147483647awea"));
	printf("ft_atoi08: %d\n",ft_atoi("+-2147483648eqewq"));
	printf("ft_atoi09: %d\n",ft_atoi(" 7"));
	printf("ft_atoi10: %d\n",ft_atoi(" -5"));
	printf("ft_atoi11: %d\n",ft_atoi(" -weq +-25"));
	printf("ft_atoi12: %d\n",ft_atoi("+   65"));
	printf("ft_atoi13: %d\n",ft_atoi("-   23"));
	printf("ft_atoi14: %d\n",ft_atoi("+jeoqwjeoqjeoqjweoqjeoj"));
	printf("ft_atoi15: %d\n",ft_atoi("-qwoejqoejqowje"));
	printf("ft_atoi16: %d\n",ft_atoi("-+-+-+-+o1"));
	printf("ft_atoi17: %d\n",ft_atoi("-+-+-+-+o0"));*/


	// ex04

	/*ft_putnbr_base(100000,"0123456789");
	printf("\n");
	ft_putnbr_base(9183477,"abcdefghijklmnopqrstuvwxyz"); //ucnar
	printf("\n");
	ft_putnbr_base(91583498,"01"); //101011101010111010000001010
	printf("\n");
	ft_putnbr_base(538475,"salutSALUT"); //SuUtLS
	printf("\n");
	ft_putnbr_base(8233543,"abcdefghijklmnopqrstuvwxyz"); //salut
	printf("\n");
	ft_putnbr_base(-6754,"0123456789"); // duh
	printf("\n");
	ft_putnbr_base(-6754,"9876543210"); // -3245
	printf("\n");
	ft_putnbr_base(7,"0123456789-"); // nothing
	printf("\n");
	ft_putnbr_base(7,"0123456789+"); // nothing
	printf("\n");
	ft_putnbr_base(7,"0123456789 "); // nothing
	printf("\n");
	ft_putnbr_base(7,"0123456789\t"); // nothing
	printf("\n");
	ft_putnbr_base(7,"0123456789\x01"); // nothing
	printf("\n");*/


	// ex05
	
	/*printf("ex05 00 - %d\n", ft_atoi_base("1010","10")); // 5
	printf("ex05 00 - %d\n", ft_atoi_base("1000qwbeqeb","01")); // 8
	printf("ex05 01 - %d\n", ft_atoi_base(" \t baaayabewbeq","ab")); // 8
	printf("ex05 02 - %d\n", ft_atoi_base("\t+-y666 syrttos4385","6y")); // -8
	printf("ex05 03 - %d\n", ft_atoi_base("\t+-y666\n\r\t\b","y6")); // -7
	printf("ex05 04 - %d\n", ft_atoi_base("-+-+--+salutREWHRIUWEHFqweqw","abcdefghijklmnopqrstuvwxyz")); // 8233543
	printf("ex05 05 - %d\n", ft_atoi_base("+ 42","0123456789")); // 0
	printf("ex05 06 - %d\n", ft_atoi_base(" 1000","01 ")); // 0
	printf("ex05 07 - %d\n", ft_atoi_base("\t\b\n+--1000","011")); // 0
	printf("ex05 08 - %d\n", ft_atoi_base("ff","0123456789abcdef")); // 255
	printf("ex05 09 - %d\n", ft_atoi_base("1001","01+")); // 0
	printf("ex05 10 - %d\n", ft_atoi_base("\b  \t   +-++-+-1001","01")); // 0
	printf("ex05 11 - %d\n", ft_atoi_base("\r  \t   +-++-+-1001","01")); // -9
	printf("ex05 12 - %d\n", ft_atoi_base(" \t  1000","01")); // 8
	printf("ex05 13 - %d\n", ft_atoi_base("coucou","cou")); // 140
	printf("ex05 14 - %d\n", ft_atoi_base("   --+2147483647","0123456789")); // 2147483647
	printf("ex05 15 - %d\n", ft_atoi_base("  --+-2147483648","0123456789")); // -2147483648*/
}

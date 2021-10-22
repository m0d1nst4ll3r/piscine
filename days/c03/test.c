#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int ft_strlen(char *str);

int    main(int argc, char *argv[])
{
	unsigned int    result;
	unsigned int    result2;
	int    trunc;
	int    trunc2;
	unsigned int    size;
	char    test[20] = "coucou123";
	char    test2[20] = "coucou123";
	trunc = 0;
	trunc2 = 0;
	size = 21;
	if (argc == 3)
	{
		result2 = ft_strlcat(test2, argv[1], size);
		result = strlcat(test, argv[2], size);
		if (ft_strlen(test) < result)
			trunc = 1;
		if (ft_strlen(test2) < result2)
			trunc2 = 1;
		printf(">>>> strlcat\nResult : %d\nNew string : %s\nIs truncated : %d\n", result, test, trunc);
		printf(">>>> ft_strlcat\nResult : %d\nNew string : %s\nIs truncated : %d\n", result2, test2, trunc2);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c05_correction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:38:36 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/26 17:18:53 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle();

int	main(int argc, char **argv)
{
	(void)argc;
	// ex00

	/*printf("ex00 00 - %d\n", ft_iterative_factorial(-1));
	printf("ex00 01 - %d\n", ft_iterative_factorial(0));
	printf("ex00 02 - %d\n", ft_iterative_factorial(1));
	printf("ex00 03 - %d\n", ft_iterative_factorial(2));
	printf("ex00 04 - %d\n", ft_iterative_factorial(3));
	printf("ex00 05 - %d\n", ft_iterative_factorial(4));
	printf("ex00 06 - %d\n", ft_iterative_factorial(5));
	printf("ex00 07 - %d\n", ft_iterative_factorial(15));
	printf("ex00 08 - %d\n", ft_iterative_factorial(100));*/


	// ex01

	/*printf("ex01 00 - %d\n", ft_recursive_factorial(-1));
	printf("ex01 01 - %d\n", ft_recursive_factorial(0));
	printf("ex01 02 - %d\n", ft_recursive_factorial(1));
	printf("ex01 03 - %d\n", ft_recursive_factorial(2));
	printf("ex01 04 - %d\n", ft_recursive_factorial(3));
	printf("ex01 05 - %d\n", ft_recursive_factorial(4));
	printf("ex01 06 - %d\n", ft_recursive_factorial(5));
	printf("ex01 07 - %d\n", ft_recursive_factorial(15));
	printf("ex01 08 - %d\n", ft_recursive_factorial(100));*/


	// ex02

	/*printf("ex02 00 - %d\n", ft_iterative_power(0,0));
	printf("ex02 01 - %d\n", ft_iterative_power(0,1));
	printf("ex02 02 - %d\n", ft_iterative_power(1,0));
	printf("ex02 03 - %d\n", ft_iterative_power(1,1));
	printf("ex02 04 - %d\n", ft_iterative_power(1,-1));
	printf("ex02 05 - %d\n", ft_iterative_power(2,4));
	printf("ex02 06 - %d\n", ft_iterative_power(10,6));
	printf("ex02 07 - %d\n", ft_iterative_power(5,2));
	printf("ex02 08 - %d\n", ft_iterative_power(2,16));*/


	// ex03

	/*printf("ex03 00 - %d\n", ft_recursive_power(0,0));
	printf("ex03 01 - %d\n", ft_recursive_power(0,1));
	printf("ex03 02 - %d\n", ft_recursive_power(1,0));
	printf("ex03 03 - %d\n", ft_recursive_power(1,1));
	printf("ex03 04 - %d\n", ft_recursive_power(1,-1));
	printf("ex03 05 - %d\n", ft_recursive_power(2,4));
	printf("ex03 06 - %d\n", ft_recursive_power(10,6));
	printf("ex03 07 - %d\n", ft_recursive_power(5,2));
	printf("ex03 08 - %d\n", ft_recursive_power(2,16));*/


	// ex04

	/*printf("ex04 00 - %d\n",ft_fibonacci(-1));
	printf("ex04 01 - %d\n",ft_fibonacci(0));
	printf("ex04 02 - %d\n",ft_fibonacci(1));
	printf("ex04 03 - %d\n",ft_fibonacci(2));
	printf("ex04 04 - %d\n",ft_fibonacci(3));
	printf("ex04 05 - %d\n",ft_fibonacci(4));
	printf("ex04 06 - %d\n",ft_fibonacci(5));
	printf("ex04 07 - %d\n",ft_fibonacci(6));
	printf("ex04 08 - %d\n",ft_fibonacci(7));
	printf("ex04 09 - %d\n",ft_fibonacci(8));
	printf("ex04 10 - %d\n",ft_fibonacci(9));
	printf("ex04 11 - %d\n",ft_fibonacci(10));*/


	// ex05

	/*printf("ex05 00 - %d\n",ft_sqrt(-1)); // 0
	printf("ex05 01 - %d\n",ft_sqrt(0)); // 0
	printf("ex05 02 - %d\n",ft_sqrt(1)); // 0
	printf("ex05 03 - %d\n",ft_sqrt(2)); // 0
	printf("ex05 04 - %d\n",ft_sqrt(3)); // 0
	printf("ex05 05 - %d\n",ft_sqrt(4)); // 2
	printf("ex05 06 - %d\n",ft_sqrt(5)); // 0
	printf("ex05 07 - %d\n",ft_sqrt(9)); // 3
	printf("ex05 08 - %d\n",ft_sqrt(11));
	printf("ex05 09 - %d\n",ft_sqrt(15));
	printf("ex05 10 - %d\n",ft_sqrt(16));
	printf("ex05 11 - %d\n",ft_sqrt(121));
	printf("ex05 12 - %d\n",ft_sqrt(4096));
	printf("ex05 13 - %d\n",ft_sqrt(30858025));
	printf("ex05 14 - %d\n",ft_sqrt(100000000));
	printf("10:%d\n", ft_sqrt(100));
	printf("6:%d\n", ft_sqrt(36));
	printf("0:%d\n", ft_sqrt(37));
	printf("100:%d\n", ft_sqrt(10000));
	printf("0:%d\n", ft_sqrt(10001));
	printf("2000:%d\n", ft_sqrt(4000000));
	printf("0:%d\n", ft_sqrt(-36));*/

	// ex06

	/*printf("ex06 00 - %d (0)\n",ft_is_prime(-8));
	printf("ex06 01 - %d (0)\n",ft_is_prime(-3));
	printf("ex06 02 - %d (0)\n",ft_is_prime(-2));
	printf("ex06 03 - %d (0)\n",ft_is_prime(-1));
	printf("ex06 04 - %d (0)\n",ft_is_prime(0));
	printf("ex06 05 - %d (0)\n",ft_is_prime(1));
	printf("ex06 06 - %d (0)\n",ft_is_prime(2));
	printf("ex06 07 - %d (1)\n",ft_is_prime(3));
	printf("ex06 08 - %d (0)\n",ft_is_prime(4));
	printf("ex06 09 - %d (1)\n",ft_is_prime(5));
	printf("ex06 10 - %d (0)\n",ft_is_prime(9));
	printf("ex06 11 - %d (1)\n",ft_is_prime(11));
	printf("ex06 12 - %d (0)\n",ft_is_prime(15));
	printf("ex06 13 - %d (0)\n",ft_is_prime(16));
	printf("ex06 14 - %d (1)\n",ft_is_prime(499));
	printf("ex06 15 - %d (0)\n",ft_is_prime(4096));
	printf("ex06 16 - %d (0)\n",ft_is_prime(30858025));
	printf("ex06 17 - %d (1)\n",ft_is_prime(76231));
	printf("ex06 18 - %d (0)\n",ft_is_prime(76232));
	printf("ex06 19 - %d (0)\n",ft_is_prime(100000000));*/
	//printf("ex06 19 - %d\n",ft_is_prime(atoi(argv[1])));
	/*printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
		ft_is_prime(-1) == 0 ? "OK" : "Fail",
		ft_is_prime(-3) == 0 ? "OK" : "Fail",
		ft_is_prime(0) == 0 ? "OK" : "Fail",
		ft_is_prime(1) == 0 ? "OK" : "Fail",
		ft_is_prime(2) == 1 ? "OK" : "Fail",
		ft_is_prime(3) == 1 ? "OK" : "Fail",
		ft_is_prime(4) == 0 ? "OK" : "Fail",
		ft_is_prime(5) == 1 ? "OK" : "Fail",
		ft_is_prime(6) == 0 ? "OK" : "Fail",
		ft_is_prime(7) == 1 ? "OK" : "Fail",
		ft_is_prime(10) == 0 ? "OK" : "Fail",
		ft_is_prime(11) == 1 ? "OK" : "Fail",
		ft_is_prime(13) == 1 ? "OK" : "Fail",
		ft_is_prime(19) == 1 ? "OK" : "Fail",
		ft_is_prime(20) == 0 ? "OK" : "Fail"
		  );*/

	// ex07

	//printf("ex07 - %d\n",ft_find_next_prime(atoi(argv[1])));

	// ex08

	printf("ex08 - %d\n",ft_ten_queens_puzzle()); // 724
}

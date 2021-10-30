/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:00:09 by rpohlen           #+#    #+#             */
/*   Updated: 2021/10/30 20:04:08 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_TO_WORDS_H
# define NUM_TO_WORDS_H

# define DEFAULT_DIC "numbers.dict"
# define EBADDIC "Dict Error\n"
# define BUFSIZE 256

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

//	num_to_words_dic.c
int		ntw_check_dic(char *dic);

//	num_to_words_util.c
void	ft_putstr(char *str);
void	ft_puterr(char *str);


//	REMOVE THIS
#include <stdio.h> // REMOVE THIS
//	REMOVE THIS

#endif

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
# define EBADARG "Error\n"
# define STDIN_MSG "Waiting for input... press CTRL+D to end\n"
# define BUFSIZE 256
# define NTW_AND " and "
# define NTW_DEF " "
# define NTW_HYP "-"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

//	This structure is used as our key / word pair
//	It will be used as a chained list
typedef struct s_pair
{
	char			num;
	char			*word;
	struct s_pair	*next;
}	t_pair;

//	This structure is used to regroup all the values used
//		in the translating functions
typedef struct s_val
{
	int		len;
	int		i;
	int		pos;
	char	thou;
	char	spec;
	char	*sep;
}	t_val;

//	num_to_words_translate.c
int		ntw_translate_digit(t_pair *list, char *num, t_val *val,
		void(*func)(char *));

//	num_to_words_dic_check.c
int		ntw_check_dic(char *dic);

//	num_to_words_dic_format.c
t_pair	*ntw_format_dic(char *dic);

//	num_to_words_arg.c
char	*ntw_read_arg();
int		ntw_check_arg(char *arg);
char	*ntw_format_arg(char *arg);

//	num_to_words_util.c
void	ntw_putstr(char *str);
void	ntw_puterr(char *str);
int		ntw_open_dic(char *dic);
char	*ntw_realloc(char *old, char add);
int		ntw_convert_key(char *key);

//	num_to_words_util2.c
int		ntw_atoi(char *str);
int		ntw_strlen(char *str);
void	ntw_mute(char *str);

//	num_to_words_list_util.c
void	ntw_insert_elem(t_pair **begin, char num, char *word);
t_pair	*ntw_seek_elem(t_pair *begin, char num);
void	ntw_free_list(t_pair *begin);
int		ntw_translate_print(t_pair *list, char key, void(*func)(char *));

#endif

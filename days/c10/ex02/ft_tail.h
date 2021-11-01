#ifndef FT_TAIL_H
# define FT_TAIL_H

# define BUFSIZE 256
# define ERR_NO_ARG 1
# define ERR_INVALID_ARG 2
# define ERR_CANT_OPEN 3

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

typedef struct s_byte
{
	char			byte;
	struct s_byte	*next;
}	t_byte;

//	ft_tail_list.c
void	remove_front(t_byte **begin);
void	insert_back(t_byte **begin, char byte);
void	free_list(t_byte *begin);
int		list_size(t_byte *list);
void	free_list(t_byte *list);

//	ft_tail_util.c
void	ft_putstr(char *str, int chan);
int		ft_open(char *file);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);

//	ft_tail_err.c
int		ft_err(int err, char *name, char *str);

#endif

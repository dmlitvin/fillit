/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:40:24 by akorchyn          #+#    #+#             */
/*   Updated: 2019/09/13 20:37:06 by dmlitvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/include/libft.h"
# include <fcntl.h>
# define AC(x) if (x != 2) {ft_putstr("usage: fillit source_file\n"); exit(-1);}
# define CHECK(x) if (x == -1) {ft_putstr("error\n"); exit(-1);}
# define MALCHECK(x) if (x == NULL) {ft_putstr("error\n"); exit(-1);}
# define SIZECHECK(x) if (x > 26 || x < 1) {ft_putstr("error\n"); exit(-1);}

typedef struct		s_figure
{
	char			**figure;
	struct s_figure	*next;
}					t_figure;

t_figure			*figurenew(void);
void				del_all(t_figure **head);
int					ft_figure_size(t_figure *begin_list);

typedef struct		s_back
{
	char			**matrix;
	struct s_back	*next;
	struct s_back	*back;
}					t_back;

void				del_list(t_back *head, int size);
t_back				*add_t_back(char **matrix, int size);

void				corectness(t_figure *head);
void				back_tracking(t_figure *head, t_back *matrix,
	int square, int i);
void				change_sharps(t_figure *head);
void				move_upper(t_figure *head);
t_figure			*get_figures(int fd);

#endif

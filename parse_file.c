/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:40:05 by akorchyn          #+#    #+#             */
/*   Updated: 2018/11/12 13:40:07 by akorchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		change_sharps(t_figure *head)
{
	t_figure	*run;
	char		c;
	int			i;
	int			j;

	c = 'A';
	run = head;
	while (run)
	{
		i = -1;
		while ((run->figure)[++i])
		{
			j = -1;
			while ((run->figure)[i][++j])
				if ((run->figure)[i][j] == '#')
					run->figure[i][j] = c;
		}
		c++;
		run = run->next;
	}
}

static int	cpy(char **figure, char *buff)
{
	int		i;

	i = -1;
	if (buff[4] != '\n' || buff[9] != '\n'
		|| buff[14] != '\n' || buff[19] != '\n')
		return (-1);
	while (++i < 4)
		MALCHECK((figure[i] = (char *)malloc(sizeof(char) * 4)));
	figure[0] = ft_strncpy(figure[0], buff, 4);
	figure[1] = ft_strncpy(figure[1], buff + 5, 4);
	figure[2] = ft_strncpy(figure[2], buff + 10, 4);
	figure[3] = ft_strncpy(figure[3], buff + 15, 4);
	return (0);
}

t_figure	*get_figures(int fd)
{
	int			ret;
	char		buff[21];
	t_figure	*figures;
	t_figure	*run;

	MALCHECK((figures = figurenew()));
	run = figures;
	while ((ret = read(fd, buff, 21)) == 21)
	{
		if (buff[20] != '\n')
		{
			ft_putstr("error\n");
			exit(-1);
		}
		CHECK(cpy(run->figure, buff));
		MALCHECK((run->next = figurenew()));
		run = run->next;
	}
	(ret != 20) ? ret = -1 : 0;
	CHECK(ret);
	cpy(run->figure, buff);
	SIZECHECK(ft_figure_size(figures));
	return (figures);
}

static void	move_up(t_figure *list)
{
	int		l;
	int		j;
	int		y_to_figure;

	y_to_figure = 30;
	l = -1;
	while (++l < 4)
	{
		j = -1;
		while (++j < 4)
			if (list->figure[l][j] != '.' && y_to_figure > l)
				y_to_figure = l;
	}
	l = -1;
	while (++l < 4 && (y_to_figure > 0 && y_to_figure < 4))
	{
		j = -1;
		while (++j < 4)
			if (list->figure[l][j] != '.')
			{
				list->figure[l - y_to_figure][j] = list->figure[l][j];
				list->figure[l][j] = '.';
			}
	}
}

void		move_upper(t_figure *head)
{
	if (head->next)
		move_upper(head->next);
	move_up(head);
}

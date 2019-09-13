/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corectness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:15:30 by akorchyn          #+#    #+#             */
/*   Updated: 2018/11/08 13:15:31 by akorchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_corectness(char **str, int j, int i)
{
	int		k;

	k = 0;
	if (i > 0)
		(str[j][i - 1] == '#') ? k++ : 0;
	if (j > 0)
		(str[j - 1][i] == '#') ? k++ : 0;
	if (j < 3)
		(str[j + 1][i] == '#') ? k++ : 0;
	(str[j][i + 1] == '#') ? k++ : 0;
	if (k > 0)
		return (k);
	return (-8);
}

static int	corectness_massive(char **str)
{
	int i;
	int	j;
	int	connections;
	int	sharps;

	j = -1;
	connections = 0;
	sharps = 0;
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
		{
			if ((str[j][i] != '.' && str[j][i] != '#'))
				return (-1);
			(str[j][i] == '#') ? sharps++ : 0;
			if (str[j][i] == '#')
				connections += check_corectness(str, j, i);
		}
		if (i != 4)
			return (-1);
	}
	if ((connections != 6 && connections != 8) || sharps != 4)
		return (-1);
	return (1);
}

void		corectness(t_figure *head)
{
	if (head->next)
		corectness(head->next);
	CHECK(corectness_massive(head->figure));
}

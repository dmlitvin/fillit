/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_figures.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:30:28 by akorchyn          #+#    #+#             */
/*   Updated: 2018/11/07 17:30:29 by akorchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	*figurenew(void)
{
	t_figure	*new;
	int			i;

	i = -1;
	if (!(new = (t_figure *)malloc(sizeof(t_figure))))
		return (NULL);
	if (!(new->figure = (char **)malloc(sizeof(char *) * 5)))
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	new->figure[4] = NULL;
	return (new);
}

int			ft_figure_size(t_figure *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

static void	massive_free(char ***as)
{
	int		i;

	if (!as)
		return ;
	i = -1;
	while (++i < 4)
		free((*as)[i]);
	free(*as);
	*as = NULL;
}

void		del_all(t_figure **head)
{
	if (!*head)
		return ;
	if ((*head)->next)
		del_all(&((*head)->next));
	massive_free(&((*head)->figure));
	free(*head);
	*head = NULL;
}

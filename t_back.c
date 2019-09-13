/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_back.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:33:26 by akorchyn          #+#    #+#             */
/*   Updated: 2018/11/11 12:33:27 by akorchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_back	*backnew(int square)
{
	t_back	*new;
	int		i;
	int		j;

	i = -1;
	MALCHECK((new = (t_back *)malloc(sizeof(t_back))));
	MALCHECK((new->matrix = (char **)malloc(sizeof(char *) * square)));
	while (++i < square)
	{
		j = -1;
		MALCHECK((new->matrix[i] = (char *)malloc(sizeof(char *) * square)));
		while (++j < square)
			new->matrix[i][j] = '.';
	}
	new->next = NULL;
	new->back = NULL;
	return (new);
}

void			del_list(t_back *head, int square)
{
	int		i;

	i = -1;
	if (!head)
		return ;
	while (++i < square)
		free(head->matrix[i]);
	free(head->matrix);
	free(head);
}

t_back			*add_t_back(char **matrix, int square)
{
	t_back	*new;
	int		i;

	i = -1;
	new = backnew(square);
	if (matrix)
		while (++i < square)
			new->matrix[i] = ft_strncpy(new->matrix[i], matrix[i], square);
	return (new);
}

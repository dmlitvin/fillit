/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:48:31 by akorchyn          #+#    #+#             */
/*   Updated: 2018/11/09 18:48:32 by akorchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_matrix(char **matrix, int i)
{
	int	j;
	int	l;

	j = -1;
	while (++j < i)
	{
		l = -1;
		while (++l < i)
			ft_putchar(matrix[j][l]);
		ft_putchar('\n');
	}
	exit(0);
}

static int	len_x(t_figure *list, int position, t_back *matrix, int square)
{
	int		x_to_figure;
	int		l;
	int		j;
	int		x;
	int		y;

	x = position % square;
	y = position / square;
	x_to_figure = 30;
	l = -1;
	while (++l < 4)
	{
		j = -1;
		while (++j < 4)
			if (list->figure[l][j] != '.' && x_to_figure > j)
				x_to_figure = j;
	}
	l = -1;
	while (++l < 4 && (j = -1))
		while (++j < 4)
			if ((list->figure[l][j] != '.' && ((y + l > square - 1
				|| x + (j - x_to_figure) > square - 1)
				|| matrix->matrix[y + l][x + (j - x_to_figure)] != '.')))
				return (-1);
	return (x_to_figure);
}

int			add_figure_to_matrix(t_figure *list, t_back *matrix,
	int square, int position)
{
	int	x;
	int	y;
	int	l;
	int	j;
	int	x_to_figure;

	x = position % square;
	if ((y = position / square) == square)
		return (-1);
	if ((x_to_figure = len_x(list, position, matrix, square)) == -1)
		return (0);
	l = -1;
	while (++l < 4)
	{
		j = x_to_figure - 1;
		while (++j < 4)
			if (list->figure[l][j] != '.')
				matrix->matrix[y + l][x + (j - x_to_figure)] =
			list->figure[l][j];
	}
	return (1);
}

void		back_tracking(t_figure *head, t_back *matrix, int square, int i)
{
	int			position;
	int			k;

	position = 0;
	if (!matrix)
		matrix = add_t_back(NULL, square);
	while (head)
	{
		matrix->next = add_t_back(matrix->matrix, square);
		matrix->next->back = matrix;
		matrix = matrix->next;
		while ((k = add_figure_to_matrix(head, matrix, square, position)) == 0)
			position++;
		position++;
		if (k == -1)
		{
			(i == 0) ? del_list(matrix->back, square) : 0;
			del_list(matrix, square);
			return ;
		}
		(k == 1) ? back_tracking(head->next, matrix, square, i + 1) : 0;
		matrix = matrix->back;
		del_list(matrix->next, square);
	}
	print_matrix(matrix->matrix, square);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorchyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:05:12 by akorchyn          #+#    #+#             */
/*   Updated: 2018/11/07 13:05:14 by akorchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int			fd;
	int			i;
	t_figure	*figures;
	t_back		*matrix;

	i = 1;
	matrix = NULL;
	AC(argc);
	CHECK((fd = open(argv[1], O_RDONLY)));
	MALCHECK((figures = get_figures(fd)));
	close(fd);
	corectness(figures);
	change_sharps(figures);
	move_upper(figures);
	while (++i < 20)
		back_tracking(figures, matrix, i, 0);
	del_all(&figures);
	return (0);
}

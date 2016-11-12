/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:49:51 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/12 17:15:25 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/fillit.h"

void		ft_reset_piece(t_coord **piece,
		char **res, int x_index, int y_index)
{
	t_coordxy	*first;
	int			x;
	int			y;

	first = (*piece)->coords;
	while ((*piece)->coords)
	{
		x = (*piece)->coords->x + x_index;
		y = (*piece)->coords->y + y_index;
		res[y][x] = '.';
		(*piece)->coords = (*piece)->coords->next;
	}
	(*piece)->in = 0;
	(*piece)->coords = first;
}

void		ft_write_piece(t_coord **piece,
		char **res, int x_index, int y_index)
{
	t_coordxy	*first;
	int			x;
	int			y;

	first = (*piece)->coords;
	while ((*piece)->coords)
	{
		x = (*piece)->coords->x + x_index;
		y = (*piece)->coords->y + y_index;
		res[y][x] = (*piece)->coords->number + 'A';
		(*piece)->coords = (*piece)->coords->next;
	}
	(*piece)->in = 1;
	(*piece)->coords = first;
}

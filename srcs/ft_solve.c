/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:35:38 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/12 18:21:44 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/fillit.h"

int			ft_check_htg(t_coord **piece, char **res, int x_index, int y_index, int size)
{
	t_coordxy	*first;
	int			error;
	int			x;
	int			y;

	error = 0;
	first = (*piece)->coords;
	if ( x_index + (piece[0])->x_max < size  &&
			y_index + (piece[0])->y_max < size)
	{
		while ((*piece)->coords)
		{
			x = (*piece)->coords->x + x_index;
			y = (*piece)->coords->y + y_index;
			if (res[y][x] >= 'A')
				error = 1;
			(*piece)->coords = (*piece)->coords->next;
		}
	}
	else 
		error = 1;
	(*piece)->coords = first;
	if (error)
		return (1);
	else
		return (0);
}

int		ft_check_htg_all(t_coord **pieces, char **res, int x_index, int y_index, int size)
{
	int i;

	i = 0;
	while (i < (pieces[0])->nb_pieces)
	{
		if (pieces[i]->in == 0)
		{
			if (!ft_check_htg(&pieces[i], res, x_index, y_index, size))
			{
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int			ft_all_pieces(t_coord **piece)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if ((piece[i])->in == 0)
			return (0);
		i++;
	}
	return (1);
}



int			ft_backtrack(t_coord **pieces, int size, char **res, int index)
{
	int x_index;
	int y_index;
	int i;

	i = 0;
	x_index = index % size;
	y_index = index / size;
	if (ft_all_pieces(pieces))
		return (1);
	if ((ft_check_htg_all(&pieces[i], res, x_index, y_index, size) == 0) &&
			index <= size * size)
		return (ft_backtrack(pieces, size, res, index + 1));
	while (i < (pieces[0])->nb_pieces)
	{
		if (ft_check_htg(&pieces[i], res, x_index, y_index, size) != 1 && (pieces[i])->in == 0)
		{
			ft_write_piece(&pieces[i], res, x_index, y_index);
			if (ft_backtrack(pieces, size, res, index + 1) == 1)
				return (1);
			ft_reset_piece(&pieces[i], res, x_index, y_index);
		}
		i++;
	}
	return (0);
}

void		ft_solve(t_coord **pieces, int nb_pieces, int taille)
{
	char	**tab;
	int		i;

	i = 0;
	while (nb_pieces * 4 > taille * taille)
		taille++;
	tab = (char **)malloc(sizeof(char *) * taille + 1);
	while (i < taille)
	{
		tab[i] = ft_strnew(taille - 1);
		tab[i] = ft_memset(tab[i], '.', taille);
		i++;
	}
	if (ft_backtrack(pieces, taille, tab, 0) == 1)
	{
		ft_print_tab(tab);
		return ;
	}
	else
		ft_solve(pieces, nb_pieces, taille + 1);
	i = 0;
	while (tab[i++])
	{
		free(tab[i]);
		tab[i] = NULL;
		free(tab);
	}
}

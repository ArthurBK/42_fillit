/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:28:38 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/09 19:41:05 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/fillit.h"

/*
   static int		ft_mult_4(int i)
   {
   if (i == 1)
   return (0);
   if (i / 4 * 4 == i)
   return (1);
   return (0);
   }
   */

/*
   static int		ft_nb_piece(char *str)
   {
   return (ft_strlen(str) / 16);
   }
   */



t_piece			**ft_piece_to_coord(char **tab)
{
	int			i;
	int			j;
	int			k;
	int			p;
	int			x;
	int			y;
	int			count;
	t_coordxy	*coord;
	t_piece		**piece;

	j = 0;
	count = 0;
	p = 0;
	piece = (t_piece **)malloc(sizeof(t_piece));
	coord = (t_coordxy *)malloc(sizeof(t_coordxy));
	while (tab[j])
	{
		x = 0;
		y = 0;
		k = -1;
//		*piece = ft_lstnew(..)
		while (++k <= 3)
		{
			i = 0;
			while (tab[j][i])
			{
				if (tab[j][i] == '#')
				{
					if (k != 3 && i > 0)
						if (tab[j + 1][i - 1] == '#')
							x++;
					coord->x = x;
					coord->y = y;
					ft_lstadd(&coord, ft_lstnew(&coord, sizeof(coord)));
					p++;
				}
				i++;
				x++;
			}
			y++;
			j++;
		}
		count++;
	}
	return (piece);
}
/*
{
if (!(coordxy = (t_coordxy*)malloc(sizeof(t_coordxy))))
	return (NULL);
}
*/

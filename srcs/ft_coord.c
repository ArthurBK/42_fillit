/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:28:38 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/09 16:34:09 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_mult_4(int i)
{
	if (i == 1)
		return (0);
	if (i / 4 * 4 == i)
		return (1);
	return (0);
}

static int		ft_nb_piece(char *str)
{
	return (ft_strlen(str) / 16);
}

t_coordxy		*ft_piece_to_coord(char **tab)
{
	int			i;
	int			j;
	t_coord		*coordxy;

	i = 0;
	j = 0;
	if (!(coordxy = (t_coordxy*)malloc(sizeof(t_coordxy))))
		return (NULL);

}

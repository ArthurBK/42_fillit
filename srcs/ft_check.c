/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:23:56 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/12 10:00:57 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int		ft_mult_5(int i)
{
	if (i == 1)
		return (0);
	if (i / 5 * 5 == i)
		return (1);
	return (0);
}

static int		ft_check_back_line(char *str)
{
	int i;
	int	j;
	int nb_line;
	int	square;

	i = 1;
	square = 0;
	j = 1;
	nb_line = 1;
	while (str[i])
	{
		if (ft_mult_5(nb_line) == 1 && str[i] != '\n')
			return (1);
		if (ft_mult_5(nb_line) == 1)
			j--;
		if (str[i] == '\n')
			nb_line++;
		j++;
		if (ft_mult_5(j) == 1 && str[i] != '\n')
			return (1);
		square++;
		if (ft_mult_5(nb_line) == 1 && str[i + 1] != '\0')
			square = 0;
		i++;
	}
	return (square != 21 ? 1 : 0);
}

static int		ft_check_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '#' &&
				str[i] != '.' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int				ft_check_main(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_check_char(str);
	i = ft_check_back_line(str);
	if (i == 1)
		return (1);
	j = ft_check_pattern(str);
	return (i + j);
}

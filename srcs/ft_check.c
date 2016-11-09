/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:23:56 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/09 08:41:59 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_mult_5(int i)
{
	if (i / 5 * 5 == i)
		return (1);
	return (0);
}

static int		ft_check_back_line(char *str)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (str[i])
	{
		if (ft_mult_5(i) == 1 && ft_mult_5(j) != 1 && str[i] != '\n')
			return (1);
		if (ft_mult_5(i) == 1)
			j++;
		if (ft_mult_5(j) == 1 && str[i] != '\n')
			return (1);
		i++;
	}
	return (i);
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

int     		ft_check_main(char *str)
{
	int i;

	i = 0;
	i = ft_check_char(str);
	i = ft_check_back_line(str);
	return (i);
}

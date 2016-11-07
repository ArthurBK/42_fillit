/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:41:27 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/07 21:13:22 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **ar)
{
	int fd;

	fd = 0;
	if (ac == 2)
	{
		if (!(fd = open(ar[1], O_RDWR)))
			ft_putstr(ar[1]);
		if (close(ar[1]) == -1)
			ft_putstr("close error ()");
	}
	else
	{
		//ecrire sur la sortie d'erreur 2?
		ft_putstr("usgae: ./fillit target_file");
	}

		return(0);
}

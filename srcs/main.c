/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:41:27 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/07 20:50:43 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **ar)
{
	if (ac == 2)
	{
		ft_putstr(ar[1]);
	}
	else
	{
		//ecrire sur la sortie d'erreur 2?
		ft_putstr("usgae: ./fillit target_file");
	}

		return(0);
}

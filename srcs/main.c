/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:41:27 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/08 14:44:11 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_check(int fd)
{
}


void	ft_read_file(int fd)
{
	int		ret;
	char	buf[2];

	while ((ret = read(fd, buf, 1)))
	{
		buf[1] = '\0';
		ft_putchar(buf[0]);
	}
}

int		ft_lenfd(int fd)
{
	int		ret;
	int		i;
	char	buf[2];

	i = 0;
	while ((ret = read(fd, buf, 1)))
	{
		buf[1] = '\0';
		i++;
	}
	return (i);
}


int	main(int ac, char **ar)
{
	int		fd;
	char	*dst;
	int		len;

	fd = 0;
	len = 0;
	if (ac == 2)
	{
		if (!(fd = open(ar[1], O_RDWR)))
		{
			ft_putstr("open error ()");
			return (1);
		}
		len = ft_lenfd(fd);
		if (close(fd) == -1)
		{
			ft_putstr("close error ()");
			return (1);
		}
		fd = open(ar[1], O_RDWR);
		dst = malloc(sizeof(char) * len + 1);
		printf("%d\n", len);
		ft_read_file(fd);
	}
	else
	{
		//ecrire sur la sortie d'erreur 2?
		ft_putstr("usage: ./fillit target_file");
	}

	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:41:27 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/09 13:59:02 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/fillit.h"
#include <stdio.h>

int		ft_lenfd(int fd)
{
	int     ret;
	int     i;
	char    buf[2];

	i = 0;
	while ((ret = read(fd, buf, 1)))
	{
		buf[1] = '\0';
		i++;
	}
	return (i);
}

char	*ft_string_to_fd(char *dst, int fd)
{
	int     ret;
	char    buf[2];
	int		i;

	i = 0;
	while ((ret = read(fd, buf, 1)))
	{
		buf[1] = '\0';
		dst[i] = buf[0];
		i++;
	}
	dst[i] = 0;
	return (dst);
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
		if (!(dst = malloc(sizeof(char) * len + 1)))
			return (1);
		dst = ft_string_to_fd(dst, fd);
		ft_check_main(dst);
		printf("%i\n", ft_check_pattern(dst));
	}
	else
	{
		//ecrire sur la sortie d'erreur 2?
		ft_putstr("usage: ./fillit target_file");
	}

	return(0);
}

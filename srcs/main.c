/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:41:27 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/12 10:01:08 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/fillit.h"

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

char	*ft_string_to_fd(char *dst, int fd)
{
	int		ret;
	char	buf[2];
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

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_open_len(char *av)
{
	int len;
	int fd;

	fd = 0;
	if (!(fd = open(av, O_RDWR)))
	{
		ft_putstr("open error ()");
		return (-1);
	}
	len = ft_lenfd(fd);
	if (close(fd) == -1)
	{
		ft_putstr("close error ()");
		return (-1);
	}
	return (len);
}

int	main(int ac, char **ar)
{
	int		fd;
	char	*dst;
	char	*str;
	int		len;
	char	**tab;
	t_coord	**pieces;
	int		yo;

	fd = 0;
	yo = 2;
	len = 0;
	if (ac == 2)
	{
		if (ft_open_len(ar[1]) == -1)
			return (1);
		len = ft_open_len(ar[1]);
		fd = open(ar[1], O_RDWR);
		if (!(dst = malloc(sizeof(char) * len + 1)))
			return (1);
		dst = ft_string_to_fd(dst, fd);
		if (ft_check_main(dst) != 0)
		{
			ft_putstr("error\n");
			return (1);
		}
		str = ft_str_without_back_slash(dst);
		tab = ft_str_to_tab(str);
		pieces = ft_store_pieces(tab, ft_nb_piece(str), ft_nb_piece(str));
		while (yo * yo < ft_nb_piece(str))
			yo++;
		ft_solve(pieces, ft_nb_piece(str), 1);
	}
	else
		ft_putstr("usage: ./fillit target_file");
	return (0);
}

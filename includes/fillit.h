/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:38:40 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/09 16:38:26 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# define NUMBER_OF_PATTERNS 19

typedef	struct	s_coordxy
{
	int	x;
	int	y;
}				t_coordxy;

typedef	struct	s_coord
{
	t_coordxy	coord_1;
	t_coordxy	coord_2;
	t_coordxy	coord_3;
	t_coordxy	coord_4;
}				t_coord;

typedef struct	s_piece
{
	struct s_coord	*coord;
	struct s_piece	*next;
}				t_piece;

int		ft_check_main(char *str);
int		ft_check_pattern(char *str);

#endif

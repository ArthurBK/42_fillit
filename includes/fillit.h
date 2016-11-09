/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:38:40 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/09 19:07:52 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# define NUMBER_OF_PATTERNS 19

typedef	struct	s_coordxy
{
	int					x;
	int					y;
	struct s_coordxy	*next;
}				t_coordxy;


typedef struct	s_piece
{
	struct s_coordxy	*coord;
	int					number;
	struct s_piece		*next;
}				t_piece;

int		ft_check_main(char *str);
int		ft_check_pattern(char *str);
t_piece         **ft_piece_to_coord(char **tab);

#endif

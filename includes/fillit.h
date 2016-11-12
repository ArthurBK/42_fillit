/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:38:40 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/12 16:37:50 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>

typedef	struct	s_coordxy
{
	int					x;
	int					y;
	int					number;
	struct s_coordxy	*next;
}				t_coordxy;

typedef	struct	s_coord
{
	t_coordxy	*coords;
	int			x_min;
	int			x_max;
	int			y_max;
	int			in;
	int			nb_pieces;
}				t_coord;

int		ft_check_main(char *str);
int		ft_check_pattern(char *str);
int		ft_check_valid_tet(int *i, int j, int k, char **pieces);
char	*ft_str_without_back_slash(char *str);
char	**ft_str_to_tab(char *str);
int		ft_nb_piece(char *str);
void	ft_solve(t_coord **pieces, int nb_pieces, int taille);
void	ft_print_tab(char **tab);
void	ft_lstaddxy(t_coordxy **alst, t_coordxy *new);
t_coord	*ft_push_coords(int x, int y, t_coord *piece_coords, int number);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_nb_piece(char *str);
int		ft_check_offy(char *str);
int		ft_check_offx(char *str);
t_coord	*ft_store(char *str, int number);
void	ft_find_limits(t_coord **piece, int nb_p);
t_coord	**ft_store_pieces(char **tab, int size, int nb_p);
void	ft_reset_piece(t_coord **piece, char **res, int x_index, int y_index);
void	ft_write_piece(t_coord **piece, char **res, int x_index, int y_index);
int		ft_check_htg(t_coord **piece, char **res, int x_index, int y_index, int size);
int		ft_all_pieces(t_coord **piece);
int		ft_taille_struct(t_coord **pieces);
int		ft_backtrack(t_coord **pieces, int size, char **res, int index);
void	ft_solve(t_coord **pieces, int nb_pieces, int taille);

#endif

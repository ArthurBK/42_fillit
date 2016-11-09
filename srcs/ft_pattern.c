/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pattern.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:14:03 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/09 15:38:03 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "libft.h"
#include <stdio.h>

/*
   const t_tetri  g_tetri[19] = {

//		while (i < NUMBER_OF_PATTERNS)
//		if (ft_strequ(g_tetri[i].pattern, )
{"
##..
##..
....
....", 2 },
{"####............", 0 },
{"#...#...#...#...", 3 },
{".##.##..........", 1 },
{"#...##...#......", 2 },
{"##...##.........", 1 },
{".#..##..#.......", 2 },
{".#...#..##......", 2 },
{"#...###.........", 1 },
{"##..#...#.......", 2 },
{"###...#.........", 1 },
{"###..#..........", 1 },
{".#..##...#......", 2 },
{".#..###.........", 1 },
{"#...##..#.......", 2 },
{"#...#...##......", 2 },
{"###.#...........", 1 },
{"##...#...#......", 2 },
{"..#.###.........", 1 }
};
*/
int	ft_check_pattern(char *str)
{
	char	**pieces;
	int i;
	int j;
	int k;
	int valid;

	j = 0;
	pieces = ft_strsplit(str, '\n');
	while (pieces[j])
	{
		valid = 1;
		k = 0;
		while (k <= 3)
		{
			i = 0;
			while (i < 4)
			{
				while (pieces[j][i] && pieces[j][i] != '#')
					i++;
				if (i == 3 && k != 3)
				{	
					if (pieces[j + 1][i] == '#')
						valid += 1;
				}
				else if(i < 3)
				{
					//				printf("p[j][i]: %c\n", pieces[j][i]);
					//	printf("pieces: %s\n", pieces[j]);
					if (k != 3)
					{
						if (pieces[j + 1][i] == '#')
							valid += 1;
						if (pieces[j][i + 1] == '#' && pieces[j + 1][i] == '#' && pieces[j + 1][i + 1] == '#' && k != 3 && i < 3)
							valid -= 1;
					}
					if (pieces[j][i + 1] == '#')
						valid += 1;
				}
				i++;
				//				printf("valid: %i\n", valid);
			}
			k++;
			j++;
		}
		//			printf("valid: %i\n", valid);
		if (valid != 4)
			return (-1);
	}
	return (1);
}

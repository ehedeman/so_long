/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:15:28 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/23 13:37:26 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_coordinates(int *x, int *y, int i, int j)
{
	*x = i;
	*y = j;
}

void	map_coordinates(t_game *game)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (game->map.content[i])
	{
		if (game->map.content[i] == 'E')
			set_coordinates(&game->map.exit_x, &game->map.exit_y, x, j);
		if (game->map.content[i] == 'P')
			set_coordinates(&game->map.player_x, &game->map.player_y, x, j);
		if (game->map.content[i] == 'C')
			set_coordinates(&game->map.item_x, &game->map.item_y, x, j);
		if (game->map.content[i] == '\n')
		{
			j++;
			x = 0;
		}
		else
			x++;
		i++;
	}
}

int	get_map_width_and_height(t_game *game)
{
	int	i;
	int	j;
	
	i = 1;
	j = 1;
	while (game->map.content[i])
	{
		if (game->map.content[i] == '\n')
			j++;
		i++;
	}
	game->map.width = (i - j + 1) / j; //newlines werden mitgezählt
	game->map.height = j;
	game->map.object_nbr = 0;
	game->map.size = i;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:45:27 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 15:43:47 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_whole_wall(t_game *game, int i)
{
	while (i <= game->map.width)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.addr,
			game->wall.x, game->wall.y);
		game->wall.x += 153;
		i++;
	}
	game->wall.x = game->map.centre_x - 153 * game->map.width / 2;
	game->wall.y += 153;
	return (0);
}

int	put_side_walls(t_game *game, int i, int j)
{
	while (i < game->map.height)
	{
		while (j <= game->map.width)
		{
			if (j == 1 || j == game->map.width)
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall.addr, game->wall.x, game->wall.y);
			game->wall.x += 153;
			j++;
		}
		game->wall.x = game->map.centre_x - 153 * game->map.width / 2;
		game->wall.y += 153;
		j = 1;
		i++;
	}
	return (0);
}

int	put_surrounding_wall(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	game->wall.x = game->map.centre_x - 153 * game->map.width / 2;
	game->wall.y = game->map.centre_y - 153 * game->map.height / 2;
	if (put_whole_wall(game, i) < 0)
		return (-9);
	if (put_side_walls(game, i + 1, j) < 0)
		return (-9);
	if (put_whole_wall(game, i) < 0)
		return (-9);
	return (0);
}

//for some reason whenever i put a condition to the mlx_put_image_to_window
//(only the beginning ones mind you), the pictures are in fact not put to the
//window. therefor this will not be included in the error messages.
//	Because what the actual fuck.

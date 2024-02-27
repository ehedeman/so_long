/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:31:23 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/23 16:49:38 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_item(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->item.addr, game->item.x, game->item.y);
}

int	put_objects_exit(t_game *game)
{
	int	i;
	int ret;

	i = 0;
	while (i < game->map.object_nbr)
	{
		ret = mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.addr,
				game->map.object_list[i].x, game->map.object_list[i].y);
		if (ret < 0)
			return (-4);
		i++;
	}
	if (game->map.item_collected == 0)
		ret = mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->exit.addr1, game->exit.x, game->exit.y);
	else if (game->map.item_collected == 1)
		ret = mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->exit.addr2, game->exit.x, game->exit.y);
	if (ret < 0)
		return (-4);
	return (0);
}

int	beginning_put_to_window(t_game *game)
{
	int	ret;

	set_player_coords_beginning(game);
	ret = mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map.background_adress, 0, 0);
	if (ret < 0)
		return (-4);
	ret = mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player.addr1, game->player.x, game->player.y);
	if (ret < 0)
		return (-4);
	ret = mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->item.addr, game->item.x, game->item.y);
	if (ret < 0)
		return (-4);
	put_surrounding_wall(game);
	beginning_put_objects_exit(game);
	return (0);
}
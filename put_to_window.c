/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:31:23 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 15:39:23 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_item(t_game *game)
{
	if (mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->item.addr, game->item.x, game->item.y))
		return (-9);
	return (0);
}

int	put_objects_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.object_nbr)
	{
		if (mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.addr,
				game->map.object_list[i].x, game->map.object_list[i].y))
			return (-9);
		i++;
	}
	if (game->map.item_collected == 0)
		if (mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->exit.addr1, game->exit.x, game->exit.y))
			return (-9);
	if (game->map.item_collected == 1)
		if (mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->exit.addr2, game->exit.x, game->exit.y))
			return (-9);
	return (0);
}

int	beginning_put_objects_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.object_nbr)
	{
		game->map.object_list[i].x = game->map.left_border + \
			(game->map.object_list[i].x) * 153;
		game->map.object_list[i].y = game->map.upper_border + \
			(game->map.object_list[i].y) * 153;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.addr,
			game->map.object_list[i].x, game->map.object_list[i].y);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->exit.addr1, game->exit.x, game->exit.y);
	return (0);
}

int	beginning_put_to_window(t_game *game)
{
	set_player_coords_beginning(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.background_adress, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player.addr1, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->item.addr, game->item.x, game->item.y);
	put_surrounding_wall(game);
	beginning_put_objects_exit(game);
	return (0);
}

// int	beginning_put_to_window(t_game *game)
// {
// 	set_player_coords_beginning(game);
// 	if (mlx_put_image_to_window(game->mlx, game->mlx_win,
// 			game->map.background_adress, 0, 0))
// 		return (-9);
// 	if (mlx_put_image_to_window(game->mlx, game->mlx_win,
// 			game->player.addr1, game->player.x, game->player.y))
// 		return (-9);
// 	if (mlx_put_image_to_window(game->mlx, game->mlx_win,
// 			game->item.addr, game->item.x, game->item.y))
// 		return (-9);
// 	if (put_surrounding_wall(game) < 0)
// 		return (-9);
// 	if (beginning_put_objects_exit(game) < 0)
// 		return (-9);
// 	return (0);
// }
// int	beginning_put_objects_exit(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->map.object_nbr)
// 	{
// 		game->map.object_list[i].x = game->map.left_border + \
// 			(game->map.object_list[i].x) * 153;
// 		game->map.object_list[i].y = game->map.upper_border + \
// 			(game->map.object_list[i].y) * 153;
// 		if (mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall.addr,
// 				game->map.object_list[i].x, game->map.object_list[i].y))
// 			return (-9);
// 		i++;
// 	}
// 	if (mlx_put_image_to_window(game->mlx, game->mlx_win,
// 			game->exit.addr1, game->exit.x, game->exit.y))
// 		return (-9);
// 	return (0);
// }

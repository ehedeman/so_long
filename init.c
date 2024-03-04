/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:23:50 by ehedeman          #+#    #+#             */
/*   Updated: 2024/03/04 12:09:51 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-7);
	game->mlx_win = mlx_new_window(game->mlx, 3840, 2110, "so_long");
	if (!game->mlx_win)
		return (-7);
	if (mlx_hook(game->mlx_win, 2, 1L << 0, key_handler, game) == 0)
		return (-10);
	if (mlx_hook(game->mlx_win, 17, 1L << 0, close_window, game) == 0)
		return (-10);
	// if (mlx_mouse_hook(game->mlx_win, mouse_handler, game) == 0)
	// 	return (-10);
	game->message_height = 200;
	game->message_width = 800;
	game->message_addr = mlx_xpm_file_to_image(game->mlx, MESSAGE_PATH,
			&game->message_width, &game->message_height);
	if (!game->message_addr)
		return (-7);
	return (0);
}

int	bckg_wall_item_init(t_game *game)
{
	int	size;

	size = 153;
	game->wall.addr = mlx_xpm_file_to_image(game->mlx, WALL_PATH,
			&size, &size);
	if (!game->wall.addr)
		return (-7);
	game->map.background_adress = mlx_xpm_file_to_image(game->mlx,
			BACKGROUND_PATH, &game->win_width, &game->win_height);
	if (!game->map.background_adress)
		return (-7);
	game->item.width = 153;
	game->item.height = 153;
	game->item.addr = mlx_xpm_file_to_image(game->mlx, ITEM_PATH,
			&game->item.width, &game->item.height);
	if (!game->item.addr)
		return (-7);
	return (0);
}

int	init(t_game *game, char *filename)
{
	int	ret;

	ret = map_init(filename, game);
	if (ret < 0)
		return (ret);
	ret = valid_map(game);
	if (ret < 0)
		return (ret);
	ret = game_init(game);
	if (ret < 0)
		return (ret);
	ret = player_init(game);
	if (ret < 0)
		return (ret);
	ret = bckg_wall_item_init(game);
	if (ret < 0)
		return (ret);
	ret = exit_init(game);
	if (ret < 0)
		return (ret);
	ret = object_list_init(game, 0, 0);
	if (ret < 0)
		return (ret);
	return (0);
}

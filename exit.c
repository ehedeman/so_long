/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:38:29 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 15:18:36 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	if ((game->player.x == game->exit.x
			&& game->player.y == game->exit.y)
		&& game->map.item_collected == 1)
	{
		game->game_won = 1;
		mlx_clear_window(game->mlx, game->mlx_win);
		if (mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->message_addr, (game->map.centre_x - 400),
				(game->map.centre_y - 100)))
			return (-9);
	}
	return (0);
}

int	exit_init(t_game *game)
{
	game->exit.width = 153;
	game->exit.height = 153;
	game->exit.addr1 = mlx_xpm_file_to_image(game->mlx, EXIT_PATH1,
			&game->exit.width, &game->exit.height);
	if (!game->exit.addr1)
		return (-7);
	game->exit.addr2 = mlx_xpm_file_to_image(game->mlx, EXIT_PATH2,
			&game->exit.width, &game->exit.height);
	if (!game->exit.addr2)
		return (-7);
	return (0);
}

int	exit_closed(t_game *game, int direction)
{
	int	d;

	d = direction;
	if (game->player.y - 153 == game->exit.y && d == 1
		&& (game->player.x == game->exit.x))
		return (1);
	if (game->player.y + 153 == game->exit.y && d == 2
		&& (game->player.x == game->exit.x))
		return (1);
	if (game->player.x - 153 == game->exit.x && d == 3
		&& (game->player.y == game->exit.y))
		return (1);
	if (game->player.x + 153 == game->exit.x && d == 4
		&& (game->player.y == game->exit.y))
		return (1);
	return (0);
}

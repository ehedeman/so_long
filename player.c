/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:20:05 by ehedeman          #+#    #+#             */
/*   Updated: 2024/03/01 12:14:55 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_init(t_game *game)
{
	game->player.height = 153;
	game->player.width = 138;
	game->player.addr1 = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH1,
			&game->player.width, &game->player.height);
	if (!game->player.addr1)
		return (-7);
	game->player.addr2 = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH2,
			&game->player.width, &game->player.height);
	if (!game->player.addr2)
		return (-7);
	return (0);
}

int	change_coords_put_bckg(t_game *game, int up_or_down, int left_or_right)
{
	if (up_or_down == 1)
		game->player.y += 153;
	else if (up_or_down == 2)
		game->player.y -= 153;
	if (left_or_right == 1)
		game->player.x += 153;
	else if (left_or_right == 2)
		game->player.x -= 153;
	if (mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map.background_adress, 0, 0))
		return (-9);
	return (0);
}

int	move_player(t_game *game, int up_or_down, int left_or_right, int spritenbr)
{
	game->steps++;
	ft_printf("Steps so far: %i\n", game->steps);
	mlx_clear_window(game->mlx, game->mlx_win);
	if (change_coords_put_bckg(game, up_or_down, left_or_right) < 0)
		return (-9);
	item_collected(game);
	if (put_objects_exit(game) < 0)
		return (-9);
	if (spritenbr < 2)
		if (mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->player.addr1, game->player.x, game->player.y))
			return (-9);
	if (spritenbr == 2)
		if (mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->player.addr2, game->player.x, game->player.y))
			return (-9);
	if (game->map.item_collected == 0)
		if (put_item(game) < 0)
			return (-9);
	if (put_surrounding_wall(game) < 0)
		return (-9);
	exit_game(game);
	return (0);
}

void	set_player_coords_beginning(t_game *game)
{
	game->map.centre_x = 1920;
	game->map.centre_y = 1055;
	game->map.left_border = game->map.centre_x - 153 * game->map.width / 2;
	game->map.right_border = game->map.centre_x + 153 * game->map.width / 2;
	game->map.upper_border = game->map.centre_y - 153 * game->map.height / 2;
	game->map.lower_border = game->map.centre_y + 153 * game->map.height / 2;
	game->player.x = (game->map.left_border + game->map.player_x * 153);
	game->player.y = (game->map.upper_border + game->map.player_y * 153);
	game->item.x = (game->map.left_border + game->map.item_x * 153);
	game->item.y = (game->map.upper_border + game->map.item_y * 153);
	game->exit.x = (game->map.left_border + game->map.exit_x * 153);
	game->exit.y = (game->map.upper_border + game->map.exit_y * 153);
	game->map.item_collected = 0;
	game->game_won = 0;
}

void	item_collected(t_game *game)
{
	if (game->player.x == game->item.x
		&& game->player.y == game->item.y)
	{
		game->map.item_collected = 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:20:05 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 11:46:06 by ehedeman         ###   ########.fr       */
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
		return (-1);
	game->player.addr2 = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH2,
			&game->player.width, &game->player.height);
	if (!game->player.addr2)
		return (-1);
	return (0);
}

void	change_coords(t_game *game, int up_or_down, int left_or_right)
{
	if (up_or_down == 1)
		game->player.y += 153;
	else if (up_or_down == 2)
		game->player.y -= 153;
	if (left_or_right == 1)
		game->player.x += 153;
	else if (left_or_right == 2)
		game->player.x -= 153;
}

int	move_player(t_game *game, int up_or_down, int left_or_right, int spritenbr)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	change_coords(game, up_or_down, left_or_right);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map.background_adress, 0, 0);
	put_objects_exit(game);
	if (spritenbr < 2)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.addr1,
			game->player.x, game->player.y);
	if (spritenbr == 2)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.addr2,
			game->player.x, game->player.y);
	item_collected(game);
	if (game->map.item_collected == 0)
		put_item(game);
	put_surrounding_wall(game);
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

int item_collected(t_game *game)
{
	if (game->player.x == game->item.x
		&& game->player.y == game->item.y)
	{
		game->map.item_collected = 1;
	}
	return (0);
}
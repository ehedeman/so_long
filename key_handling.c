/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:50:14 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 12:01:51 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.addr1);
	mlx_destroy_image(game->mlx, game->player.addr2);
	mlx_destroy_image(game->mlx, game->map.background_adress);
	mlx_destroy_image(game->mlx, game->wall.addr);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->map.object_list);
	free(game->mlx);
	return (0);
}

int	key_handler(int key, t_game *game)
{
	if (key == XK_ESCAPE)
	{
		ft_printf("The key %d (ESC) has been pressed \n\n", key);
		free_all(game);
		exit(1);
	}
	if (game->game_won == 0)
	{
		printf("%i\n\n", key);
		if ((key == 119 || key == 65362) && check_for_objects(game, 1) == 0) //&& check_for_objects(game) == 0) //up
			move_player(game, 2, 0, 0);
		if ((key == 115 || key == 65364) && check_for_objects(game, 2) == 0)//&& check_for_objects(game) == 0) //down
			move_player(game, 1, 0, 0);
		if ((key == 97 || key == 65361) && check_for_objects(game, 3) == 0)//&& check_for_objects(game) == 0) //left
			move_player(game, 0, 2, 1);
		if ((key == 100 || key == 65363) && check_for_objects(game, 4) == 0)//&& check_for_objects(game) == 0) //right
			move_player(game, 0, 1, 2);
	}
	return (0);
}

int	is_within_bounds(t_game *game, int i)
{
	if (game->player.y - 50 < game->map.upper_border + 153 && i == 1)
		return (1);
	else if (game->player.y + 50 > game->map.lower_border - 153 * 2 && i == 2)
		return (1);
	else if (game->player.x - 50 < game->map.left_border + 153 && i == 3)
		return (1);
	else if (game->player.x + 50 > game->map.right_border -153 * 2&& i == 4)
		return (1);
	return (0);
}

int	is_on_object(t_game *game, int d)
{
	int i;

	i = 0;
	while (game->map.object_nbr > i)
	{
		if (game->player.y - 153 == game->map.object_list[i].y && d == 1
			&& (game->player.x == game->map.object_list[i].x))
			return (1);
		if (game->player.y + 153 == game->map.object_list[i].y && d == 2
			&& (game->player.x  == game->map.object_list[i].x))
			return (1);
		if (game->player.x - 153 == game->map.object_list[i].x && d == 3
			&& (game->player.y == game->map.object_list[i].y))
			return (1);
		if (game->player.x + 153 == game->map.object_list[i].x && d == 4
			&& (game->player.y == game->map.object_list[i].y))
			return (1);
		i++;
	}
	return (0);
}

int	check_for_objects(t_game *game, int direction)
{
	if (is_within_bounds(game, direction) == 1)
		return (1);
	if (is_on_object(game, direction) == 1)
		return (1);
	if (exit_closed(game, direction) == 1 && game->map.item_collected == 0)
		return (1);
	//insert Bedingung aus altem header bzgl der koordinaten vom Objekt und so
	//objekt is noch nicht fertig also geht das grad noch nich.
	//muss aber eigentlich
	//else
	return (0);
}

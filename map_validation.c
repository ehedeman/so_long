/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:15:40 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 12:07:20 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(t_game *game)
{
	if (game->map.width == game->map.height)
		return (-5);
	if (game->map.width < 5 || game->map.height < 3)
		return (-5);
	if (game->map.width > 25 || game->map.height > 13)
		return (-5);
	if (game->map.item_x == 0)
		return (-5);
	if (game->map.exit_x == 0)
		return (-5);
	if (game->map.player_x == 0)
		return (-5);
	if (illegal_symbol(game, 1) == 1)
		return (-5);
	if (check_borders(game, 0, 0, 0) == 1)
		return (-5);
	if (map_shape(game, 0, 0) == 1)
		return (-5);
	return (0);
}

int	check_borders(t_game *game, int i, int j, int x)
{
	while (i < game->map.size)
	{
		if (game->map.content[i] != '1' && j == 0 && x != game->map.width)
			return (1);
		if (game->map.content[i] != '1'
			&& game->map.content[i + 1] == '\n')
			return (1);
		if (game->map.content[i] != '1' && x == 0)
			return (1);
		if (game->map.content[i] != '1' && j == game->map.height - 1)
			return (1);
		if (game->map.content[i] == '\n')
		{
			j++;
			x = -1;
		}
		x++;
		i++;
	}
	return (0);
}

int	set_coords_zero(t_game *game)
{
	game->map.left_border = 0;
	game->map.right_border = 0;
	game->map.upper_border = 0;
	game->map.lower_border = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->map.item_x = 0;
	game->map.item_y = 0;
	game->map.exit_x = 0;
	game->map.exit_y = 0;
	return (0);
}

int	illegal_symbol(t_game *game, int i)
{
	while (game->map.content[i])
	{
		if (!ft_strchr("10ECP", game->map.content[i])
			&& game->map.content[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	map_shape(t_game *game, int i, int j)
{
	int	first_row_width;
	
	first_row_width = 1;
	while (game->map.content[i] != '\n')
	{
		i++;
		first_row_width++;
	}
	while (game->map.content[i])
	{
		if (game->map.content[i] == '\n')
		{
			if (j == first_row_width || j > first_row_width)
				return (1);
			j = 0;
			i++;
		}
		j++;
		i++;
	}
	return (0);
}

//noch nicht fertig, first_row_width wsl zu gros (in der letzten reihe
//ist keine newline sprich j automatisch) kleiner als first_row_width
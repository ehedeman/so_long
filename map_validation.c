/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:15:40 by ehedeman          #+#    #+#             */
/*   Updated: 2024/03/01 16:26:34 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(t_game *game)
{
	if (game->map.width == game->map.height)
		return (-6);
	if (game->map.width < 5 || game->map.height < 3)
		return (-17);
	if (game->map.width > 25 || game->map.height > 13)
		return (-16);
	if (game->map.item_x == 0)
		return (-15);
	if (game->map.exit_x == 0)
		return (-15);
	if (game->map.player_x == 0)
		return (-15);
	if (check_symbols(game, 1) == 1)
		return (-12);
	if (check_borders(game, 0, 0, 0) == 1)
		return (-13);
	if (map_shape(game, 0, 0) == 1)
		return (-14);
	if (split_map(game) == 1)
		return (-11);
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

int	check_symbols(t_game *game, int i)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	while (game->map.content[i])
	{
		if (!ft_strchr("10ECP", game->map.content[i])
			&& game->map.content[i] != '\n')
			return (1);
		if (game->map.content[i] == 'C')
			c++;
		if (game->map.content[i] == 'P')
			p++;
		if (game->map.content[i] == 'E')
			e++;
		i++;
	}
	if (e > 1 || p > 1 || c > 1)
		return (1);
	return (0);
}

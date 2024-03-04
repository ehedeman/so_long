/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:09:52 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 15:28:54 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_map_objects(t_game *game, int i, int j)
{
	int	object_counter;
	int	x;

	x = 0;
	object_counter = 0;
	while (game->map.content[i])
	{
		if (game->map.content[i] == '1' && (j < game->map.height - 1 && j > 0)
			&& (x < game->map.width - 1 && x > 0))
		{
			game->map.object_list[object_counter].x = x;
			game->map.object_list[object_counter].y = j;
			object_counter++;
		}
		if (game->map.content[i] == '\n')
		{
			i++;
			x = 0;
			j++;
		}
		x++;
		i++;
	}
}

int	object_allocation(t_game *game)
{
	if (game->map.object_nbr > 0)
	{
		game->map.object_list = malloc(sizeof(t_object) * game->map.object_nbr);
		if (!game->map.object_list)
			return (-8);
		find_map_objects(game, 0, 0);
	}
	return (0);
}

int	object_list_init(t_game *game, int i, int j)
{
	int	x;

	x = 0;
	while (game->map.content[i])
	{
		if (game->map.content[i] == '1' && (j < game->map.height - 1 && j > 0)
			&& (x < game->map.width - 1 && x > 0))
		{
			game->map.object_nbr++;
		}
		if (game->map.content[i] == '\n')
		{
			i++;
			j++;
			x = 0;
		}
		x++;
		i++;
	}
	if (object_allocation(game) < 0)
		return (-8);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:16:26 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/23 17:36:41 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error_handling(int index, t_game *game)
{
	if (index == -1)
	{
		printf("ERROR: Number of Argumets.");
		return (0);
	}
	else if (index == -2)
		printf("ERROR: Malloc Error.");
	else if (index == -3)
		printf("ERROR: Reading File.");
	else if (index == -4)
		printf("ERROR: Image Error.");
	else if (index == -5)
		printf("ERROR: Invalid Map.");
	if (game->mlx)
		free(game->mlx);
	exit(1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:16:26 by ehedeman          #+#    #+#             */
/*   Updated: 2024/03/04 12:44:48 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_addr(t_game *game)
{
	if (game->mlx)
	{
		if (game->player.addr1)
			mlx_destroy_image(game->mlx, game->player.addr1);
		if (game->player.addr2)
			mlx_destroy_image(game->mlx, game->player.addr2);
		if (game->exit.addr2)
			mlx_destroy_image(game->mlx, game->exit.addr2);
		if (game->exit.addr1)
			mlx_destroy_image(game->mlx, game->exit.addr1);
		if (game->map.background_adress)
			mlx_destroy_image(game->mlx, game->map.background_adress);
		if (game->wall.addr)
			mlx_destroy_image(game->mlx, game->wall.addr);
		if (game->item.addr)
			mlx_destroy_image(game->mlx, game->item.addr);
		if (game->message_addr)
			mlx_destroy_image(game->mlx, game->message_addr);
		if (game->mlx_win)
			mlx_destroy_window(game->mlx, game->mlx_win);
		free(game->mlx);
	}
}

void	first_error(int index)
{
	if (index == -2)
		ft_printf("ERROR: Memory Allocation Fail.");
	else if (index == -3)
		ft_printf("ERROR: File Type Incorrect.");
	else if (index == -4)
		ft_printf("ERROR: File Path Incorrect.");
	else if (index == -5)
		ft_printf("ERROR: Failed To Read Map.");
	else if (index == -6)
		ft_printf("ERROR: Map Has To Be Rectangular.");
	else if (index == -7)
		ft_printf("ERROR: Address Could Not Be Allocated.");
	else if (index == -8)
		ft_printf("ERROR: Failed To Render Objects.");
	else if (index == -9)
		ft_printf("ERROR: Failed To Put Image.");
	else if (index == -10)
		ft_printf("ERROR: Mlx_hook Could Not Be Established.");
}

void	second_error(int index)
{
	if (index == -11)
		ft_printf("ERROR: No Possible Path.");
	else if (index == -12)
		ft_printf("ERROR: False or Duplicate Map-Symbols.");
	else if (index == -13)
		ft_printf("ERROR: Map-Borders Invalid.");
	else if (index == -14)
		ft_printf("ERROR: Map-Shape Invalid.");
	else if (index == -15)
		ft_printf("ERROR: Map-Symbol Missing.");
	else if (index == -16)
		ft_printf("ERROR: Map Too Tall.");
	else if (index == -17)
		ft_printf("ERROR: Map Too Small.");
	else if (index == -18)
		ft_printf("Window X Button Pressed. Game Closed.");
	else if (index == 65307)
		ft_printf("The key -65307 (ESC) has been pressed. Game closed.\n\n");
}

void	errors(int index, t_game *game)
{
	first_error(index);
	second_error(index);
	if (game->map.content)
		free(game->map.content);
	if (game->map.object_list)
		free(game->map.object_list);
	free_addr(game);
	exit(0);
}

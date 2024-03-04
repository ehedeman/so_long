/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:06:01 by ehedeman          #+#    #+#             */
/*   Updated: 2024/03/01 16:12:59 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		ret;

	if (argc != 2)
	{
		ft_printf("ERROR: Number of Argumets.");
		return (0);
	}
	set_to_zero(&game);
	ret = correct_input(argv[1]);
	if (ret < 0)
		errors(ret, &game);
	game.win_height = 2160;
	game.win_width = 3840;
	ret = init(&game, argv[1]);
	if (ret < 0)
		errors(ret, &game);
	ret = beginning_put_to_window(&game);
	if (ret == -4)
		errors(ret, &game);
	mlx_loop(game.mlx);
}

int	correct_input(char *file)
{
	int	ret;

	ret = filetype(file);
	if (ret < 0)
		return (ret);
	ret = file_placement(file);
	if (ret < 0)
		return (ret);
	return (0);
}

int	filetype(char *file)
{
	char	*temp;

	temp = malloc(sizeof(char) * 5);
	if (!temp)
		return (-2);
	ft_strlcpy(temp, &file[ft_strlen(file) - 4], 5);
	if (!ft_strnstr(temp, ".ber", ft_strlen(temp)))
	{
		free(temp);
		return (-3);
	}
	free(temp);
	return (0);
}

int	file_placement(char *file)
{
	char	*temp;

	temp = malloc(sizeof(char) * 6);
	if (!temp)
		return (-2);
	ft_strlcpy(temp, file, 6);
	if (!ft_strnstr(temp, "maps/", ft_strlen(temp)))
	{
		free(temp);
		return (-4);
	}
	free(temp);
	return (0);
}

int	set_to_zero(t_game *game)
{
	game->mlx = 0;
	game->mlx_win = 0;
	game->message_addr = 0;
	game->player.addr1 = 0;
	game->player.addr2 = 0;
	game->item.addr = 0;
	game->exit.addr1 = 0;
	game->exit.addr2 = 0;
	game->map.background_adress = 0;
	game->wall.addr = 0;
	game->steps = 0;
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
	game->map.possible_path = 0;
	game->map.object_list = 0;
	return (0);
}

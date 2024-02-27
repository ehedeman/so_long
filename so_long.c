/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:06:01 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 12:08:32 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	*filename;
	int		ret;

	if (argc != 2)
		return (error_handling(-1, &game));
	game.mlx = 0;
	filename = argv[1];
	ret = filetype(filename);
	if (ret < 0)
		error_handling(ret, &game);
	game.win_height = 2160;
	game.win_width = 3840;
	set_coords_zero(&game);
	ret = init(&game, argv[1]);
	if (ret < 0)
		error_handling(ret, &game);
	ret = beginning_put_to_window(&game);
	if (ret == -4)
		error_handling(ret, &game);
	mlx_loop(game.mlx);
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
		return (-5);
	}
	return (0);
}
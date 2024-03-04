/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:50:15 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 15:14:05 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_join(t_game *game, char buf[], int fd)
{
	char	*temp;

	temp = ft_strjoin(game->map.content, buf);
	free(game->map.content);
	game->map.content = temp;
	if (!game->map.content)
	{
		close(fd);
		return (-2);
	}
	return (0);
}

int	map_read(t_game *game, int fd, char buf[])
{
	int	ret;

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
		{
			free(game->map.content);
			close(fd);
			return (-5);
		}
		else
		{
			buf[ret] = 0;
			if (map_join(game, buf, fd) == -2)
				return (-2);
		}
	}
	return (0);
}

int	map_init(char *filename, t_game *game)
{
	int		fd;
	char	buf[1024 + 1];
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-5);
	game->map.content = ft_calloc(1, 1);
	if (!game->map.content)
	{
		close(fd);
		return (-2);
	}
	ret = map_read(game, fd, buf);
	if (ret < 0)
		return (ret);
	close(fd);
	map_coordinates(game, 0, 0, 0);
	get_map_width_and_height(game);
	return (0);
}

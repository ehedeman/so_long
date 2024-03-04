/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:54:16 by ehedeman          #+#    #+#             */
/*   Updated: 2024/03/01 15:47:00 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void path_player_to_item(int x, int y, char *a[], t_game *game)
{
    char    target;
    char    color;

    target = '0';
    color = '1';
    if (a[y][x] == 'C')
    {
        game->map.possible_path = 1;
        return;
    }
    if (a[y][x] == color)
        return;
    if (a[y][x] != target && a[y][x] != 'P')
        return;
    a[y][x] = '1';
    if (a[y][x] != 'C')
    {
        path_player_to_item(x + 1, y, a, game);
        path_player_to_item(x, y + 1, a, game);
        path_player_to_item(x - 1, y, a, game);
        path_player_to_item(x, y - 1, a, game);
    }
    return;
}

void path_item_to_exit(int x, int y, char *a[], t_game *game)
{
    char    target;
    char    color;

    target = '0';
    color = '1';
    if (a[y][x] == 'E')
    {
        game->map.possible_path = 1;
        return;
    }
    if (a[y][x] == color)
        return;
    if (a[y][x] != target && a[y][x] != 'C' && a[y][x] != 'P')
        return;
    a[y][x] = '1';
    if (a[y][x] != 'E')
    {
        path_item_to_exit(x + 1, y, a, game);
        path_item_to_exit(x, y + 1, a, game);
        path_item_to_exit(x - 1, y, a, game);
        path_item_to_exit(x, y - 1, a, game);
    }
    return;
}

void    free_map(char **array, int i)
{
    int j;

    j = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int split_map(t_game *game)
{
    char    **array;

    array = ft_split(game->map.content, '\n');
    path_player_to_item(game->map.player_x, game->map.player_y, array, game);
    free_map(array, 0);
    if (game->map.possible_path == 0)
       return (1);
    game->map.possible_path = 0;
    array = ft_split(game->map.content, '\n');
    path_item_to_exit(game->map.item_x, game->map.item_y, array, game);
    free_map(array, 0);
    if (game->map.possible_path == 0)
        return (1);
    return (0);
}

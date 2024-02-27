/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:01:52 by ehedeman          #+#    #+#             */
/*   Updated: 2024/02/27 12:02:31 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include <string.h>
#include "libft/libft.h"
#define PLAYER_PATH1 "sprites/Player_character_L.xpm"
#define PLAYER_PATH2 "sprites/Player_character_R.xpm"
#define BACKGROUND_PATH "sprites/Background.xpm"
#define WALL_PATH "sprites/Object.xpm"
#define ITEM_PATH "sprites/Item.xpm"
#define MESSAGE_PATH "sprites/Message.xpm"
#define EXIT_PATH1 "sprites/Exit_1.xpm"
#define EXIT_PATH2 "sprites/Exit_2.xpm"
#define XK_ESCAPE 65307

typedef struct s_player
{
	void	*addr1;
	void	*addr2;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_player;

typedef struct s_wall
{
	void	*addr;
	int		y;
	int		x;
}	t_wall;

typedef struct s_object
{
	int	x;
	int	y;
}	t_object;

typedef struct s_map
{
	char		*content;
	void		*background_adress;
	int			size;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			item_x;
	int			item_y;
	int			item_collected;
	int			exit_x;
	int			exit_y;
	int			centre_x;
	int			centre_y;
	int			left_border;
	int			right_border;
	int			upper_border;
	int			lower_border;
	int			object_nbr;
	t_object	*object_list;
}	t_map;

typedef struct s_item
{
	void	*addr;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_item;

typedef struct s_exit
{
	void	*addr1;
	void	*addr2;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_exit;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	void			*message_addr;
	int				message_height;
	int				message_width;
	int				win_height;
	int				win_width;
	int				game_won;
	t_player		player;
	t_item			item;
	t_map			map;
	t_wall			wall;
	t_exit			exit;
}	t_game;

//beginning functions
int		filetype(char *file);
int		game_init(t_game *game);
int		player_init(t_game *game);
int		init(t_game *game, char *filename);
int		bckg_wall_item_init(t_game *game);
int		map_init(char *filename, t_game *game);
int		error_handling(int index, t_game *game);
int		map_read(t_game *game, int fd, char buf[]);
int		map_join(t_game *game, char buf[], int fd);
void	map_coordinates(t_game *game);
void	set_coordinates(int *x, int *y, int j, int i);
int		key_handler(int key, t_game *game);
int		beginning_put_to_window(t_game *game);
int		move_player(t_game *game, int up_or_down, int left_or_right,
			int spritenbr);
int		check_for_objects(t_game *game, int direction);
int		get_map_width_and_height(t_game *game);
void	set_player_coords_beginning(t_game *game);
int		put_surrounding_wall(t_game *game);
int		find_map_objects(t_game *game, int i, int j);
int		beginning_put_objects_exit(t_game *game);
int		put_objects_exit(t_game *game);
int		object_list_init(t_game *game, int i, int j);
void	put_item(t_game *game);
int		set_coords_zero(t_game *game);
int		check_borders(t_game *game, int i, int j, int x);
int		valid_map(t_game *game);
int		illegal_symbol(t_game *game, int i);
int		map_shape(t_game *game, int i, int j);
int		item_collected(t_game *game);
int		exit_game(t_game *game);
int		exit_init(t_game *game);
int		exit_closed(t_game *game, int direction);
//end functions

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:01:52 by ehedeman          #+#    #+#             */
/*   Updated: 2024/03/04 12:08:46 by ehedeman         ###   ########.fr       */
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
#define MAP_STRING2 "111111111111111111\n"\
                    "100000000000000001\n"\
                    "1E0000000010000001\n"\
                    "100000000011111111\n"\
                    "100000000010000001\n"\
                    "10000P000010000001\n"\
                    "100000000010000001\n"\
                    "100000000010000001\n"\
                    "10000000001000C001\n"\
                    "100000000010000001\n"\
                    "111111111111111111"
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
	int			possible_path;
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
	int				steps;
}	t_game;
//beginning functions
void	errors(int index, t_game *game);
int		correct_input(char *file);
int		filetype(char *file);
int		file_placement(char *file);
int		set_to_zero(t_game *game);
int		init(t_game *game, char *filename);
int		map_init(char *filename, t_game *game);
int		map_read(t_game *game, int fd, char buf[]);
int		map_join(t_game *game, char buf[], int fd);
int		valid_map(t_game *game);
int		split_map(t_game *game);
int		check_borders(t_game *game, int i, int j, int x);
int		map_shape(t_game *game, int i, int j);
int		check_symbols(t_game *game, int i);
void	get_map_width_and_height(t_game *game);
void	map_coordinates(t_game *game, int i, int j, int x);
int		game_init(t_game *game);
int		player_init(t_game *game);
void	set_player_coords_beginning(t_game *game);
int		bckg_wall_item_init(t_game *game);
int		exit_init(t_game *game);
int		object_list_init(t_game *game, int i, int j);
int		beginning_put_to_window(t_game *game);
int		put_surrounding_wall(t_game *game);
int		put_objects_exit(t_game *game);
int		put_item(t_game *game);
int		key_handler(int key, t_game *game);
int 	close_window(t_game *game);
int		change_coords_put_bckg(t_game *game, int up_or_down, int left_or_right);
int		move_player(t_game *game, int up_or_down, int left_or_right,
			int spritenbr);
int		exit_game(t_game *game);
int		exit_closed(t_game *game, int direction);
void	item_collected(t_game *game);
//end functions

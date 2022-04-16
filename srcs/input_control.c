#include "../includes/so_long.h"

void exit_modes(int exit_mode)
{
	if (exit_mode == 0)
		perror("Error\n");
	if (exit_mode == 1)
		ft_printf("You left dude come back... ");
	if (exit_mode == 2)
		ft_printf("Congrats! You`ve succesfully trapped the Kittens in the Tree");
	if (exit_mode == 3)
		ft_printf("Error\nInvalid Map");
	if (exit_mode == 4)
		ft_printf("Error\ntoo many or too less Player spawn points");
	if (exit_mode == 5)
		ft_printf("Error\nNo Collectibles found");
	if (exit_mode == 6)
		ft_printf("Error\nLess than 1 Exit availible");
	if (exit_mode == 7)
		ft_printf("Error\nInvalid Map, row too short");
	if (exit_mode == 8)
		ft_printf("Error\nInvalid Map, forbidden characters");
	
}

int	exit_game(t_gamedata *gamedata, int exit_mode)
{
	exit_modes(exit_mode);
	if (gamedata->wall_object != NULL)
		mlx_destroy_image(gamedata->mlx, gamedata->wall_object);
	if (gamedata->collectible_object != NULL)
		mlx_destroy_image(gamedata->mlx, gamedata->collectible_object);
	if (gamedata->exit_object != NULL)
		mlx_destroy_image(gamedata->mlx, gamedata->exit_object);
	if (gamedata->player_up_object != NULL)
		mlx_destroy_image(gamedata->mlx, gamedata->player_up_object);
	if (gamedata->player_left_object != NULL)
		mlx_destroy_image(gamedata->mlx, gamedata->player_left_object);
	if (gamedata->player_down_object != NULL)
		mlx_destroy_image(gamedata->mlx, gamedata->player_down_object);
	if (gamedata->player_right_object != NULL)
		mlx_destroy_image(gamedata->mlx, gamedata->player_right_object);
	if (gamedata->map != NULL)
		free_map(gamedata->map);
	if (gamedata)
		free(gamedata);
	exit(exit_mode);
}

int	key_event(int key, t_gamedata *gamedata)
{
	if (key == W)
		move_character_up(gamedata);
	if (key == A)
		move_character_left(gamedata);
	if (key == S)
		move_character_down(gamedata);
	if (key == D)
		move_character_right(gamedata);
	if (key == ESC)
		exit_game(gamedata, 1);
	return (0);
}
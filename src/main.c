#include "../inc/game_of_life.h"

void	FREEER(t_game *game)
{
	if (game->alive == WIDTH * HEIGHT)
		printf("Specys invaded all the map after generation %d.\n", game->generation);
	CloseWindow();
	exit(0);
}

void	INIT_Game(t_game *game, int argc, char **argv)
{
	int	probability;

	if (argc < 2)
		probability = 8; //ft_random(ft_random_seed(0), 100, 0);
	else
		probability = ft_atoi(argv[1]);
	game->paused = 0;
	game->generation= 0;
	game->wait_time = 50000;
	INIT_Map(game->first_map, probability);
	INIT_Empty_Map(game->second_map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	INIT_Game(&game, argc, argv);
	GAME_Of_Life(&game);
}

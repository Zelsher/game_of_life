#include "../inc/game_of_life.h"

void	WAITER(t_game *game)
{
	int	i;
	while (i < 10)
	{
		usleep(game->wait_time);
		HANDLE_Input(game);
		i++;
	}
}

void	INIT_Window(t_game *game)
{
	InitWindow(WIDTH * PIXEL, HEIGHT * PIXEL, "LIVE GAME");
	ClearBackground(BLACK);
	game->prevMousePos.x = 0;
	game->prevMousePos.y = 0;
    game->camera.target = (Vector2){ 0 };
    game->camera.offset = (Vector2){ 0, 0};
    game->camera.rotation = 0.0f;
    game->camera.zoom = 1.0f;
	printf("ZOOM %f", game->camera.zoom);
}

void	GAME_Of_Life(t_game *game)
{
	INIT_Window(game);
	DISPLAY_Map(game, game->first_map);
	WAITER(game);
	while (!WindowShouldClose()) 
	{
		if (!game->paused)
		{		
			UPDATE_Map(game->first_map, game->second_map, game);
			UPDATE_Map(game->second_map, game->first_map, game);
		}
		else
			HANDLE_Pause_Input(game);
	}
}


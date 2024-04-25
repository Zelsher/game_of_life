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
	InitWindow(WIDTH * PIXEL, HEIGHT * PIXEL, "Game Of Life");
	ClearBackground(BLACK);
	game->data.prevMousePos.x = 0;
	game->data.prevMousePos.y = 0;
    game->camera.target = (Vector2){ 0 };
    game->camera.offset = (Vector2){ 0, 0};
    game->camera.rotation = 0.0f;
    game->camera.zoom = 1.0f;
}

void	GAME_Of_Life(t_game *game)
{
	INIT_Window(game);
	BeginDrawing();
	BeginMode2D(game->camera);
	DISPLAY_Map(game, game->first_map);
	WAITER(game);
	EndMode2D();
	EndDrawing();
	while (!WindowShouldClose()) 
	{
		UPDATE_Map(game->first_map, game->second_map, game);
		while (game->paused)
			HANDLE_Pause_Input(game, game->second_map);
		UPDATE_Map(game->second_map, game->first_map, game);
		while (game->paused)
			HANDLE_Pause_Input(game, game->first_map);
	}
}


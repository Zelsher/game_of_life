#include "../inc/game_of_life.h"

void	DISPLAY_Map(t_game *game, char map[HEIGHT + 1][WIDTH + 1])
{
	int	y;
	int	x;
	int	y_win;
	int	x_win;

	y = 0;
	y_win = 0;
	while (y < HEIGHT)
	{
		x = 0;
		x_win = 0;
		while (x < WIDTH)
		{
			if (map[y][x] == '1')
				DrawRectangle(x_win, y_win, PIXEL, PIXEL, GRAY);
			else
				DrawRectangle(x_win, y_win, PIXEL, PIXEL, BLACK);
			x++;
			x_win += PIXEL;
		}
		y++;
		y_win += PIXEL;
	}
	(void)game;
}

int	COUNT_Neighbors(char map[HEIGHT + 1][WIDTH + 1], int y, int x)
{
	int	count;

	count = 0;
	if (y - 1 >= 0 && x - 1 >= 0 && (map[y - 1][x - 1] == '1'))
		count++;
	if (x - 1 >= 0 && (map[y][x - 1] == '1'))
		count++;
	if (y - 1 >= 0 && (map[y - 1][x] == '1'))
		count++;
	if (y + 1 < HEIGHT && x - 1 >= 0 && (map[y + 1][x - 1] == '1'))
		count++;
	if (y - 1 >= 0 && x + 1 < WIDTH && (map[y - 1][x + 1] == '1'))
		count++;
	if (y + 1 < HEIGHT && (map[y + 1][x] == '1'))
		count++;
	if (x + 1 < WIDTH && (map[y][x + 1] == '1'))
		count++;
	if (y + 1 < HEIGHT && x + 1 < WIDTH && (map[y + 1][x + 1] == '1'))
		count++;
	return (count);
}

void	UPDATE_Cube(char p_map[HEIGHT + 1][WIDTH + 1], char n_map[HEIGHT + 1][WIDTH + 1], int y, int x)
{
	int	neighbors;

	neighbors = COUNT_Neighbors(p_map, y, x);
	if (neighbors < 2 || (neighbors >= 4 && p_map[y][x] == '1'))
		n_map[y][x] = '0';
	else if (neighbors >  2)
		n_map[y][x] = '1';
	else
		n_map[y][x] = p_map[y][x];
}
void UPDATE_Map(char p_map[HEIGHT + 1][WIDTH + 1], char n_map[HEIGHT + 1][WIDTH + 1], t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->alive = 0;
	game->generation++;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			UPDATE_Cube(p_map, n_map, y, x);
			if (n_map[y][x] == '1')
				game->alive++;
			x++;
		}
		y++;
	}
	printf("Generation %d, %d alive. (speed=%ld)\n", game->generation, game->alive, game->wait_time);
	if (game->alive == WIDTH * HEIGHT)
		FREEER(game);
	BeginDrawing();
	BeginMode2D(game->camera);
	DISPLAY_Map(game, n_map);
	WAITER(game);
	EndMode2D();
	EndDrawing();
}

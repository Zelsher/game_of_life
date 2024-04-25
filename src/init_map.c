#include "../inc/game_of_life.h"

void	INIT_Map(char map[HEIGHT + 1][WIDTH + 1], int probability)
{
	int	random;
	int	y;
	int	x;

	srand(time(NULL));
	y = 0;
	printf("probability %d\n", probability);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			random = rand() % 101;
			if (random < probability)
				map[y][x] = '1';
			else
				map[y][x] = '0';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
}

void	INIT_Empty_Map(char map[HEIGHT + 1][WIDTH + 1])
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			map[y][x] = '0';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
}

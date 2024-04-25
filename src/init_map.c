#include "../inc/game_of_life.h"


void	MAP_Print(char map[HEIGHT + 1][WIDTH + 1])
{
	int	y;
	int	x;

	y = 0;
	printf("\n_______________________________________________________________________\n");
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("_______________________________________________________________________\n");
}

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
			random = rand() % 101;//ft_random(seed, 100, 0);
			//random = RANDOM(101, 0);
			if (random < probability)
				map[y][x] = '1';
			else
				map[y][x] = '0';
			//printf("%d", map[y][x]);
			x++;
		}
		//printf("\n");
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

#include "../inc/game_of_life.h"

void PUT_Glider(t_game *game, char map[HEIGHT + 1][WIDTH + 1])
{
	map[game->data.mouseY][game->data.mouseX] = '1';
	
	if (game->data.mouseY - 1 >= 0 && game->data.mouseX + 1 <= WIDTH * PIXEL)
		map[game->data.mouseY - 1][game->data.mouseX + 1] = '1';

	if (game->data.mouseY - 1 >= 0 && game->data.mouseX + 2 <= WIDTH * PIXEL)
		map[game->data.mouseY - 1][game->data.mouseX + 2] = '1';

	if (game->data.mouseX + 2 <= WIDTH * PIXEL)
		map[game->data.mouseY][game->data.mouseX + 2] = '1';

	if (game->data.mouseY + 1 <= HEIGHT * PIXEL && game->data.mouseX + 2 <= WIDTH * PIXEL)
		map[game->data.mouseY + 1][game->data.mouseX + 2] = '1';
}

void PUT_Spaceship(t_game *game, char map[HEIGHT + 1][WIDTH + 1])
{
	map[game->data.mouseY][game->data.mouseX] = '1';
	if (game->data.mouseY + 2 >= 0)
		map[game->data.mouseY + 2][game->data.mouseX] = '1';

	if (game->data.mouseY + 3 <= HEIGHT * PIXEL && game->data.mouseX + 1 <= WIDTH * PIXEL)
		map[game->data.mouseY + 3][game->data.mouseX + 1] = '1';

	if (game->data.mouseY + 3 <= HEIGHT * PIXEL && game->data.mouseX + 2 <= WIDTH * PIXEL)
		map[game->data.mouseY + 3][game->data.mouseX + 2] = '1';

	if (game->data.mouseY + 3 <= HEIGHT * PIXEL && game->data.mouseX + 3 <= WIDTH * PIXEL)
		map[game->data.mouseY + 3][game->data.mouseX + 3] = '1';

	if (game->data.mouseY + 3 <= HEIGHT * PIXEL && game->data.mouseX + 4 <= WIDTH * PIXEL)
		map[game->data.mouseY + 3][game->data.mouseX + 4] = '1';

	if (game->data.mouseY + 2 <= HEIGHT * PIXEL && game->data.mouseX + 4 <= WIDTH * PIXEL)
		map[game->data.mouseY + 2][game->data.mouseX + 4] = '1';

	if (game->data.mouseY + 1 <= HEIGHT * PIXEL && game->data.mouseX + 4 <= WIDTH * PIXEL)
		map[game->data.mouseY + 1][game->data.mouseX + 4] = '1';

	if (game->data.mouseX + 3 <= WIDTH * PIXEL)
		map[game->data.mouseY][game->data.mouseX + 3] = '1';
}

#include "../inc/game_of_life.h"

void	CAMERA_Zoom(t_game *game)
{
	float zoomSpeed = 0.05f;
	game->data.zoom = GetMouseWheelMove();
	if (game->data.zoom < 0)
	{
		game->data.mapWidth = WIDTH * PIXEL / game->camera.zoom;
		game->data.mapHeight = HEIGHT * PIXEL / game->camera.zoom;
		game->data.cameraHalfWidth = GetScreenWidth() / (2 * game->camera.zoom);
		game->data.cameraHalfHeight = GetScreenHeight() / (2 * game->camera.zoom);
		game->data.maxCameraX = game->data.mapWidth - game->data.cameraHalfWidth;
		game->data.maxCameraY = game->data.mapHeight - game->data.cameraHalfHeight;
		if (game->camera.target.x < game->data.cameraHalfWidth)
			game->camera.target.x = game->data.cameraHalfWidth;
		else if (game->camera.target.x > game->data.maxCameraX)
			game->camera.target.x = game->data.maxCameraX;
		if (game->camera.target.y < game->data.cameraHalfHeight)
			game->camera.target.y = game->data.cameraHalfHeight;
		else if (game->camera.target.y > game->data.maxCameraY)
			game->camera.target.y = game->data.maxCameraY;
		game->camera.target.x += (game->data.prevMousePos.x - GetScreenWidth() / 2) / game->camera.zoom;
		game->camera.target.y += (game->data.prevMousePos.y - GetScreenHeight() / 2) / game->camera.zoom;
	}
	if (game->data.zoom > 0 || game->camera.zoom > 1.0f)
		game->camera.zoom += game->data.zoom * zoomSpeed;
}

void CAMERA_Moove(t_game *game)
{
	game->data.mouseWheelMove = GetMouseWheelMove();
	if (game->data.mouseWheelMove != 0)
		CAMERA_Zoom(game);
	if (IsMouseButtonDown(MOUSE_MIDDLE_BUTTON))
	{
		if (game->data.prevMousePos.x == 0 && game->data.prevMousePos.y == 0)
			game->data.prevMousePos = GetMousePosition();
		else
		{
			Vector2 currentMousePos = GetMousePosition();
			game->data.deltaX = (currentMousePos.x - game->data.prevMousePos.x) / game->camera.zoom;
			game->data.deltaY = (currentMousePos.y - game->data.prevMousePos.y) / game->camera.zoom;
            if (game->camera.target.x - game->data.deltaX >= 0 && game->camera.target.x - game->data.deltaX + GetScreenWidth() / game->camera.zoom <= WIDTH * PIXEL &&
                game->camera.target.y - game->data.deltaY >= 0 && game->camera.target.y - game->data.deltaY + GetScreenHeight() / game->camera.zoom <= HEIGHT * PIXEL)
            {
                game->camera.target.x -= game->data.deltaX;
                game->camera.target.y -= game->data.deltaY;
            }
            game->data.prevMousePos = currentMousePos;
        }
    }
    else
        game->data.prevMousePos = (Vector2){0};
}

void HANDLE_Mouse_Input(t_game *game, char map[HEIGHT + 1][WIDTH + 1])
{
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) || IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
    {
        game->data.mousePos = GetMousePosition();
        game->data.mouseX = (int)((((game->data.mousePos.x - game->camera.offset.x) / game->camera.zoom) + game->camera.target.x) / PIXEL);
        game->data.mouseY = (int)((((game->data.mousePos.y - game->camera.offset.y) / game->camera.zoom) + game->camera.target.y) / PIXEL);
        if (game->data.mouseX >= 0 && game->data.mouseX < WIDTH && game->data.mouseY >= 0 && game->data.mouseY < HEIGHT)
        {
			if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
                map[game->data.mouseY][game->data.mouseX] = '0';
            else if (game->mod == 0 && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                map[game->data.mouseY][game->data.mouseX] = '1';
			if (game->mod == 1 && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				PUT_Glider(game, map);
			else if (game->mod == 2 && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
				PUT_Spaceship(game, map);
        }
    }
}

void	HANDLE_Input(t_game *game)
{
	CAMERA_Moove(game);
	if (IsKeyDown(KEY_DOWN) && game->wait_time < MAX_WAIT_TIME)
		game->wait_time += 1000;
	else if (IsKeyDown(KEY_UP) && game->wait_time > MIN_WAIT_TIME)
		game->wait_time -= 1000;
	if (IsKeyDown(KEY_ONE) && game->wait_time < MAX_WAIT_TIME)
		game->mod = 0;
	if (IsKeyDown(KEY_TWO) && game->wait_time < MAX_WAIT_TIME)
		game->mod = 1;
	if (IsKeyDown(KEY_THREE) && game->wait_time < MAX_WAIT_TIME)
		game->mod = 2;
	if (IsKeyReleased(KEY_SPACE) || IsKeyDown(KEY_SPACE))
		game->paused = 1;
	if (IsKeyReleased(KEY_ESCAPE) || IsKeyDown(KEY_ESCAPE))
		CLOSER(0);
}

void	HANDLE_Pause_Input(t_game *game, char map[HEIGHT + 1][WIDTH + 1])
{
	HANDLE_Mouse_Input(game, map);
	if (IsKeyUp(KEY_SPACE))
		game->paused = 0;
	if (IsKeyReleased(KEY_ESCAPE))
		exit(0);
	BeginDrawing();
	BeginMode2D(game->camera);
	DISPLAY_Map(game, map);
	HANDLE_Input(game);
	EndMode2D();
	EndDrawing();
}

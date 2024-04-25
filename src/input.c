#include "../inc/game_of_life.h"

void CAMERA_Moove(t_game *game)
{
	game->mouseWheelMove = GetMouseWheelMove();
	if (game->mouseWheelMove != 0)
    {
        float zoomSpeed = 0.05f;
		game->zoom = GetMouseWheelMove();
		if (game->zoom > 0 || game->camera.zoom > 1.0f)
        	game->camera.zoom += game->zoom * zoomSpeed;
		printf("Zoom %f\nTotal Zoom %f\n", game->zoom, game->camera.zoom);
    }

	if (game->mouseWheelMove != 0 && game->camera.zoom < 1.0f)
    {
		
        game->camera.zoom += GetMouseWheelMove() * 0.05f;
    }
	if (IsMouseButtonDown(MOUSE_MIDDLE_BUTTON))
        {
            if (game->prevMousePos.x == 0 && game->prevMousePos.y == 0)
            {
                game->prevMousePos = GetMousePosition(); // Enregistrer la position initiale de la souris
            }
            else
            {
                Vector2 currentMousePos = GetMousePosition();
				if (currentMousePos.y )
				{
                	game->camera.target.x -= (currentMousePos.x - game->prevMousePos.x) / game->camera.zoom;
                	game->camera.target.y -= (currentMousePos.y - game->prevMousePos.y) / game->camera.zoom;
                	game->prevMousePos = currentMousePos; // Mettre à jour la position précédente de la souris
				}
			}
        }
        else
        {
            game->prevMousePos = (Vector2){0}; // Réinitialiser la position précédente de la souris


		}
}

void	HANDLE_Mouse_Input(t_game *game)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		game->mousePos = GetMousePosition();
		game->mouseX = ((int)game->mousePos.x + (int)game->camera.offset.x) / game->camera.zoom;
		game->mouseY = ((int)game->mousePos.y + (int)game->camera.offset.y) / game->camera.zoom;
		printf("Mouse pixel : %dX%d\nMouse map : %dX%d\n", (int)game->mouseY, game->mouseX,
			game->mouseY / PIXEL, game->mouseX / PIXEL);
		printf("camera offset : %dX%d\n", (int)game->camera.offset.y, (int)game->camera.offset.x);
		game->first_map[game->mouseY / PIXEL][game->mouseX / PIXEL] = '1';
	}
	else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{

		game->mousePos = GetMousePosition();
		game->mouseX = ((int)game->mousePos.x + (int)game->camera.offset.x) / game->camera.zoom;
		game->mouseY = ((int)game->mousePos.y + (int)game->camera.offset.y) / game->camera.zoom;
		printf("Mouse pixel : %dX%d\nMouse map : %dX%d", (int)game->mouseY, game->mouseX,
			game->mouseY / PIXEL, game->mouseX / PIXEL);
		game->first_map[game->mouseY / PIXEL][game->mouseX / PIXEL] = '0';
	}
}

void	HANDLE_Input(t_game *game)
{
	HANDLE_Mouse_Input(game);
	if (IsKeyPressed(KEY_DOWN) && game->wait_time < MAX_WAIT_TIME)
		game->wait_time *= 10;
	else if (IsKeyPressed(KEY_UP) && game->wait_time > MIN_WAIT_TIME)
		game->wait_time /= 10;
	if (IsKeyReleased(KEY_SPACE) || IsKeyDown(KEY_SPACE))
		game->paused = 1;
	if (IsKeyReleased(KEY_ESCAPE))
		exit(0);
}

void	HANDLE_Pause_Input(t_game *game)
{
	HANDLE_Mouse_Input(game);
	if (IsKeyPressed(KEY_DOWN) && game->wait_time < MAX_WAIT_TIME)
		game->wait_time *= 10;
	else if (IsKeyPressed(KEY_UP) && game->wait_time > MIN_WAIT_TIME)
		game->wait_time /= 10;
	if (IsKeyReleased(KEY_SPACE))
		game->paused = 0;
	if (IsKeyReleased(KEY_ESCAPE))
		exit(0);
	BeginDrawing();
	BeginMode2D(game->camera);
	//ClearBackground(BLACK);
	DISPLAY_Map(game, game->first_map);
	CAMERA_Moove(game);
	EndMode2D();
	EndDrawing();
}

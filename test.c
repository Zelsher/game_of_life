#include "raylib.h"
#include <stdlib.h>

typedef struct {
    Camera2D camera;
    // Autres membres de la structure Game
} Game;

// Fonction d'initialisation de la caméra
void initCamera(Game *game, int screenWidth, int screenHeight) {
    game->camera.target = (Vector2){ 0 };
    game->camera.offset = (Vector2){ screenWidth / 2, screenHeight / 2 };
    game->camera.rotation = 0.0f;
    game->camera.zoom = 1.0f;
}
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    Game *game = malloc(sizeof(Game));

    InitWindow(screenWidth, screenHeight, "Exemple de zoom et de déplacement avec Raylib");

    // Initialisation de la caméra
    initCamera(game, screenWidth, screenHeight);


    Vector2 prevMousePos = {0}; // Position précédente de la souris

    while (!WindowShouldClose())
    {
        // Vérifier si la molette de la souris a été déplacée
        int mouseWheelMove = GetMouseWheelMove();
        if (mouseWheelMove != 0)
        {
            // Zoom avec la molette de la souris
            float zoomSpeed = 0.05f;
            game->camera.zoom += mouseWheelMove * zoomSpeed;
        }

        // Déplacement de la "caméra" avec le clic de la souris
        if (IsMouseButtonDown(MOUSE_MIDDLE_BUTTON))
        {
            if (prevMousePos.x == 0 && prevMousePos.y == 0)
            {
                prevMousePos = GetMousePosition(); // Enregistrer la position initiale de la souris
            }
            else
            {
                Vector2 currentMousePos = GetMousePosition();
                game->camera.target.x -= (currentMousePos.x - prevMousePos.x) / game->camera.zoom;
                game->camera.target.y -= (currentMousePos.y - prevMousePos.y) / game->camera.zoom;
                prevMousePos = currentMousePos; // Mettre à jour la position précédente de la souris
            }
        }
        else
        {
            prevMousePos = (Vector2){0}; // Réinitialiser la position précédente de la souris
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(game->camera);

        // Dessinez vos objets ici
        DrawCircle(50, 50, 50, BLACK);

        EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    free(game);

    return 0;
}

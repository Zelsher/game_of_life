#ifndef GAME_OF_LIFE
# define GAME_OF_LIFE

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "raylib.h"


# ifndef WIDTH
#  define WIDTH 480
# endif

# ifndef HEIGHT
#  define HEIGHT 270
# endif

# ifndef PIXEL
#  define PIXEL 4
# endif

# ifndef COLOR_DCELL
#  define COLOR_DCELL RED
# endif

# ifndef COLOR_ACELL
#  define COLOR_ACELL BLACK
# endif

# ifndef MAX_WAIT_TIME
#  define MAX_WAIT_TIME 500000
# endif

# ifndef MIN_WAIT_TIME
#  define MIN_WAIT_TIME 500
# endif

typedef struct	s_data
{
	float		zoom;
	float		mapWidth;
	float		mapHeight;
	float		cameraHalfWidth;
	float		cameraHalfHeight;
	float		maxCameraX;
	float		maxCameraY;
	float		deltaX;
	float		deltaY;
	float		mouseWheelMove;
	int 		mouseX;
	int 		mouseY;
	Vector2 	prevMousePos;
	Vector2 	mousePos;
}				t_data;

typedef struct s_game
{
	char		first_map[HEIGHT + 1][WIDTH + 1];
	char		second_map[HEIGHT + 1][WIDTH + 1];
	int			alive;
	int			generation;
	int			paused;
	size_t		wait_time;
	t_data		data;
	Camera2D 	camera;
}			t_game;

int		ft_atoi(const char *str);

void	HANDLE_Input(t_game *game);
void	HANDLE_Pause_Input(t_game *game, char map[HEIGHT + 1][WIDTH + 1]);

void	INIT_Map(char map[HEIGHT + 1][WIDTH + 1], int probability);
void	INIT_Empty_Map(char map[HEIGHT + 1][WIDTH + 1]);

void 	UPDATE_Map(char p_map[HEIGHT + 1][WIDTH + 1], char n_map[HEIGHT + 1][WIDTH + 1], t_game *game);
void	DISPLAY_Map(t_game *game, char map[HEIGHT + 1][WIDTH + 1]);

void	FREEER(t_game *game);
void	WAITER(t_game *game);
void	GAME_Of_Life(t_game *game);

#endif
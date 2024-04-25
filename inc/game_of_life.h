#ifndef GAME_OF_LIFE
# define GAME_OF_LIFE

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "raylib.h"


# ifndef WIDTH
#  define WIDTH 42
# endif

# ifndef HEIGHT
#  define HEIGHT 21
# endif

# ifndef MAX_WAIT_TIME
#  define MAX_WAIT_TIME 500000
# endif

# ifndef MIN_WAIT_TIME
#  define MIN_WAIT_TIME 500
# endif

# ifndef PIXEL
#  define PIXEL 50
# endif

typedef struct s_game
{
	char		first_map[HEIGHT + 1][WIDTH + 1];
	char		second_map[HEIGHT + 1][WIDTH + 1];
	int			alive;
	int			generation;
	int			paused;
	size_t		wait_time;
	int 		mouseX;
	int 		mouseY;
	Vector2 	prevMousePos;
	Vector2 	mousePos;
	float		zoom;
	float 		mouseWheelMove;
	Camera2D 	camera;
}			t_game;

int	ft_atoi(const char *str);

void	HANDLE_Mouse_Input(t_game *game);
void	HANDLE_Input(t_game *game);
void	HANDLE_Pause_Input(t_game *game);

void	INIT_Map(char map[HEIGHT + 1][WIDTH + 1], int probability);
void	INIT_Empty_Map(char map[HEIGHT + 1][WIDTH + 1]);
void	PRINT_Map(char map[HEIGHT + 1][WIDTH + 1]);
void 	UPDATE_Map(char p_map[HEIGHT + 1][WIDTH + 1], char n_map[HEIGHT + 1][WIDTH + 1], t_game *game);
void	DISPLAY_Map(t_game *game, char map[HEIGHT + 1][WIDTH + 1]);
void	MAP_Print(char map[HEIGHT + 1][WIDTH + 1]);
void	WAITER(t_game *game);

void	GAME_Of_Life(t_game *game);

void	FREEER(t_game *game);

#endif
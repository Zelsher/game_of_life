NAME		= game_of_life

INC			= inc/
SRC_DIR		= src/
OBJ_DIR		= obj/
RAYLIB_LIB	= -lraylib
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC)

RM			= rm -f

SRC			= $(SRC_DIR)main.c \
			  $(SRC_DIR)game_of_life.c \
			  $(SRC_DIR)update_map.c \
			  $(SRC_DIR)utils.c \
			  $(SRC_DIR)input.c \
			  $(SRC_DIR)mod.c \
			  $(SRC_DIR)init_map.c

OBJ 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(RAYLIB_LIB) $(CFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re

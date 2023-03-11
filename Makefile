NAME = minirt
PATH_SRCS = ./sources/
PATH_MLX_SRCS = ./sources/mlx/
PATH_OBJS = ./objects/

SRCS = main.c
MLX_SRCS = mlx_open_window.c \
		   mlx_loop_window.c \
		   mlx_close_window.c \
		   mlx_key_press_events.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}
MLX_OBJS = ${MLX_SRCS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./includes/
FLAGS = -Wall -Wextra -Werror -g3
LINKERS = -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX_OBJS)
	@cc $(FLAGS) $(OBJS) $(MLX_OBJS) $(LINKERS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_MLX_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean all
	
.PHONY: all clean fclean re

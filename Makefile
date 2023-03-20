NAME = minirt

PATH_SRCS = ./sources/
PATH_MLX_SRCS = ./sources/mlx/
PATH_OBJS = ./objects/

SRCS = main.c
MLX_SRCS = mlx_open_window.c \
		   mlx_loop_window.c \
		   mlx_close_window.c \
		   mlx_click_press_events.c \
		   mlx_pixel_draw.c \
		   mlx_key_press_events.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}
MLX_OBJS = ${MLX_SRCS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./includes/
FLAGS = -Wall -Wextra -Werror -g3 -fPIE
LINKERS = -lmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLX_OBJS) 
	@cc $(FLAGS) $(OBJS) $(MLX_OBJS) $(LINKERS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make --no-print-directory -C libft
	@echo "\033[1;92m[SUCCESS] LIBFT created!\033[0m"

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
	@make --no-print-directory -C libft clean
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C libft fclean
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean all
	
.PHONY: all clean fclean re

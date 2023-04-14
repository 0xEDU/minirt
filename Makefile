NAME = minirt

PATH_SRCS = ./sources/
PATH_MLX_SRCS = ./sources/mlx/
PATH_COLORS = ./sources/colors/
PATH_VECTORS = ./sources/vectors/
PATH_RAYS = ./sources/rays/
PATH_HITTABLE = ./sources/hittable/
PATH_PARSER = ./sources/parser/
PATH_OBJS = ./objects/

SRCS =	main.c \
		init_minirt.c \
		hit_sphere.c \
		hit_plane.c \
		hit_cylinder.c \
		hit_cone.c \
		create_world.c \
		render_scene.c \
		lighting.c
MLX_SRCS = mlx_open_window.c \
		   mlx_loop_window.c \
		   mlx_close_window.c \
		   mlx_click_press_events.c \
		   mlx_pixel_draw.c \
		   mlx_create_image.c \
		   mlx_image_to_window.c \
		   mlx_key_press_events.c
COLORS_SRCS =	color_create_rgb.c
VECTORS_SRCS =  vector_add.c \
				vector_div_self.c \
				vector_div.c \
				vector_dot.c \
				vector_mult_self.c \
				vector_mult.c \
				vector_negate_self.c \
				vector_sum_self.c \
				vector_sum.c \
				vector_subtr.c \
				vector_diff.c \
				vector_length.c \
				vector_length_squared.c \
				vector_unit.c \
				vector_create.c \
				vector_reflect.c \
				vector_product.c \
				vector_cross.c
RAYS_SRCS =	ray_at.c \
			ray_color.c
HITTABLE_SRCS =	set_face_normal.c \
				hittable_list_add.c \
				hittable_list_clear.c \
				hittable_list_hit.c
PARSER_SRCS =	parse_ambient.c \
				parse_camera.c \
				parse_light.c \
				parse_utils.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}
MLX_OBJS = ${MLX_SRCS:%.c=$(PATH_OBJS)%.o}
COLORS_OBJS = ${COLORS_SRCS:%.c=$(PATH_OBJS)%.o}
VECTORS_OBJS = ${VECTORS_SRCS:%.c=$(PATH_OBJS)%.o}
RAYS_OBJS = ${RAYS_SRCS:%.c=$(PATH_OBJS)%.o}
HITTABLE_OBJS = ${HITTABLE_SRCS:%.c=$(PATH_OBJS)%.o}
PARSER_OBJS = ${PARSER_SRCS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./includes/
FLAGS = -Wall -Wextra -Werror -g3
LINKERS = -lmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLX_OBJS) $(COLORS_OBJS) $(VECTORS_OBJS) $(RAYS_OBJS) $(HITTABLE_OBJS) $(PARSER_OBJS)
	@cc $(FLAGS) $(OBJS) $(MLX_OBJS) $(COLORS_OBJS) $(VECTORS_OBJS) $(RAYS_OBJS) $(HITTABLE_OBJS) $(PARSER_OBJS) $(LINKERS) $(LIBFT) -o $(NAME)

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

$(PATH_OBJS)%.o: $(PATH_COLORS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_VECTORS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_RAYS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_HITTABLE)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_PARSER)%.c
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

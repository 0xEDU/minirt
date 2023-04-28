NAME = minirt
BONUS = minirt_bonus

PATH_SRCS = ./sources/
PATH_MLX_SRCS = ./sources/mlx/
PATH_COLORS = ./sources/colors/
PATH_VECTORS = ./sources/vectors/
PATH_RAYS = ./sources/rays/
PATH_HITTABLE = ./sources/hittable/
PATH_PARSER = ./sources/parser/
PATH_VALIDATOR = ./sources/validator/
PATH_OBJS = ./objects/
PATH_SRCS_BONUS = ./sources_bonus/
PATH_MLX_SRCS_BONUS = ./sources_bonus/mlx/
PATH_COLORS_BONUS = ./sources_bonus/colors/
PATH_VECTORS_BONUS = ./sources_bonus/vectors/
PATH_RAYS_BONUS = ./sources_bonus/rays/
PATH_HITTABLE_BONUS = ./sources_bonus/hittable/
PATH_PARSER_BONUS = ./sources_bonus/parser/
PATH_VALIDATOR_BONUS = ./sources_bonus/validator/
PATH_OBJS_BONUS = ./objects_bonus/

SRCS =	main.c \
		init_minirt.c \
		hit_sphere.c \
		hit_plane.c \
		hit_cylinder.c \
		hit_cylinder_utils.c \
		hit_cylinder_utils2.c \
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
				vector_project_onto_plane.c \
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
				parse_sphere.c \
				parse_plane.c \
				parse_cylinder.c \
				parse_utils.c

VALIDATOR_SRCS =	validate_argv.c \
					validate_file.c \
					validate_line.c \
					validate_camera.c \
					validate_ambient.c \
					validate_light.c \
					validate_sphere.c \
					validate_plane.c \
					validate_cylinder.c \
					validate_utils.c \
					validate_utils2.c 

SRCS_BONUS =	main_bonus.c \
		init_minirt_bonus.c \
		hit_sphere_bonus.c \
		hit_plane_bonus.c \
		hit_cylinder_bonus.c \
		hit_cylinder_utils_bonus.c \
		hit_cylinder_utils2_bonus.c \
		hit_cone_bonus.c \
		hit_cone_utils_bonus.c \
		create_world_bonus.c \
		render_scene_bonus.c \
		lighting_bonus.c
MLX_SRCS_BONUS = mlx_open_window.c \
		   mlx_loop_window.c \
		   mlx_close_window.c \
		   mlx_click_press_events.c \
		   mlx_pixel_draw.c \
		   mlx_create_image.c \
		   mlx_image_to_window.c \
		   mlx_key_press_events.c
COLORS_SRCS_BONUS =	color_create_rgb_bonus.c
VECTORS_SRCS_BONUS =  vector_add_bonus.c \
				vector_div_self_bonus.c \
				vector_div_bonus.c \
				vector_dot_bonus.c \
				vector_mult_self_bonus.c \
				vector_mult_bonus.c \
				vector_negate_self_bonus.c \
				vector_sum_self_bonus.c \
				vector_sum_bonus.c \
				vector_subtr_bonus.c \
				vector_diff_bonus.c \
				vector_length_bonus.c \
				vector_length_squared_bonus.c \
				vector_unit_bonus.c \
				vector_create_bonus.c \
				vector_reflect_bonus.c \
				vector_product_bonus.c \
				vector_project_onto_plane_bonus.c \
				vector_cross_bonus.c
RAYS_SRCS_BONUS =	ray_at_bonus.c \
			ray_color_bonus.c
HITTABLE_SRCS_BONUS =	set_face_normal_bonus.c \
				hittable_list_add_bonus.c \
				hittable_list_clear_bonus.c \
				hittable_list_hit_bonus.c
PARSER_SRCS_BONUS =	parse_ambient_bonus.c \
				parse_camera_bonus.c \
				parse_light_bonus.c \
				parse_sphere_bonus.c \
				parse_plane_bonus.c \
				parse_cylinder_bonus.c \
				parse_cone_bonus.c \
				parse_utils_bonus.c

VALIDATOR_SRCS_BONUS =	validate_argv_bonus.c \
					validate_file_bonus.c \
					validate_line_bonus.c \
					validate_camera_bonus.c \
					validate_ambient_bonus.c \
					validate_light_bonus.c \
					validate_sphere_bonus.c \
					validate_plane_bonus.c \
					validate_cylinder_bonus.c \
					validate_utils_bonus.c \
					validate_cone_bonus.c \
					validate_utils2_bonus.c 

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}
MLX_OBJS = ${MLX_SRCS:%.c=$(PATH_OBJS)%.o}
COLORS_OBJS = ${COLORS_SRCS:%.c=$(PATH_OBJS)%.o}
VECTORS_OBJS = ${VECTORS_SRCS:%.c=$(PATH_OBJS)%.o}
RAYS_OBJS = ${RAYS_SRCS:%.c=$(PATH_OBJS)%.o}
HITTABLE_OBJS = ${HITTABLE_SRCS:%.c=$(PATH_OBJS)%.o}
PARSER_OBJS = ${PARSER_SRCS:%.c=$(PATH_OBJS)%.o}
VALIDATOR_OBJS = ${VALIDATOR_SRCS:%.c=$(PATH_OBJS)%.o}

OBJS_BONUS = ${SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o}
MLX_OBJS_BONUS = ${MLX_SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o}
COLORS_OBJS_BONUS = ${COLORS_SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o}
VECTORS_OBJS_BONUS = ${VECTORS_SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o}
RAYS_OBJS_BONUS = ${RAYS_SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o}
HITTABLE_OBJS_BONUS = ${HITTABLE_SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o}
PARSER_OBJS_BONUS = ${PARSER_SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o}
VALIDATOR_OBJS_BONUS = ${VALIDATOR_SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o}

INCLUDE = -I ./includes/
FLAGS = -Wall -Wextra -Werror -g3
LINKERS = -lmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MLX_OBJS) $(COLORS_OBJS) $(VECTORS_OBJS) $(RAYS_OBJS) $(HITTABLE_OBJS) $(PARSER_OBJS) $(VALIDATOR_OBJS)
	@cc $(FLAGS) $(OBJS) $(MLX_OBJS) $(COLORS_OBJS) $(VECTORS_OBJS) $(RAYS_OBJS) $(HITTABLE_OBJS) $(PARSER_OBJS) $(VALIDATOR_OBJS) $(LINKERS) $(LIBFT) -o $(NAME)

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

$(PATH_OBJS)%.o: $(PATH_VALIDATOR)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

bonus: $(BONUS)
$(BONUS): $(LIBFT) $(OBJS_BONUS) $(MLX_OBJS_BONUS) $(COLORS_OBJS_BONUS) $(VECTORS_OBJS_BONUS) $(RAYS_OBJS_BONUS) $(HITTABLE_OBJS_BONUS) $(PARSER_OBJS_BONUS) $(VALIDATOR_OBJS_BONUS)
	@cc $(FLAGS) $(OBJS_BONUS) $(MLX_OBJS_BONUS) $(COLORS_OBJS_BONUS) $(VECTORS_OBJS_BONUS) $(RAYS_OBJS_BONUS) $(HITTABLE_OBJS_BONUS) $(PARSER_OBJS_BONUS) $(VALIDATOR_OBJS_BONUS) $(LINKERS) $(LIBFT) -o $(BONUS)

$(PATH_OBJS_BONUS)%.o: $(PATH_SRCS_BONUS)%.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS_BONUS)%.o: $(PATH_MLX_SRCS_BONUS)%.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS_BONUS)%.o: $(PATH_COLORS_BONUS)%.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS_BONUS)%.o: $(PATH_VECTORS_BONUS)%.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS_BONUS)%.o: $(PATH_RAYS_BONUS)%.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS_BONUS)%.o: $(PATH_HITTABLE_BONUS)%.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS_BONUS)%.o: $(PATH_PARSER_BONUS)%.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS_BONUS)%.o: $(PATH_VALIDATOR_BONUS)%.c
	@mkdir -p $(PATH_OBJS_BONUS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

clean:
	@rm -rf $(PATH_OBJS) $(PATH_OBJS_BONUS)
	@make --no-print-directory -C libft clean
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(BONUS) $(NAME)
	@make --no-print-directory -C libft fclean
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean all
	
.PHONY: all clean fclean re

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:59:16 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/22 21:18:43 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H
# define WIDTH 1920
# define HEIGHT 1080
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libput.h"
# include "vector.h"

typedef struct s_image {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_mlx {
	void	*mlx;
	void	*window;
}				t_mlx;

typedef struct s_camera {
	double		viewport_height;
	double		viewport_width;
	double		focal_length;
	t_vector	origin;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lower_left_corner;
}				t_camera;

typedef struct s_minirt {
	t_mlx		mlx;
	t_image		img;
	t_camera	camera;
}				t_minirt;

/* Initialization functions */
void	init_minirt(t_minirt *minirt);

/* Rendering functions */
void	render_scene(t_minirt *minirt);

/* MLX-related functions */
void	mlx_open_window(t_mlx *mlx);
void	mlx_loop_window(t_minirt *minirt);
void	mlx_close_window(t_minirt *minirt);
int		mlx_key_press_events(int key_code, t_minirt *minirt);
int		mlx_click_press_events(t_minirt *minirt);
void	mlx_pixel_draw(t_image *image, int x, int y, int color);
void	mlx_create_image(t_minirt *minirt);
void	mlx_image_to_window(t_minirt *minirt, int x, int y);

#endif

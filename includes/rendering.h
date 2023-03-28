/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:59:16 by guribeir          #+#    #+#             */
/*   Updated: 2023/03/28 13:53:10 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libput.h"
# include "vector.h"
# include "ray.h"
# define WIDTH 1920
# define HEIGHT 1080
# define SPHERE 1

typedef struct s_variation {
	double	min;
	double	max;	
}				t_variation;

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
	t_mlx			mlx;
	t_image			img;
	t_camera		camera;
}				t_minirt;

typedef struct s_hit_record {
	t_point3	point;
	t_vector	normal;
	double		t;
	int			front_face;
}				t_hit_record;

typedef struct s_sphere {
	t_point3	center;
	double		radius;
	int			type;
	int			(*hit)(struct s_sphere object, t_ray *ray,
			t_variation t, t_hit_record *rec);
}				t_sphere;

typedef union u_hittable {
	int			type;
	t_sphere	sphere;
}				t_hittable;

typedef struct s_hittable_node {
	t_sphere				*object;
	struct s_hittable_node	*next;
}				t_hittable_node;

typedef struct s_hittable_list {
	t_hittable_node	*head;
}				t_hittable_list;

/* Hittable list functions */
void		hittable_list_clear(t_hittable_list *list);
void		hittable_list_add(t_hittable_list *list, t_sphere *object);
int			hittable_list_hit(t_hittable_list *list, t_ray *ray,
			t_variation t, t_hit_record *rec);

/* Hit Record Utils */
void		create_world(t_hittable_list *world);
void		set_face_normal(t_hit_record *rec, t_ray *ray, t_vector *out_normal);

/* Light hitting functions */
int			hit_sphere(t_sphere sphere,
			t_ray *ray,
			t_variation t,
			t_hit_record *rec);
t_color		*ray_color(t_ray ray, t_hittable_list *world);

/* Initialization functions */
void		init_minirt(t_minirt *minirt);

/* Rendering functions */
void		render_scene(t_minirt *minirt, t_hittable_list *world);

/* MLX-related functions */
void		mlx_open_window(t_mlx *mlx);
void		mlx_loop_window(t_minirt *minirt);
void		mlx_close_window(t_minirt *minirt);
int			mlx_key_press_events(int key_code, t_minirt *minirt);
int			mlx_click_press_events(t_minirt *minirt);
void		mlx_pixel_draw(t_image *image, int x, int y, int color);
void		mlx_create_image(t_minirt *minirt);
void		mlx_image_to_window(t_minirt *minirt, int x, int y);

#endif

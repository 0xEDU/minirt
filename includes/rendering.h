/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:59:16 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/26 17:27:19 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libput.h"
# include "vector.h"
# include "ray.h"
# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.1415926535897932385
# define SPHERE 1
# define PLANE 2
# define PL 2
# define CYLINDER 3
# define CYL 3
# define CONE 4
# define AMBIENT 0
# define DIFFUSE 1
# define SPECULAR 2
# define RESULT 3

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
	double		fov;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lower_left_corner;
	t_vector	view_up;
	t_point3	lookfrom;
	t_point3	lookat;
}				t_camera;

typedef struct s_ambient {
	double		ratio;
	t_color		color;
}				t_ambient;

typedef struct s_hit_record {
	t_point3	point;
	t_vector	normal;
	double		t;
	int			front_face;
	int			index;
	int			ignore_index;
}				t_hit_record;

typedef struct s_material {
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}				t_material;

typedef struct s_sphere {
	t_point3	center;
	double		radius;
	int			type;
	t_material	m;
}				t_sphere;

typedef struct s_cylinder {
	t_vector	axis;
	t_vector	center;
	double		radius;
	double		height;
	t_vector	cap_top;
	t_vector	cap_bottom;
	int			type;
	t_material	m;
}				t_cylinder;

typedef struct s_cone {
	t_vector	vertex;
	t_vector	axis;
	double		height;
	double		angle;
	int			type;
	t_material	m;
}				t_cone;

typedef struct s_plane {
	t_vector	normal;
	t_vector	position;
	int			type;
	t_material	m;
}				t_plane;

typedef union u_hittable {
	int			type;
	t_sphere	sphere;
}				t_hittable;

typedef struct s_hittable_node {
	union
	{
		void				*object;
		t_sphere			*sphere;
		t_cylinder			*cylinder;
		t_cylinder			*cyl;
		t_plane				*plane;
		t_cone				*cone;	
	};
	int						type;
	int						index;
	struct s_hittable_node	*next;
}				t_hittable_node;

typedef struct s_hittable_list {
	t_hittable_node	*head;
}				t_hittable_list;

typedef struct s_minirt {
	t_mlx			mlx;
	t_image			img;
	t_camera		camera;
	t_ambient		ambient;
	t_light			light;
	t_hittable_list	*world;
}				t_minirt;

typedef struct s_hit {
	union
	{
		void				*object;
		t_sphere			*sphere;
		t_cylinder			*cyl;
		t_plane				*plane;
		t_cone				*cone;	
	};
	t_ray			*ray;
	t_variation		t;
	t_hit_record	*rec;
}				t_hit;

typedef struct s_bhaskara {
	double	a;
	double	b;
	double	c;
	double	discr;
	double	root[2];
}				t_bhaskara;

typedef struct s_lighting {
	t_material	m;
	t_light		light;
	t_point3	point;
	t_vector	eyev;
	t_vector	normal;
}				t_lighting;

/* Hittable list functions */
void			hittable_list_clear(t_hittable_list *list);
void			hittable_list_add(t_hittable_list *list, void *object,
					int index, int type);
int				hittable_list_hit(t_hittable_list *list, t_ray *ray,
					t_variation t, t_hit_record *rec);
int				hittable_shadow_hit(t_hittable_list *list, t_ray *ray,
					t_variation t, t_hit_record *rec);

/* Hit Record Utils */
// t_hittable_list	*create_world(char *file, t_minirt *minirt);
void			create_world(char *file, t_minirt *minirt,
					t_hittable_list *world, int i);
void			set_face_normal(t_hit_record *rec,
					t_ray *ray, t_vector *out_normal);

/* Light hitting functions */
int				hit_sphere(t_sphere sphere,
					t_ray *ray,
					t_variation t,
					t_hit_record *rec);
int				hit_plane(t_plane plane, t_ray *ray, t_variation t,
					t_hit_record *rec);
int				hit_cylinder(t_cylinder cyl, t_ray *ray,
					t_variation t, t_hit_record *rec);
int				hit_cone(t_cone cone, t_ray *ray,
					t_variation t, t_hit_record *rec);
t_color			ray_color(t_ray ray, t_hittable_list *world, t_light light);
t_vector		normalize(t_vector vector);

/* Initialization functions */
void			init_minirt(t_minirt *minirt);

/* Rendering functions */
void			render_scene(t_minirt *minirt, t_hittable_list *world);
t_color			lighting(t_material material, t_light light,
					t_hit *hit, int in_shadow);

/* Parsing functions utils */
t_color			parse_color(char *line);
t_vector		parse_vector(char *line);

/* Parsing functions */
void			parse_ambient(char *line, t_ambient *ambient);
void			parse_camera(char *line, t_camera *camera);
void			parse_light(char *line, t_light *light);
void			parse_sphere(char *line, t_hittable_list *world,
					t_minirt *minirt, int *i);
void			parse_plane(char *line, t_hittable_list *world,
					t_minirt *minirt, int *i);
void			parse_cylinder(char *line, t_hittable_list *world,
					t_minirt *minirt, int *i);
void			parse_cone(char *ln, t_hittable_list *lst,
					t_minirt *minirt, int *i);

/* Validating functions */
int				validate_argv(int argc, char **argv);
int				validate_file(char *file);
int				validate_line(char *line);
int				validate_camera(char *line);
int				validate_ambient(char *line);
int				validate_light(char *line);
int				validate_sphere(char *line);
int				validate_plane(char *line);
int				validate_cylinder(char *line);
int				validate_cone(char *line);

/* Validating utils */
int				validate_position(char *position);
int				validate_normal(char *normal);
int				validate_color(char *line);
int				validate_vector(char **vector);
int				validate_double(char *line);
int				clean_return(int status_code, void **split);
int				validate_ratio(char *line);
int				validate_float(char *line);

/* MLX-related functions */
void			mlx_open_window(t_mlx *mlx);
void			mlx_loop_window(t_minirt *minirt);
void			mlx_close_window(t_minirt *minirt);
int				mlx_key_press_events(int key_code, t_minirt *minirt);
int				mlx_click_press_events(t_minirt *minirt);
void			mlx_pixel_draw(t_image *image, int x, int y, int color);
void			mlx_create_image(t_minirt *minirt);
void			mlx_image_to_window(t_minirt *minirt, int x, int y);

#endif

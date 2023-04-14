/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:07:55 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/14 16:41:06 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	convert_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

// lower_left_corner + u*horizontal + v*vertical - origin
static t_ray	ray_constructor(t_camera *camera, t_vector normal)
{
	t_ray		new;

	new.origin = camera->lookfrom;
	normal.y = 1.0 - normal.y;
	new.direction = normalize(vector_diff(
			vector_sum(
				vector_sum(camera->lower_left_corner,
					vector_mult(camera->horizontal, normal.x)),
				vector_mult(camera->vertical, normal.y)),
			camera->lookfrom));
	return (new);
}

static void	turn_on_camera(t_camera *camera, double aspect_ratio)
{
	double		theta;
	double		h_cam;
	t_vector	w;
	t_vector	u;
	t_vector	v;

	theta = convert_to_radians(camera->fov);
	h_cam = tan(theta/2);
	// point3(-2,2,1), point3(0,0,-1), vec3(0,1,0)
	camera->view_up = vector_create(0, 1, 0);
	camera->viewport_height = 1.2 * h_cam;
	camera->viewport_width = aspect_ratio * camera->viewport_height;
	w = vector_unit(vector_diff(camera->lookfrom, camera->lookat));
	u = vector_unit(vector_cross(camera->view_up, w));
	v = vector_cross(w, u);
	camera->focal_length = 1.0;
	camera->horizontal = vector_mult(u, camera->viewport_width);
	camera->vertical = vector_mult(v, camera->viewport_height);
	camera->lower_left_corner = vector_diff(
			vector_diff(
				vector_diff(camera->lookfrom, vector_div(vector_negate_self(&camera->horizontal), 2)),
				vector_div(camera->vertical, 2)), w);
}

void	render_scene(t_minirt *minirt, t_hittable_list *world)
{
	t_vector	normal;
	t_vector	loop;
	t_ray		ray;
	t_color		color;
	t_light		point_light;

	turn_on_camera(&minirt->camera, (1.75));
	loop.x = 0;
	point_light = minirt->light;
	while (loop.x < WIDTH)
	{
		loop.y = 0;
		while (loop.y < HEIGHT)
		{
			normal.x = (double)loop.x / (WIDTH - 1);
			normal.y = (double)loop.y / (HEIGHT - 1);
			ray = ray_constructor(&minirt->camera, normal);
			color = ray_color(ray, world, point_light);
			mlx_pixel_draw(&minirt->img, loop.x, loop.y,
				color_create_rgb(&color));
			loop.y++;
		}
		loop.x++;
	}
}

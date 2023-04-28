/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:07:55 by guribeir          #+#    #+#             */
/*   Updated: 2023/04/28 16:32:25 by guribeir         ###   ########.fr       */
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
	new.direction = normalize(vector_diff(
				vector_sum(
					vector_sum(camera->lower_left_corner,
						vector_mult(camera->horizontal, normal.x)),
					vector_mult(camera->vertical, normal.y)),
				camera->lookfrom));
	return (new);
}

static int	vector_is_equal(t_vector v1, t_vector v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return (1);
	return (0);
}

static void	turn_on_camera(t_camera *camera, double aspect_ratio)
{
	double		theta;
	double		h_cam;
	t_vector	w;
	t_vector	u;
	t_vector	v;

	if (vector_is_equal(camera->lookat, vector_create(0, 1, 0)))
		camera->lookat.z += 0.0001;
	else if (vector_is_equal(camera->lookat, vector_create(0, -1, 0)))
		camera->lookat.z += 0.0001;
	theta = convert_to_radians(camera->fov);
	h_cam = tan(theta / 2);
	camera->view_up = vector_create(0, 1, 0);
	camera->viewport_height = 1.175 * h_cam;
	camera->viewport_width = aspect_ratio * camera->viewport_height;
	w = vector_unit(vector_negate_self(&camera->lookat));
	u = vector_unit(vector_cross(camera->view_up, w));
	v = vector_cross(u, w);
	camera->horizontal = vector_mult(u, camera->viewport_width);
	camera->vertical = vector_mult(v, camera->viewport_height);
	camera->lower_left_corner = vector_diff(
			vector_diff(
				vector_diff(camera->lookfrom,
					vector_div(vector_negate_self(&camera->horizontal), 2)),
				vector_div(camera->vertical, 2)), w);
}

void	render_scene(t_minirt *minirt, t_hittable_list *world)
{
	t_vector	normal;
	t_vector	loop;
	t_ray		ray;
	t_color		color;
	t_light		point_light;

	turn_on_camera(&minirt->camera, (1.77777777778));
	point_light = minirt->light;
	loop.x = 0;
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

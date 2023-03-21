/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:50:59 by edu               #+#    #+#             */
/*   Updated: 2023/03/20 21:09:14 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	1. Validate input.
*	2. Load .rt file in a t_raytracer struct (?)
*	3. Generate a scene using the struct...?
*	...
*/

static void draw_circle(t_minirt *minirt, int x_center, int y_center, int radius, int color)
{
    int x, y, d;

    for (y = -radius; y <= radius; y++)
    {
        for (x = -radius; x <= radius; x++)
        {
            d = x * x + y * y;
            if (d <= radius * radius)
            {
                // mlx_pixel_put(mlx, win, x_center + x, y_center + y, color);
				mlx_pixel_draw(&minirt->img, x_center + x, y_center + y, color);
            }
        }
    }
}

// TODO:
int	main(void)
{
	t_minirt	minirt;
	int x_center = WIDTH / 2;
    int y_center = HEIGHT / 2;
    int max_radius = 350;
    int num_circles = 1000;

	int			i;

	mlx_open_window(&minirt.mlx);
	mlx_create_image(&minirt);
	i = -1;
	while (++i < num_circles)
	{
		int radius = (int)(max_radius * (1 - pow((double)i / num_circles, 2)));
		int color = 0x0000FF * i / num_circles;
		draw_circle(&minirt, x_center, y_center, radius, color);
	}
	mlx_image_to_window(&minirt, 0, 0);
	mlx_loop_window(&minirt.mlx);
	return (0);
}


// #include <math.h>
// #include <stdbool.h>
// #include "mlx.h"

// #define WIDTH 800
// #define HEIGHT 600

// typedef struct {
//     double x, y, z;
// } Vec3;

// Vec3 vec3(double x, double y, double z) {
//     Vec3 v = {x, y, z};
//     return v;
// }

// Vec3 vec3_sub(Vec3 a, Vec3 b) {
//     return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
// }

// double vec3_dot(Vec3 a, Vec3 b) {
//     return a.x * b.x + a.y * b.y + a.z * b.z;
// }

// double vec3_length(Vec3 v) {
//     return sqrt(vec3_dot(v, v));
// }

// bool ray_sphere_intersect(Vec3 ray_origin, Vec3 ray_dir, Vec3 sphere_center, double sphere_radius) {
//     Vec3 oc = vec3_sub(ray_origin, sphere_center);
//     double a = vec3_dot(ray_dir, ray_dir);
//     double b = 2.0 * vec3_dot(oc, ray_dir);
//     double c = vec3_dot(oc, oc) - sphere_radius * sphere_radius;
//     double discriminant = b * b - 4 * a * c;
//     return discriminant > 0;
// }

// int main() {
//     void *mlx;
//     void *win;
//     mlx = mlx_init();
//     win = mlx_new_window(mlx, WIDTH, HEIGHT, "Ray Traced Sphere");

//     Vec3 sphere_center = vec3(WIDTH / 2.0, HEIGHT / 2.0, 50);
//     double sphere_radius = 50;
//     Vec3 camera_pos = vec3(WIDTH / 2.0, HEIGHT / 2.0, -100);
//     Vec3 screen_top_left = vec3(0, 0, 0);

//     for (int y = 0; y < HEIGHT; y++) {
//         for (int x = 0; x < WIDTH; x++) {
//             Vec3 screen_pos = vec3(x, y, 0);
//             Vec3 ray_dir = vec3_sub(screen_pos, camera_pos);
//             ray_dir = vec3(ray_dir.x / vec3_length(ray_dir), ray_dir.y / vec3_length(ray_dir), ray_dir.z / vec3_length(ray_dir));

//             if (ray_sphere_intersect(camera_pos, ray_dir, sphere_center, sphere_radius)) {
//                 mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
//             }
//         }
//     }

//     mlx_loop(mlx);
//     return 0;
// }
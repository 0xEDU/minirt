# MiniRT

MiniRT is a simple ray tracer built using minilibx that is capable of rendering planes, spheres, cylinders (mandatory part), and cones (bonus part) to generate a 2D image representing the 3D scene. 
The ray tracer features light management, including spot brightness, hard shadows, and ambiance lighting (objects are never completely in the dark). It implements ambient and diffuse lighting in the mandatory part, and ambient, diffuse, and specular lighting in the bonus part.

## Ray Tracing Technique

The ray tracing technique used in MiniRT consists of the following steps:

1. **Ray Construction**: For each pixel on the screen, a ray is constructed based on the camera's position, look direction, and the normal of the pixel.
2. **Intersection Tests**: The ray is tested for intersections with each object in the scene. The intersection tests are handled by specific functions for each geometric primitive, such as `hit_plane`, `hit_sphere`, `hit_cone`, and `hit_cylinder`.
3. **Color Calculation**: If the ray intersects an object, the color of the intersection point is calculated based on the object's material and the light sources in the scene. Shadows are also taken into account by checking if there are any objects blocking the light from reaching the intersection point.
4. **Rendering**: The color of the intersection point is used to set the color of the corresponding pixel in the final 2D image.
> The ray tracing technique used here is simple but effective for rendering scenes with basic geometric primitives and lighting.
## Features

- Render planes, spheres, cylinders, and cones
- Light management: spot brightness, hard shadows, and ambiance lighting
- Ambient and diffuse lighting (mandatory part)
- Ambient, diffuse, and specular lighting (bonus part)
- Resize objects by changing the `.rt` scene content
- Correctly handles all possible intersections and the inside of objects
- Built-in parser to ensure `.rt` files have no invalid entries

## Usage

To render a scene, provide a valid `.rt`. The ray tracer will resize objects based on its unique properties defined in the file.

#### Example usage:

```bash
make
```

After compile the project (make bonus for bonus part), you can run the executable using one scene as parameter.

```bash
./miniRT scenes/[scene_file.rt]
```

## Scene File Format

A valid scene file with the `.rt` extension must (at least) contain:

- A camera definition
- A light definition
- An ambient light definition

Additional objects and settings can be included in the scene file to customize the scene.

## Example Code

Here is a brief excerpt of the code:

```c
void	render_scene(t_minirt *minirt, t_hittable_list *world)
{
	t_vector	normal;
	t_vector	loop;
	t_ray		ray;
	t_color		color;
	t_light		point_light;

	turn_on_camera(&minirt->camera, (WIDTH / HEIGHT));
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
```

## Note

This is a basic implementation of a ray tracing renderer, and improvements can be made in various aspects, such as performance optimization, support for more complex materials and lighting models, and the addition of more geometric primitives.

> For a more in-depth look at the code, see the full implementation.

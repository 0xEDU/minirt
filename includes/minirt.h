/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:27 by edu               #+#    #+#             */
/*   Updated: 2023/03/21 16:58:21 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WIDTH 1920
# define HEIGHT 1080
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libput.h"

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

typedef struct s_minirt {
	t_mlx	mlx;
	t_image	img;
}				t_minirt;


typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;

}	t_vector;

typedef struct	s_point3
{
	double	x;
	double	y;
	double	z;

}	t_point3;

typedef struct	s_color
{
	double	x;
	double	y;
	double	z;

}	t_color;

/* MLX-related functions */
void			mlx_open_window(t_mlx *mlx);
void			mlx_loop_window(t_mlx *mlx);
void			mlx_close_window(t_mlx *mlx);
int				mlx_key_press_events(int key_code, t_mlx *mlx);
int				mlx_click_press_events(t_mlx *mlx);
void			mlx_pixel_draw(t_image *image, int x, int y, int color);
void			mlx_create_image(t_minirt *minirt);
void			mlx_image_to_window(t_minirt *minirt, int x, int y);
unsigned long	create_rgb(int r, int g, int b);

#endif

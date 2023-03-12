/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:27 by edu               #+#    #+#             */
/*   Updated: 2023/03/11 21:17:43 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libput.h"

typedef struct s_mlx {
	void	*mlx;
	void	*window;
}				t_mlx;

/* MLX-related functions */
void	mlx_open_window(t_mlx *mlx);
void	mlx_loop_window(t_mlx *mlx);
void	mlx_close_window(t_mlx *mlx);
int		mlx_key_press_events(int key_code, t_mlx *mlx);
int		mlx_click_press_events(t_mlx *mlx);
#endif

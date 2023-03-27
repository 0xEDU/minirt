/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:50:23 by etachott          #+#    #+#             */
/*   Updated: 2023/03/27 16:28:53 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H
# include "rendering.h"
# include "vector.h"
# include "ray.h"
# define SPHERE 1

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
}				t_sphere;

typedef union u_hittable {
	int			type;
	t_sphere	sphere;
}				t_hittable;

/* Hit Record Utils */
void	set_face_normal(t_hit_record *rec, t_ray *ray, t_vector *out_normal);

/* Light hitting functions */
int		hit_sphere(t_sphere sphere,
			t_ray *ray,
			t_variation t,
			t_hit_record *rec);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/26 16:45:05 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	set_record(double *closest, t_hit_record *tr,
	t_hit_record *rec, int index)
{
	*closest = tr->t;
	*rec = *tr;
	rec->index = index;
	return (1);
}

static int	init_shadow_variables(double *closest, t_variation t)
{
	*closest = t.max;
	return (0);
}

static void	set_t_var(t_variation *t_var, t_variation t, double closest)
{
	t_var->min = t.min;
	t_var->max = closest;
}

int	hittable_shadow_hit(t_hittable_list *list, t_ray *ray,
			t_variation t, t_hit_record *rec)
{
	t_hit_record	tr;
	t_hittable_node	*c;
	int				hit_any;
	double			closest;
	t_variation		t_var;

	hit_any = init_shadow_variables(&closest, t);
	c = list->head;
	while (c)
	{
		if (c->index != rec->ignore_index)
		{
			set_t_var(&t_var, t, closest);
			if (c->type == SPHERE && hit_sphere(*(c->sphere), ray, t_var, &tr))
					hit_any = set_record(&closest, &tr, rec, c->index);
			else if (c->type == CONE && hit_cone(*(c->cone), ray, t_var, &tr))
					hit_any = set_record(&closest, &tr, rec, c->index);
			else if (c->type == PL && hit_plane(*(c->plane), ray, t_var, &tr))
					hit_any = set_record(&closest, &tr, rec, c->index);
			else if (c->type == CYL && hit_cylinder(*(c->cyl), ray, t_var, &tr))
					hit_any = set_record(&closest, &tr, rec, c->index);
		}
		c = c->next;
	}
	return (hit_any);
}

int	hittable_list_hit(t_hittable_list *list, t_ray *ray,
			t_variation t, t_hit_record *rec)
{
	t_hit_record	tr;
	t_hittable_node	*c;
	int				hit_any;
	double			closest;
	t_variation		t_var;

	hit_any = 0;
	closest = t.max;
	c = list->head;
	while (c)
	{
		t_var.min = t.min;
		t_var.max = closest;
		if (c->type == SPHERE && hit_sphere(*(c->sphere), ray, t_var, &tr))
				hit_any = set_record(&closest, &tr, rec, c->index);
		else if (c->type == CONE && hit_cone(*(c->cone), ray, t_var, &tr))
				hit_any = set_record(&closest, &tr, rec, c->index);
		else if (c->type == PLANE && hit_plane(*(c->plane), ray, t_var, &tr))
				hit_any = set_record(&closest, &tr, rec, c->index);
		else if (c->type == CYL && hit_cylinder(*(c->cyl), ray, t_var, &tr))
				hit_any = set_record(&closest, &tr, rec, c->index);
		c = c->next;
	}
	return (hit_any);
}

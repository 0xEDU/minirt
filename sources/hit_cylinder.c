/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:26:45 by etachott          #+#    #+#             */
/*   Updated: 2023/04/12 14:52:40 by guribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector vector_project_onto_plane(t_vector v, t_vector n)
{
	t_vector n_scaled;
	double dot_product;

	dot_product = vector_dot(v, n);
	n_scaled = vector_mult(n, dot_product);
	return vector_diff(v, n_scaled);
}

// int hit_cylinder(t_cylinder cyl, t_ray *ray, t_hit_record *rec)
// {
//     t_vector v;
//     t_vector v_origin_center;
//     double discr;
//     double root1, root2;
//     double a, b, c;

//     v_origin_center = vector_diff(ray->origin, cyl.cap_bottom);
//     t_vector projected_origin_center = vector_project_onto_plane(v_origin_center, cyl.axis);
//     v = vector_project_onto_plane(ray->direction, cyl.axis);

//     a = vector_length_squared(v);
//     b = 2 * vector_dot(projected_origin_center, v);
//     c = vector_length_squared(projected_origin_center) - cyl.radius * cyl.radius;

//     discr = b * b - 4 * a * c;
//     if (discr < 0)
//         return (0);

//     root1 = (-b - sqrt(discr)) / (2 * a);
//     root2 = (-b + sqrt(discr)) / (2 * a);

//     // Calculate the intersection points and their heights
//     t_vector point1 = ray_at(*ray, root1);
//     double height1 = vector_dot(cyl.axis, vector_diff(point1, cyl.cap_bottom));

//     t_vector point2 = ray_at(*ray, root2);
//     double height2 = vector_dot(cyl.axis, vector_diff(point2, cyl.cap_bottom));

//     // Check if any of the intersections are within the height range of the cylinder
//     if ((height1 >= 0 && height1 <= cyl.height) && (height2 < 0 || height2 > cyl.height || root1 < root2))
//     {
//         rec->t = root1;
//         rec->point = point1;
//     }
//     else if ((height2 >= 0 && height2 <= cyl.height) && (height1 < 0 || height1 > cyl.height || root2 < root1))
//     {
//         rec->t = root2;
//         rec->point = point2;
//     }
//     else
//     {
//         return (0);
//     }

//     t_vector point_on_axis = vector_sum(cyl.cap_bottom, vector_mult(cyl.axis, vector_dot(vector_diff(rec->point, cyl.cap_bottom), cyl.axis)));
//     rec->normal = vector_unit(vector_diff(rec->point, point_on_axis));
//     set_face_normal(rec, ray, &rec->normal);

//     return (1);
// }

int hit_cylinder(t_cylinder cyl, t_ray *ray, t_variation t, t_hit_record *rec)
{
    t_vector v;
    t_vector v_origin_center;
    double discr;
    double root1, root2;
    double a, b, c;

    v_origin_center = vector_diff(ray->origin, cyl.cap_bottom);
    t_vector projected_origin_center = vector_project_onto_plane(v_origin_center, cyl.axis);
    v = vector_project_onto_plane(ray->direction, cyl.axis);

    a = vector_length_squared(v);
    b = 2 * vector_dot(projected_origin_center, v);
    c = vector_length_squared(projected_origin_center) - cyl.radius * cyl.radius;

    discr = b * b - 4 * a * c;
    if (discr < 0)
        return (0);

    root1 = (-b - sqrt(discr)) / (2 * a);
    root2 = (-b + sqrt(discr)) / (2 * a);

    // Calculate the intersection points and their heights
    t_vector point1 = ray_at(*ray, root1);
    double height1 = vector_dot(cyl.axis, vector_diff(point1, cyl.cap_bottom));

    t_vector point2 = ray_at(*ray, root2);
    double height2 = vector_dot(cyl.axis, vector_diff(point2, cyl.cap_bottom));

    // Check if any of the intersections are within the height range of the cylinder and the t_variation range
    if ((height1 >= 0 && height1 <= cyl.height && root1 >= t.min && root1 <= t.max) && (height2 < 0 || height2 > cyl.height || root2 < t.min || root2 > t.max || root1 < root2))
    {
        rec->t = root1;
        rec->point = point1;
    }
    else if ((height2 >= 0 && height2 <= cyl.height && root2 >= t.min && root2 <= t.max) && (height1 < 0 || height1 > cyl.height || root1 < t.min || root1 > t.max || root2 < root1))
    {
        rec->t = root2;
        rec->point = point2;
    }
    else
    {
        return (0);
    }

    t_vector point_on_axis = vector_sum(cyl.cap_bottom, vector_mult(cyl.axis, vector_dot(vector_diff(rec->point, cyl.cap_bottom), cyl.axis)));
    rec->normal = vector_unit(vector_diff(rec->point, point_on_axis));
    set_face_normal(rec, ray, &rec->normal);

    return (1);
}
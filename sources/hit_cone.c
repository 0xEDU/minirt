#include "minirt.h"

int hit_cone(t_cone cone, t_ray *ray, t_variation t, t_hit_record *rec) {
	double k = tan(cone.angle) * tan(cone.angle);
	t_vector v_origin_vertex = vector_diff(ray->origin, cone.vertex);
	t_vector v = ray->direction;

	double a = vector_dot(v, v) - (1 + k) * pow(vector_dot(v, cone.axis), 2);
	double b = 2 * (vector_dot(v, v_origin_vertex) - (1 + k) * vector_dot(v, cone.axis) * vector_dot(v_origin_vertex, cone.axis));
	double c = vector_dot(v_origin_vertex, v_origin_vertex) - (1 + k) * pow(vector_dot(v_origin_vertex, cone.axis), 2);

	double discr = b * b - 4 * a * c;
	if (discr < 0)
		return 0;
	double root1 = (-b - sqrt(discr)) / (2 * a);
	double root2 = (-b + sqrt(discr)) / (2 * a);

	t_vector point1 = ray_at(*ray, root1);
	double height1 = vector_dot(cone.axis, vector_diff(point1, cone.vertex));
	t_vector point2 = ray_at(*ray, root2);
	double height2 = vector_dot(cone.axis, vector_diff(point2, cone.vertex));

	if ((height1 >= 0 && height1 <= cone.height && root1 >= t.min && root1 <= t.max) || (height2 >= 0 && height2 <= cone.height && root2 >= t.min && root2 <= t.max)) {
		if ((height1 >= 0 && height1 <= cone.height && root1 >= t.min && root1 <= t.max) && (height2 < 0 || height2 > cone.height || root2 < t.min || root2 > t.max || root1 < root2))
		{
			rec->t = root1;
			rec->point = point1;
		}
		else
		{
			rec->t = root2;
			rec->point = point2;
		}
		t_vector point_on_axis = vector_sum(cone.vertex, vector_mult(cone.axis, vector_dot(vector_diff(rec->point, cone.vertex), cone.axis)));
		rec->normal = vector_unit(vector_diff(rec->point, point_on_axis));
		set_face_normal(rec, ray, &rec->normal);
		return 1;
	}

	return 0;
}

#include "hittable.h"

t_hit_record new_hit_record(t_ray *ray, t_hittable hittable)
{
	t_hit_record rec;

	// if (hittable.type == SPHERE) {
	rec.t = root(ray, hittable);
	rec.is_hit = (rec.t >= 0.0);
	rec.normal = unit(subtract_vector(point_on_ray(ray, rec.t), hittable.center));
	// }
	return rec;
}

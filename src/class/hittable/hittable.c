#include "hittable.h"

t_bool is_hit(t_ray *ray, t_hittable hittable)
{
	if (hittable.type == SPHERE)
		return (sp_discriminant(ray, hittable) >= 0);
	return 0;
}

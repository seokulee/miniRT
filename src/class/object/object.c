#include "object.h"

t_bool is_hit(t_ray *ray, t_object object)
{
	if (object.type == SPHERE)
		return (sp_discriminant(ray, object) >= 0);
	return 0;
}

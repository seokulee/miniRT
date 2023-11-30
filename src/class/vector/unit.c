#include "class.h"

double	length(t_vector vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

t_vector	unit(t_vector vector)
{
	double len;

	len = length(vector);
	if (len > 0)
	{
		vector.x /= len;
		vector.y /= len;
		vector.z /= len;
	}
	return vector;
}

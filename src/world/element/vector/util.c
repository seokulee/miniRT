#include "element.h"

double v_length(t_vector vector)
{
	return sqrt(v_power(vector));
}

t_vector	unit(t_vector vector)
{
	double len;

	len = v_length(vector);
	if (len > 0)
	{
		vector.x /= len;
		vector.y /= len;
		vector.z /= len;
	}
	return vector;
}

t_vector reverse(t_vector vector)
{
	return v_multiple(vector, -1);
}

double v_power(t_vector vector)
{
	return (vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

t_vector v_cross(t_vector v1, t_vector v2)
{
	t_vector vector;

	vector.x = v1.y * v2.z - v1.z * v2.y;
	vector.y = v1.z * v2.x - v1.x * v2.z;
	vector.z = v1.x * v2.y - v1.y * v2.x;
	return vector;
}

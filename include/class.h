#ifndef CLASS_H
# define CLASS_H

/* ------------------------- class boolean ------------------------- */
typedef int t_bool;

# define TRUE 1;
# define FALSE 0;

/* ------------------------- class vector ------------------------- */
typedef struct s_vector
{
	double x;
	double y;
	double z;
} t_vector;

t_vector new_vector(double x, double y, double z);
t_vector add_vector(t_vector v1, t_vector v2);
t_vector subtract_vector(t_vector v1, t_vector v2);
t_vector multiply_scalar(t_vector vector, double scalar);
double dot_product(t_vector v1, t_vector v2);

/* ------------------------- class view ------------------------- */
typedef struct s_view
{
	double w_width;
	double w_height;
	double n_width;
	double n_height;
	t_vector camera;
	t_vector left_top_from_cam;
} t_view;

t_view new_view(double w_width, double w_height, t_vector camera);

/* ------------------------- class pixel ------------------------- */
typedef struct s_pixel
{
	int x;
	int y;
} t_pixel;

t_pixel new_pixel(int x, int y);
t_vector pixel_to_vector(t_pixel pixel, t_view view);

/* ------------------------- class ray ------------------------- */
typedef struct s_ray
{
	t_vector pos; // position
	t_vector dir; // direction
} t_ray;

t_ray ray_from_camera(t_pixel pixel, t_view view);

#endif

#include "hittable.h"

void init_list(t_hittable_list *list)
{
	list->last = &list->dummy_first;
}

void add_object(t_hittable_list *list, t_hittable *object)
{
	list->last->next = object;
	list->last = object;
}

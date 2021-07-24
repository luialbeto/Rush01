#include "t_args.h"
#include "t_matrix.h"

int	ft_is_error(t_args *a);

int	ft_rush(t_args *a, t_matrix *m)
{
	int	i;
	int	j;

	if (ft_is_error(a))
		return (-1);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_error(t_args *a)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (((a->up[i] == a->down[i]) && a->up[i] >= 3) ||
			((a->left[i] == a->right[i]) && a->left[i] >= 3) ||
			(a->up[i] <= 0 || a->down[i] <= 0 ||
			a->left[i] <= 0 || a->right[i] <= 0))
			return (-1);
		i++;
	}
	return (0);
}

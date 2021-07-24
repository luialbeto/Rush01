#include <stdlib.h>
#include "t_matrix.h"

void	ft_free(t_matrix *m)
{
	int	i;

	i = 0;
	while (i < m->rows)
	{
		free(m->values[i]);
		i++;
	}
	free(m->values);
}

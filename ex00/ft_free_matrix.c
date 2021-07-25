#include <stdlib.h>
#include "structs.h"

void	ft_free_matrix(t_matrix *m)
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

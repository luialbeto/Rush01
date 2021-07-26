#include "structs.h"

int	ft_find_unassigned_location(t_matrix *m, t_pos *p)
{
	p->row = 0;
	while (p->row < m->rows)
	{
		p->col = 0;
		while (p->col < m->cols)
		{
			if (m->values[p->row][p->col] == 0)
				return (1);
			p->col++;
		}
		p->row++;
	}
	return (0);
}

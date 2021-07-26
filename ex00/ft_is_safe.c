#include "structs.h"

int	ft_used_in_row(t_matrix *m, int row, int val);
int	ft_used_in_col(t_matrix *m, int col, int val);

int	ft_is_safe(t_matrix *m, t_pos *p, int val)
{
	return (!ft_used_in_row(m, p->row, val)
		&& !ft_used_in_col(m, p->col, val)
		&& m->values[p->row][p->col] == 0);
}

int	ft_used_in_row(t_matrix *m, int row, int val)
{
	int	col;

	col = 0;
	while (col < m->cols)
	{
		if (m->values[row][col] == val)
			return (1);
		col++;
	}
	return (0);
}

int	ft_used_in_col(t_matrix *m, int col, int val)
{
	int	row;

	row = 0;
	while (row < m->rows)
	{
		if (m->values[row][col] == val)
			return (1);
		row++;
	}
	return (0);
}

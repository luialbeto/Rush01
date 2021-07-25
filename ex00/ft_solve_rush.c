#include "structs.h"

int	ft_find_unassigned_location(t_matrix *m, int *row, int *col);
int	ft_used_in_col(t_matrix *m, int col, int val);
int	ft_used_in_row(t_matrix *m, int row, int val);
int ft_is_safe(t_matrix *m, int row, int col, int val);

int	ft_solve_rush(t_input *i, t_matrix *m)
{
	int	row;
	int	col;
	int	val;

	if (!ft_find_unassigned_location(m, &row, &col))
		return (1);
	
	val = 1;
	while (val <= m->rows)
	{
		if (ft_is_safe(m, row, col, val))
		{
			m->values[row][col] = val;

			if (ft_solve_rush(i, m))
				return (1);

			m->values[row][col] = 0;
		}
		val++;
	}
	return (0);
}

int ft_is_safe(t_matrix *m, int row, int col, int val)
{
	return !ft_used_in_row(m, row, val) &&
			!ft_used_in_col(m, col, val) &&
			m->values[row][col] == 0;
}

int	ft_used_in_row(t_matrix *m, int row, int val)
{
	int col;

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
	int row;

	row = 0;
	while (row < m->rows)
	{
		if (m->values[row][col] == val)
			return (1);
		row++;
	}
	return (0);
}

int	ft_find_unassigned_location(t_matrix *m, int *row, int *col)
{
	*row = 0;
	while (*row < m->rows)
	{
		*col = 0;
		while (*col < m->cols)
		{
			if (m->values[*row][*col] == 0)
				return (1);
			(*col)++;
		}
		(*row)++;
	}
	return (0);
}

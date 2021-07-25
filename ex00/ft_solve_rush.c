#include <stdio.h>

#include "structs.h"

void	ft_print(t_matrix *m);
int	ft_find_unassigned_location(t_matrix *m, t_pos *p);
int	ft_used_in_col(t_matrix *m, int col, int val);
int	ft_used_in_row(t_matrix *m, int row, int val);
int ft_is_safe(t_matrix *m, t_pos *p, int val);
int	ft_matches_up(int *up, t_matrix *m, int col);
int	ft_matches_down(int *down, t_matrix *m, int col);
int	ft_matches_left(int *left, t_matrix *m, int row);
int	ft_matches_right(int *right, t_matrix *m, int row);
int	ft_matches_input(t_input *i, t_matrix *m, t_pos *p);

int	ft_solve_rush(t_input *i, t_matrix *m)
{
	t_pos	p;
	int		val;


	if (!ft_find_unassigned_location(m, &p) &&
		ft_matches_input(i, m, &p))
		return (1);

	ft_print(m);
	printf("\n\n");

	val = 1;
	while (val <= m->rows)
	{
		if (ft_is_safe(m, &p, val))
		{
			m->values[p.row][p.col] = val;

			if (ft_solve_rush(i, m))
				return (1);

			m->values[p.row][p.col] = 0;
		}
		val++;
	}
	return (0);
}

int	ft_matches_input(t_input *i, t_matrix *m, t_pos *p)
{
	return ft_matches_up(i->up, m, p->col) &&
			ft_matches_down(i->down, m, p->col) &&
			ft_matches_left(i->left, m, p->row) &&
			ft_matches_right(i->right, m, p->row);
}

int	ft_matches_up(int *up, t_matrix *m, int col)
{
	int	row;
	int	count;

	count = m->rows;
	row = 1;
	while (row < m->rows)
	{
		if (m->values[row][col] < m->values[0][col] &&
			m->values[row][col] != 0)
			count--;
		row++;
	}
	return count == up[col];
}

int	ft_matches_down(int *down, t_matrix *m, int col)
{
	int	row;
	int	count;

	count = m->rows;
	row = 0;
	while (row < m->rows - 1)
	{
		if (m->values[row][col] < m->values[m->rows - 1][col] &&
			m->values[row][col] != 0)
			count--;
		row++;
	}
	return count == down[col];
}

int	ft_matches_left(int *left, t_matrix *m, int row)
{
	int	col;
	int	count;

	count = m->cols;
	col = 1;
	while (col < m->cols)
	{
		if (m->values[row][col] < m->values[row][0] &&
			m->values[row][col] != 0)
			count--;
		col++;
	}
	return count == left[row];
}

int	ft_matches_right(int *right, t_matrix *m, int row)
{
	int	col;
	int	count;

	count = m->cols;
	col = 0;
	while (col < m->cols - 1)
	{
		if (m->values[row][col] < m->values[row][m->cols - 1] &&
			m->values[row][col] != 0)
			count--;
		col++;
	}
	return count == right[row];
}

int ft_is_safe(t_matrix *m, t_pos *p, int val)
{
	return !ft_used_in_row(m, p->row, val) &&
			!ft_used_in_col(m, p->col, val) &&
			m->values[p->row][p->col] == 0;
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

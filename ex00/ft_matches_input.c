#include "structs.h"

int	ft_matches_up(int *up, t_matrix *m, int col);
int	ft_matches_down(int *down, t_matrix *m, int col);
int	ft_matches_left(int *left, t_matrix *m, int row);
int	ft_matches_right(int *right, t_matrix *m, int row);

int	ft_matches_input(t_input *i, t_matrix *m, t_pos *p)
{
	return (ft_matches_up(i->up, m, p->col)
		&& ft_matches_down(i->down, m, p->col)
		&& ft_matches_left(i->left, m, p->row)
		&& ft_matches_right(i->right, m, p->row));
}

int	ft_matches_up(int *up, t_matrix *m, int col)
{
	int	row;
	int	count;

	count = m->rows;
	row = 1;
	while (row < m->rows)
	{
		if (m->values[row][col] < m->values[0][col])
			count--;
		row++;
	}
	return (count == up[col]);
}

int	ft_matches_down(int *down, t_matrix *m, int col)
{
	int	row;
	int	count;

	count = m->rows;
	row = 0;
	while (row < m->rows - 1)
	{
		if (m->values[row][col] < m->values[m->rows - 1][col])
			count--;
		row++;
	}
	return (count == down[col]);
}

int	ft_matches_left(int *left, t_matrix *m, int row)
{
	int	col;
	int	count;

	count = m->cols;
	col = 1;
	while (col < m->cols)
	{
		if (m->values[row][col] < m->values[row][0])
			count--;
		col++;
	}
	return (count == left[row]);
}

int	ft_matches_right(int *right, t_matrix *m, int row)
{
	int	col;
	int	count;

	count = m->cols;
	col = 0;
	while (col < m->cols - 1)
	{
		if (m->values[row][col] < m->values[row][m->cols - 1])
			count--;
		col++;
	}
	return (count == right[row]);
}

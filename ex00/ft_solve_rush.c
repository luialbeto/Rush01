#include "structs.h" // adaptamos uma estrutura de sudoku

void	ft_print(t_matrix *m);
int		ft_find_unassigned_location(t_matrix *m, t_pos *p);
int		ft_is_safe(t_matrix *m, t_pos *p, int val);
int		ft_matches_input(t_input *i, t_matrix *m, t_pos *p);
int		ft_validate(t_input *i, t_matrix *m);

int	ft_solve_rush(t_input *i, t_matrix *m)
{
	t_pos	p;
	int		val;

	if (!ft_find_unassigned_location(m, &p)) // se não tiver mais 0, retorna validação, quebrou o código
		return (ft_validate(i, m));
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

int	ft_validate(t_input *i, t_matrix *m)
{
	t_pos	aux;

	aux.row = 0;
	while (aux.row < m->rows)
	{
		aux.col = 0;
		while (aux.col < m->cols)
		{
			if (!ft_matches_input(i, m, &aux))
				return (0);
			aux.col++;
		}
		aux.row++;
	}
	return (1);
}

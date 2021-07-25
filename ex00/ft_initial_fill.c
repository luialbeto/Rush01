#include "structs.h"

void	ft_initial_fill_cols(t_input *in, t_matrix *ma);
void	ft_initial_fill_rows(t_input *in, t_matrix *ma);

void	ft_initial_fill(t_input *in, t_matrix *ma)
{
	ft_initial_fill_cols(in, ma);
	ft_initial_fill_rows(in, ma);
}

void	ft_initial_fill_rows(t_input *in, t_matrix *ma)
{
	int			i;
	int			j;

	i = 0;
	while (i < ma->rows)
	{
		if (in->left[i] == ma->cols)
		{
			j = 0;
			while (j < ma->cols)
			{
				ma->values[i][j] = j + 1;
				j++;
			}
		}
		else if (in->left[i] == 1)
			ma->values[i][0] = ma->cols;
		i++;
	}
}

void	ft_initial_fill_cols(t_input *in, t_matrix *ma)
{
	int			i;
	int			j;

	i = 0;
	while (i < ma->cols)
	{
		if (in->up[i] == ma->rows)
		{
			j = 0;
			while (j < ma->rows)
			{
				ma->values[j][i] = j + 1;
				j++;
			}
		}
		else if (in->up[i] == 1)
			ma->values[0][i] = ma->rows;
		i++;
	}
}

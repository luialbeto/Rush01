#include "structs.h"

void	ft_putstr(char *str, int size);
void	ft_putchar(char c);

void	ft_print(t_matrix *m)
{
	int i;
	int j;

	i = 0;
	while(i < m->rows)
	{
		j = 0;
		while(j < m->cols)
		{
			ft_putchar(m->values[i][j] + '0');
			if (j < m->cols - 1)
				ft_putstr(" ", 1);
			j++;
		}
		ft_putstr("\n", 1);
		i++;
	}	
}

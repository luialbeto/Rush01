#include <stdio.h>

#include "structs.h"

t_input		ft_get_input(char *str);
t_matrix	ft_create_matrix(int row, int col);
int			ft_solve_rush(t_input *input, t_matrix *m);
void		ft_print(t_matrix *m);
void		ft_putstr(char *str, int size);
void		ft_free_matrix(t_matrix *m);

int	main(int argc, char **argv)
{
	t_input		input;
	t_matrix	matrix;
	int			is_success;

	is_success = 0;
	if (argc > 1)
	{
		input = ft_get_input(argv[1]);
		matrix = ft_create_matrix(4, 4);
		is_success = ft_solve_rush(&input, &matrix);
		if (is_success)
			ft_print(&matrix);
		ft_free_matrix(&matrix);
	}
	if (argc <= 1 || !is_success)
		ft_putstr("Error\n", 6);
	return (0);
}

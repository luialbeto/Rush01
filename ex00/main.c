#include <stdio.h>

#include "t_args.h"
#include "t_matrix.h"

t_args		ft_get_args(char *str);
t_matrix	ft_create_matrix(int row, int col);
int			ft_rush(t_args *args, t_matrix *m);
void		ft_print(t_matrix *m);
void		ft_putstr(char *str, int size);
void		ft_free(t_matrix *m);

int	main(int argc, char **argv)
{
	t_args		args;
	t_matrix	matrix;
	int			is_error;

	is_error = 0;
	if (argc > 1)
	{
		args = ft_get_args(argv[1]);
		matrix = ft_create_matrix(4, 4);
		is_error = ft_rush(&args, &matrix);
		if (!is_error)
			ft_print(&matrix);
		ft_free(&matrix);
	}
	if (argc <= 1 || is_error)
		ft_putstr("Error\n", 6);
	return (0);
}

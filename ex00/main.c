#include "t_matrix.h"

int	*ft_get_input(char *str);
t_matrix ft_create_matrix(int row, int col);
void	ft_print(t_matrix *m);

int	main()
{
	t_matrix m;

	m = ft_create_matrix(4,4);
	ft_print(&m);
	//ft_get_input("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
}

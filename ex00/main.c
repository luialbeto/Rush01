#include <stdio.h>

#include "structs.h"

t_input		ft_get_input(char *str);
t_matrix	ft_create_matrix(int row, int col);
int			ft_solve_rush(t_input *input, t_matrix *m);
void		ft_print(t_matrix *m);
void		ft_putstr(char *str, int size);
void		ft_free_matrix(t_matrix *m);

int	main(int argc, char **argv) // quantidade e valores
{
	t_input		input; // variável do tipo t_input - criada por nós - struct - facilitar e diminuir parâmetros - similar objeto em JS
	t_matrix	matrix;
	int			is_success; // verifica se o programa inicia normalmente

	is_success = 0; // inicia como 0 - booleano e 0 é falso
	if (argc > 1) // quando executa programa, quantidade de elementos padrão é 1
	{
		input = ft_get_input(argv[1]); // chama a função ft_get_input, passando o valor 1 do vetor argv
		matrix = ft_create_matrix(4, 4); // transforma valor em int
		is_success = ft_solve_rush(&input, &matrix); 
		if (is_success)
			ft_print(&matrix);
		ft_free_matrix(&matrix);
	}
	if (argc <= 1 || !is_success)
		ft_putstr("Error\n", 6);
	return (0);
}

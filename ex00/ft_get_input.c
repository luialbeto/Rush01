#include <stdlib.h>
#include "structs.h"

void	ft_store_values(char *str, t_input *input, int *i);

t_input	ft_get_input(char *str)
{
	t_input	input;
	int		i;

	input.up = (int *) malloc(4 * sizeof(int));
	input.down = (int *) malloc(4 * sizeof(int));
	input.left = (int *) malloc(4 * sizeof(int));
	input.right = (int *) malloc(4 * sizeof(int));
	i = 0;
	while (*str != '\0') // guarda valor numérico na string correspondente
	{
		ft_store_values(str, &input, &i);
		str++;
	}
	return (input);
}

void	ft_store_values(char *str, t_input *input, int *i) // 
{
	int	value;
	int	index;

	if (*str != ' ')
	{
		value = *str - '0'; // transforma em int
		index = *i % 4; // pega o valor do parâmetro i faz mod 4, pq o tabuleiro é 4x4
		if (*i < 4)
			input->up[index] = value; // coloca no vetor up
		else if (*i < 8)
			input->down[index] = value; // entre 5 e 8, guarda no vetor down
		else if (*i < 12)
			input->left[index] = value; // entre 9 e 12 guarda no left
		else
			input->right[index] = value; // caso contrário, no right
		(*i)++;
	}
}

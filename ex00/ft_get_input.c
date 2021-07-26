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
	while (*str != '\0')
	{
		ft_store_values(str, &input, &i);
		str++;
	}
	return (input);
}

void	ft_store_values(char *str, t_input *input, int *i)
{
	int	value;
	int	index;

	if (*str != ' ')
	{
		value = *str - '0';
		index = *i % 4;
		if (*i < 4)
			input->up[index] = value;
		else if (*i < 8)
			input->down[index] = value;
		else if (*i < 12)
			input->left[index] = value;
		else
			input->right[index] = value;
		(*i)++;
	}
}

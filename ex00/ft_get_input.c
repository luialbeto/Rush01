#include <stdlib.h>
#include "structs.h"

t_input	ft_get_input(char *str)
{
	t_input	input;
	int		i;
	int		value;
	int		index;

	i = 0;
	input.up = (int *) malloc(4 * sizeof(int));
	input.down = (int *) malloc(4 * sizeof(int));
	input.left = (int *) malloc(4 * sizeof(int));
	input.right = (int *) malloc(4 * sizeof(int));
	while (*str != '\0')
	{
		if (*str != ' ')
		{
			value = *str - '0';
			index = i % 4;
			if (i < 4)
				input.up[index] = value;
			else if (i < 8)
				input.down[index] = value;
			else if (i < 12)
				input.left[index] = value;
			else
				input.right[index] = value;
			i++;
		}
		str++;
	}
	return (input);
}

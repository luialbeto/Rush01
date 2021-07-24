#include <stdlib.h>
#include "t_args.h"

t_args	ft_get_args(char *str)
{
	t_args	args;
	int		i;
	int		value;
	int		index;

	i = 0;
	args.up = (int *) malloc(4 * sizeof(int));
	args.down = (int *) malloc(4 * sizeof(int));
	args.left = (int *) malloc(4 * sizeof(int));
	args.right = (int *) malloc(4 * sizeof(int));
	while (*str != '\0')
	{
		if (*str != ' ')
		{
			value = *str - '0';
			index = i % 4;
			if (i < 4)
				args.up[index] = value;
			else if (i < 8)
				args.down[index] = value;
			else if (i < 12)
				args.left[index] = value;
			else
				args.right[index] = value;
			i++;
		}
		str++;
	}
	return (args);
}

#include <stdlib.h>
#include "structs.h"

t_matrix ft_create_matrix(int rows, int cols)
{
	t_matrix	matrix;
	int			i;
	int			j;

	i = 0;
	matrix.rows = rows;
	matrix.cols = cols;
	matrix.values = (int **) malloc(rows * sizeof(int *));
	while(i < rows)
	{
		matrix.values[i] = (int *) malloc(cols * sizeof(int));
		j = 0;
		while (j < cols)
		{
			matrix.values[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

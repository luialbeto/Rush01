#include <stdlib.h>
#include "t_matrix.h"

t_matrix ft_create_matrix(int row, int col)
{
	t_matrix matrix;
	int i;
	int j;

	i = 0;
	matrix.rows = row;
	matrix.cols = col;
	matrix.values = (int **) malloc(row * sizeof(int *));
	while(i < row)
	{
		matrix.values[i] = (int *) malloc(col * sizeof(int));
		j = 0;
		while(j < col)
		{
			matrix.values[i][j] = i + j;
			j++;
		}
		i++;
	}
	return(matrix);
}

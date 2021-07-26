#include <stdlib.h>
#include "structs.h"

t_matrix	ft_create_matrix(int rows, int cols) // tipo t-matrix
{
	t_matrix	matrix;
	int			i;
	int			j;

	i = 0;
	matrix.rows = rows; // passamos a quantidade de linhas que essa matrix vai ter
	matrix.cols = cols; // idem para colunas
	matrix.values = (int **) malloc(rows * sizeof(int *)); // alocando um ponteiro para ponteior de int - matrix de duas dimensões - cada linha vai ter um vetor
	while (i < rows) // percorre as linhas e aloca quantidade de colunas do tipo int para cada uma delas
	{
		matrix.values[i] = (int *) malloc(cols * sizeof(int));
		j = 0;
		while (j < cols) // enquanto j for menor que a coluna, percorre a coluna e coloca valor 0, para mostrar que não colocou nenhuma caixa na matrix
		{
			matrix.values[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

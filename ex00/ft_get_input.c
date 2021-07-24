#include <stdlib.h>

int	*ft_get_input(char *str)
{
	int *arr;
	int i;

	i = 0;
	arr = (int *) malloc(16 * sizeof(int));
	while (*str != '\0')
	{
		if (*str != ' ')
		{
			arr[i] = *str - '0';
			i++;
		}
		str++;
	}
	return(arr);
}

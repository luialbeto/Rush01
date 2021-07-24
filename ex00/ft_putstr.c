#include <unistd.h>

void	ft_putstr(char *str, int size)
{
	write(1, str, size);
}

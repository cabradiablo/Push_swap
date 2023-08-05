#include "libft.h"

void	ft_free_matrix(char **matrix)
{
	int	row;

	row = -1;
	while (matrix[++row]);
	while (--row >= 0)
		free(matrix[row]);
	free(matrix);
}

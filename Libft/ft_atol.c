#include "libft.h"

long	ft_atol(char *str)
{
	long	result;
	int	i;
	long	flag;

	result = 0;
	i = 0;
	flag = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * flag);
}
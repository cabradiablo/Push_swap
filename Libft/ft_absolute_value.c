#include "libft.h"

long    ft_absolute_value(long nbr)
{
    if (nbr < 0)
        return (nbr * (-1));
    else
        return (nbr);
}
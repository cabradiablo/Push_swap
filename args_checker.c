#include "pushswap.h"


void    duplicate_checker(char **nbr)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (nbr[i])
    {
        j = i + 1;
        while (nbr[j])
        {
            if (ft_atoi(nbr[i]) == ft_atoi(nbr[j]))
                ft_error("ERROR: DUPLICATED INPUT\n");
            j++;
        }
        i++;
    }
}

void    valid_int_checker(char  *nbr)
{
    long    aux;

    if (!nbr)
        return;
    if ((*nbr == '-' || *nbr == '+'))
        nbr++;
    if (*nbr == '\0')
        ft_error("ERROR: NO NUMBER AFTER SIGN\n");
    while(*nbr != '\0')
    {
        if (*(nbr) < '0' || *(nbr) > '9')
            ft_error("ERROR: INVALID SYNTAX ARGUMENT\n");
        nbr++;
    }
    aux = ft_atol(nbr);
    if(aux > INT_MAX || aux < INT_MIN)
        ft_error("ERROR: NUMBER IS TOO LARGE\n");
}
void    ft_checker(char **nbr)
{
    int i;

    i = 0;
    while (nbr[i])
        valid_int_checker(nbr[i++]);
    duplicate_checker(nbr);
}
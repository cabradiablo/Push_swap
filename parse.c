#include "pushswap.h"

void stack_a_maker(char **nbr, t_stack **stack_a)
{
    t_stack *node;
    
    int i = 0;
    *stack_a = NULL;
    node = NULL;
    while (nbr[i])
    {
        node = (t_stack *)malloc(sizeof(t_stack));
        if (!node)
            ft_error("MALLOC");
        (*node)->nbr = ft_atol(nbr[i]);
        (*node)->next = *stack_a;
        *stack_a = node;
        i++;
    }
}

void    valid_nbr(char  *nbr)
{
    if (*nbr == '-' || *nbr == '+')
        *nbr++;
    while(*nbr != '\0')
        if (*(nbr) <= '0' || *(nbr++) >= '9')
            ft_error("INVALID SYNTAX ARGUMENT");
}
void    list_getter_zsh(int argc, char **argv, t_stack *stack_a)
{
    int i;

    i = 0;

    while (i < argc)
        valid_nbr(argv[i++]);
    stack_a_maker(argv, stack_a);
}

void    list_getter_bash(char *argv, t_stack *stack_a)
{
    char    **nbr;
    int         i;

    nbr = ft_split(argv[1], ' ');
    while (nbr[i])
        valid_nbr(nbr[i++]);
    stack_a_maker(nbr, stack_a);
}

void    ft_parser(int argc, char **argv, t_stack *stack_a)
{
    if (argc <= 1)
        ft_error("INVALID NUMEBER OF ARGUMENT");
    if (argc == 2)
        list_getter_bash(argv[1], stack_a);
    else
        list_getter_zsh(argc, argv, stack_a);
}
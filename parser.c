#include "pushswap.h"

void stack_a_maker(char **nbr)
{
    t_stack  *stack_a;
    t_stack *node;
    long    i;

    i = 0;
    stack_a = NULL;
    node = NULL;
    while (nbr[i])
    {
        node = (t_stack*)ft_calloc(sizeof(t_stack), 1);
        if (!node)
            ft_error("MALLOC");
        node->nbr = ft_atol(nbr[i]);
        if(node->nbr > __INT_MAX__ || node->nbr < INT_MIN)
		    ft_error("NUMBER IS TOO LARGE");
        ft_stackadd_back(&stack_a, node);
        i++;
    }
    //ft_rotate(&stack_a, 'a');
    print_list(stack_a);
}

void    list_getter_bash(int argc, char **argv)
{
    int i;

    i = 0;
    while (i < argc)
        ft_checker(argv[i++]);
    duplicate_checker(argv + 1);
    stack_a_maker(argv);
}

void    list_getter_zsh(char *argv)
{
    char    **nbr;
    int         i;

    i = 0;
    nbr = ft_split(argv, ' ');
    while (nbr[i])
        ft_checker(nbr[i++]);
    duplicate_checker(nbr);
    stack_a_maker(nbr);
    ft_free_matrix(nbr);
}

void    ft_parser(int argc, char **argv)
{
    if (argc <= 1)
        ft_error("INVALID NUMEBER OF ARGUMENT");
    if (argc == 2)
        list_getter_zsh(argv[1]);
    else
        list_getter_bash(argc, argv + 1);
}

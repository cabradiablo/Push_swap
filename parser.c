#include "pushswap.h"

t_stack *stack_a_maker(char **nbr)
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
        ft_stackadd_back(&stack_a, node);
        i++;
    }
    print_list(stack_a);
    return (stack_a);
}

t_stack *ft_parser(int argc, char **argv)
{
    t_stack *stack_a;
    char    **nbr;

    if (argc <= 1)
        ft_error("INVALID NUMEBER OF ARGUMENT");
    else if (argc == 2)
    {
        nbr = ft_split(argv[1], ' ');
        ft_checker(nbr);
        stack_a = stack_a_maker(nbr);
        ft_free_matrix(nbr);
    }
    else
    {
        nbr = ft_argv_cleaner(argc, argv);
        ft_checker(nbr);
        stack_a = stack_a_maker(nbr);
        ft_free_matrix(nbr);
    }
    return (stack_a);
}

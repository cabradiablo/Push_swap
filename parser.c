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
    ft_reverse_rotate(&stack_a, 'a');
    print_list(stack_a);
    return (stack_a);
}

void    list_getter_bash(char **argv)
{
    ft_checker(argv);
    stack_a_maker(argv);
}

void    list_getter_zsh(char *argv)
{
    char    **nbr;

    nbr = ft_split(argv, ' ');
    ft_checker(nbr);
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
        list_getter_bash(argv + 1);
}

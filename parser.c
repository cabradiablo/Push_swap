#include "pushswap.h"

void card_to_ord(t_stack **stack_a)
{
    t_stack *aux;
    t_stack *temp;
    long i;

    temp = *stack_a;
    while (temp)
    {
        i = 1;
        aux = *stack_a;
        while (aux)
        {
            if (temp->nbr > aux->nbr)
                i++;
            aux = aux->next;
        }
        temp->index = i;
        temp = temp->next;
    }
}

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
            ft_error("MALLOC\n");
        node->nbr = ft_atol(nbr[i]);
        ft_stackadd_back(&stack_a, node);
        i++;
    }
    return (stack_a);
}

t_stack *ft_parser(int argc, char **argv)
{
    t_stack *stack_a;
    char    **nbr;

    if (argc <= 1)
        ft_error("INVALID NUMEBER OF ARGUMENT\n");
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
    card_to_ord(&stack_a);
    return (stack_a);
}

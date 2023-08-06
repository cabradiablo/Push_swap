#include "pushswap.h"

void print_list(t_stack *stack)
{
    if (!stack)
        return;
    printf("%li\n", stack->nbr);
    print_list(stack->next);
}

char    **ft_argv_cleaner(int argc, char **argv)
{
    char    **aux;
    int     i;

    aux = (char **)malloc(sizeof(char *) * argc);
    i = -1;
    while (++i < argc - 1)
        aux[i] = ft_strdup(argv[i + 1]);
    aux[i] = NULL;
    return (aux);
}

void ft_stackadd_back(t_stack **stack, t_stack *node)
{
    t_stack *aux;

    if (*stack == NULL)
        *stack = node;
    else
    {
        aux = *stack;
        while (aux->next)
            aux = aux->next;
        aux->next = node;
        aux->next->prev = aux;
    }
}
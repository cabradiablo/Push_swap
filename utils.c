#include "pushswap.h"

void print_list(t_stack *stack)
{
    if (!stack)
        return;
    printf("%li\n", stack->nbr);
    print_list(stack->next);
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
#include "pushswap.h"

void    ft_swap(t_stack **stack, char x)
{
    long    aux1;
    long    aux2;
    long    aux_ind1;
    long    aux_ind2;

    if (*stack == NULL || (*stack)->next == NULL)
        ft_error("ERROR: EMPTY STACK\n");
    aux1 = (*stack)->nbr;
    aux2 = (*stack)->next->nbr;
    aux_ind1 = (*stack)->index;
    aux_ind2 = (*stack)->next->index;
    (*stack)->nbr = aux2;
    (*stack)->next->nbr = aux1;
    (*stack)->index = aux_ind2;
    (*stack)->next->index = aux_ind1;
    if (x == 'a')
        write(1, "sa\n", 3);
    else if (x == 'b')
        write(1, "sb\n", 3);
    else
        ft_error("ERROR: BAD STACK\n");
}

void ft_doubleswap(t_stack **stacka, t_stack **stackb)
{
    ft_swap(stacka, 'a');
    ft_swap(stackb, 'b');
    write(1, "ss\n", 3);
}
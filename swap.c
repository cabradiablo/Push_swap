#include "pushswap.h"

void    ft_swap(t_stack **stack, char x)
{
    long    aux1;
    long    aux2;

    if (*stack == NULL || (*stack)->next == NULL)
        ft_error("EMPTY STACK");
        ///liada
    aux1 = (*stack)->nbr;
    aux2 = (*stack)->next->nbr;
    (*stack)->nbr = aux2;
    *stack = (*stack)->next;
    (*stack)->nbr = aux1;
    if (x == 'a')
        write(0, "sa\n", 3);
    else if (x == 'b')
        write(0, "sb\n", 3);
    else
        ft_error("BAD STACK");
}

void ft_doubleswap(t_stack **stacka, t_stack **stackb)
{
    ft_swap(stacka, 'a');
    ft_swap(stackb, 'b');
    write(0, "ss\n", 3);
}
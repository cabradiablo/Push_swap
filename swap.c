#include "pushswap.h"

void    ft_swap(t_stack **stack, char x)
{
    long    aux1;
    long    aux2;

    if (*stack == NULL || (*stack)->next == NULL)
        ft_error();
    aux1 = (*stack)->nbr;
    stack = (*stack)->next;
    aux2 = (*stack)->nbr;
    (*stack)->nbr = aux1;
    *stack = (*stack)->prev;
    (*stack)->nbr = aux2;
    if (x == 'a')
        write(0, "sa", 2);
    else if (x == 'b')
        write(0, "sb", 2);
    else
        ft_error();
}

void ft_doubleswap(t_stack **stacka, t_stack **stackb)
{
    ft_swap(stacka, 'a');
    ft_swap(stackb, 'b');
    write(0, "ss", 2);
}
#include "pushswap.h"

void ft_rotate(t_stack **stack, char x)
{
    t_stack *last;
    
    if (*stack == NULL || (*stack)->next == NULL)
        ft_error("EMPTY STACK");
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = *stack; 
    (*stack)->prev = last; 
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
    if (x == 'a')
        write(0, "ra\n", 3);
    else if (x == 'b')
        write(0, "rb\n", 3);
    else
        ft_error("BAD STACK");
}


void    ft_reverse_rotate(t_stack **stack, char x)
{
    t_stack *aux;
    
    if (*stack == NULL || (*stack)->next == NULL)
        ft_error("EMPTY STACK");
    aux = *stack;
    while (aux->next != NULL)
        aux = aux->next;
    aux->prev->next = NULL;
    aux->prev = NULL;
    (*stack)->prev = aux;
    aux->next = *stack;
    *stack = aux;
    if (x == 'a')
        write(0, "ra\n", 3);
    else
        ft_error("BAD STACK");
}

void ft_doublerotate(t_stack **stacka, t_stack **stackb)
{
    ft_rotate(stacka, 'a');
    ft_rotate(stackb, 'b');
    write(0, "rr\n", 3);
}
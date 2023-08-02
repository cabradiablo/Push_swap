#include "pushswap.h"

void    ft_rotate(t_stack **stack, char x)
{
    t_stack *aux;
    
    if (*stack == NULL || (*stack)->next == NULL)
        ft_error();
    aux = (*stack);
    (*stack) = (*stack)->next;
    free((*stack)->prev);
    (*stack)->prev = NULL;
    while ((*stack)->next != NULL) 
        (*stack) = (*stack)->next;
    (*stack)->next = aux;
    aux->prev = (*stack);
    aux->next = NULL;
    if (x = 'a')
        write(0, "ra", 2);
    else if (x = 'b')
        write(0, "rb", 2);
    else
        ft_error("BAD STACK");
}
void    ft_reverse_rotate(t_stack **stack, char x)
{
    t_stack *aux;
    
    if (*stack == NULL || (*stack)->next == NULL)
        ft_error();
    while ((*stack)->next != NULL)
        (*stack) = (*stack)->next;   
    aux = (*stack);
    (*stack) = (*stack)->prev;
    free((*stack)->next);
    (*stack)->next = NULL;
    while ((*stack)->prev != NULL)
        (*stack) = (*stack)->prev;
    (*stack)->prev = aux;
    aux->next = (*stack);
    aux->prev = NULL;
    if (x = 'a')
        write(0, "ra", 2);
    else
        ft_error("BAD STACK");
}

void ft_doublerotate(t_stack **stacka, t_stack **stackb)
{
    ft_rotate(stacka, 'a');
    ft_rotate(stackb, 'b');
    write(0, "rr", 2);
}
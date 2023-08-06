#include "pushswap.h"

void ft_rotate(t_stack **stack, char x)
{
    t_stack *aux;
    
    if (*stack == NULL || (*stack)->next == NULL)
        ft_error("ERROR: EMPTY STACK\n");
    aux = *stack;
    while (aux->next)
        aux = aux->next;
    if (aux->prev)
        aux->prev->next = NULL;
    aux->next = *stack;
    (*stack)->prev = aux;
    aux->prev = NULL;
    *stack = aux;
    if (x == 'a')
        write(1, "ra\n", 3);
    else if (x == 'b')
        write(1, "rb\n", 3);
    else if (x =='r')
        return ;
    else
        ft_error("ERROR: BAD STACK\n");
}
void    ft_reverse_rotate(t_stack **stack, char x)
{
    t_stack *aux;
    
    if (*stack == NULL || (*stack)->next == NULL)
        ft_error("ERROR: EMPTY STACK\n");
    aux = *stack;
    while (aux->next != NULL)
        aux = aux->next;
    if (aux->prev)
        aux->prev->next = NULL;
    aux->prev = NULL;
    (*stack)->prev = aux;
    aux->next = *stack;
    *stack = aux;
    if (x == 'a')
        write(1, "ra\n", 3);
    else if (x == 'r')
        return ;
    else
        ft_error("ERROR: BAD STACK\n");
}

void ft_doublerotate(t_stack **stacka, t_stack **stackb)
{
    ft_rotate(stacka, 'a');
    ft_rotate(stackb, 'b');
    write(1, "rr\n", 3);
}
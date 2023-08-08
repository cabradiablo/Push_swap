#include "pushswap.h"


void ft_pushtob(t_stack **stack_a, t_stack **stack_b) {
    
    t_stack *aux;
    
    if (*stack_a == NULL)
        ft_error("ERROR: EMPTY STACKaaaa\n");
    aux = *stack_a;
    *stack_a = (*stack_a)->next;
    if (*stack_a != NULL)
        (*stack_a)->prev = NULL;
    aux->next = *stack_b;
    aux->prev = NULL;
    if (*stack_b != NULL)
        (*stack_b)->prev = aux;
    *stack_b = aux;
    write(1, "pb\n", 3);
}

void ft_pushtoa(t_stack **stack_a, t_stack **stack_b) 
{
    t_stack *aux;

    if (*stack_b == NULL)
        ft_error("ERROR: EMPTY STACK\bbbbbn");
    aux = *stack_b;
    *stack_b = (*stack_b)->next;
    if (*stack_b != NULL)
        (*stack_b)->prev = NULL;
    aux->next = *stack_a;
    aux->prev = NULL;
    if (*stack_a != NULL)
        (*stack_a)->prev = aux;
    *stack_a = aux;
    write(1, "pa\n", 3);
}
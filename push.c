#include "pushswap.h"

void ft_pushtob(t_stack **stacka, t_stack **stackb)
{
    t_stack *aux;
    
    if (*stacka == NULL || *stackb == NULL)
        ft_error("ERROR: EMPTY STACK\n");
    aux = (t_stack *)malloc(sizeof(t_stack));
    if (aux == NULL)
        return;
    aux->nbr = (*stacka)->nbr;
    aux->next = *stackb;
    aux->prev = NULL;
    (*stackb)->prev = aux;
    (*stacka) = (*stacka)->next;
    free((*stacka)->prev);
    (*stacka)->prev = NULL;
    write(0, "pb\n", 3);
}

void ft_pushtoa(t_stack **stacka, t_stack **stackb)
{
    t_stack *aux;
    
    if (*stacka == NULL || *stackb == NULL)
        ft_error("ERROR: EMPTY STACK\n");
    aux = (t_stack *)malloc(sizeof(t_stack));
    if (aux == NULL)
        return;
    aux->nbr = (*stackb)->nbr;
    aux->next = *stacka;
    aux->prev = NULL;
    (*stacka)->prev = aux;
    (*stackb) = (*stackb)->next;
    free((*stacka)->prev);
    (*stackb)->prev = NULL;
    write(0, "pa\n", 3);
}
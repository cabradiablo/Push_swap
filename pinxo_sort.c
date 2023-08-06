#include "pushswap.h"

int is_sorted(t_stack *stack)
{
    long    i;

    i = 0;
    if (!stack)
        return (1);
    while (stack)
    {
        i = stack->nbr;
        stack = stack->next;
        if (i > stack->nbr)
            return (0);
    }
    return (1);
}
long    weight_stack_a(t_stack  **stack_a)
{
    t_stack *aux;
    long    weight;
    long    total_weight;
    long    i;
    long    stack_size;

    weight = 0;
    total_weight = 0;
    i = 1;
    aux = *stack_a;
    stack_size = ft_stacksize(aux);
    while (aux)
    {
        weight = aux->index - i;
        if ((ft_absolute_value(weight) > stack_size / 2) && (weight < 0))
            weight = i - aux->index;
        if ((ft_absolute_value(weight) > stack_size / 2) && (weight > 0))
            weight = weight - stack_size;
        if ((ft_absolute_value(weight) > stack_size / 2) && (weight < 0))
            weight = weight + stack_size;
        printf("objetivo:%li----indice:%li---pasos:%li\n", aux->index, i, weight);
        aux = aux->next;
        i++;
        total_weight += ft_absolute_value(weight);
    }
    printf("weight------------->%li\n\n", total_weight);
    return (weight);
}

/*
long    weight_calculator(t_stack **stack_a, t_stack **stack_b)
{
    long    weight;
    long    i;
    long    stack_size;
    t_stack *aux;
    (void)stack_b;

    weight = 0;
    i = 0;
    aux = *stack_a;
    stack_size = ft_stacksize(aux);
    while (aux)
    {
        if (i > stack_size / 2)
            i = stack_size - i;
        weight += ft_absolute_value(i - aux->index);
        aux = aux->next;
        i++;
    }
    stack_size = ft_stacksize(&stack_b);
    while (stack_b)
    {
        if (i > stack_size / 2)
            i = stack_size - i;
        weight += i + (*stack_b)->index + 1;
        stack_b = (*stack_b)->next;
        i++;
    }

    printf("weight------------->%li\n\n", weight);
    return (weight);
}
*/
/*
void    ft_algorithm(t_stack **stack_a)
{
    t_list  *stack_b;

    weight_calculator(&stack_a, &stack_b);
}
*/
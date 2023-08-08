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
        write(1, "rra\n", 3);
    else if (x == 'b')
        write(1, "rrb\n", 3);
    else if (x == 'r')
        return ;
    else
        ft_error("ERROR: BAD STACK\n");
}

void ft_doublerotate(t_stack **stack_a, t_stack **stack_b)
{
    ft_rotate(stack_a, 'r');
    ft_rotate(stack_b, 'r');
    write(1, "rr\n", 3);
}

void ft_reverse_doublerotate(t_stack **stack_a, t_stack **stack_b)
{
    ft_reverse_rotate(stack_a, 'r');
    ft_reverse_rotate(stack_b, 'r');
    write(1, "rrr\n", 4);
}


void    loop_rotate(t_stack **stack_a, t_stack **stack_b, int i, char *order)
{
    while (i)
	{
		if (i > 0)
		{
            if(ft_strncmp("a", order, 2) == 1)
			    ft_rotate(stack_a, 'a');
            if(ft_strncmp("b", order, 2) == 1)
			    ft_rotate(stack_b, 'b');
			i--;
		}
		if (i < 0)
		{
            if(ft_strncmp("a", order, 2) == 1)
			    ft_reverse_rotate(stack_a, 'a');
            if(ft_strncmp("b", order, 2) == 1)
                ft_reverse_rotate(stack_b, 'b');
			i++;
		}
	}
}

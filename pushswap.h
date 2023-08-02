#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

void    ft_rotate(t_stack **stack, char x);
void    ft_reverse_rotate(t_stack **stack, char x);
void    ft_doublerotate(t_stack **stack_a, t_stack **stack_b);
void    ft_swap(t_stack **stack, char x);
void    ft_doubleswap(t_stack **stack_a, t_stack **stack_b);
void    ft_pushtoa(t_stack **stack_a, t_stack **stackb_);
void    ft_pushtob(t_stack **stack_a, t_stack **stack_b);

void	stack_a_maker(char **nbr, t_stack **stack_a);
void    valid_nbr(char  *nbr);
void    list_getter_zsh(int argc, char **argv, t_stack *stack_a);
void    list_getter_bash(char *argv, t_stack *stack_a);
void    ft_parser(int argc, char **argv, t_stack *stack_a);

#endif
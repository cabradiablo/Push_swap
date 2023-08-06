#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "./Libft/libft.h"

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
void    ft_pushtoa(t_stack **stack_a, t_stack **stack_b);
void    ft_pushtob(t_stack **stack_a, t_stack **stack_b);

void    card_to_ord(t_stack **stack_a);
t_stack *stack_a_maker(char **nbr);
t_stack	*ft_parser(int argc, char **argv);

void	ft_error(char *msg);

void    valid_int_checker(char  *nbr);
void    duplicate_checker(char **nbr);
void    ft_checker(char **nbr);

void 	print_list(t_stack *stack);
void	free_stack(t_stack **stack);
long	ft_stacksize(t_stack *stack);
char    **ft_argv_cleaner(int argc, char **argv);
void 	ft_stackadd_back(t_stack **stack, t_stack *node);

int 	is_sorted(t_stack *stack);
long    weight_stack_a(t_stack  **stack_a);
long    weight_calculator(t_stack **stack_a, t_stack **stack_b);
void    ft_algorithm(t_stack **stack_a);

#endif
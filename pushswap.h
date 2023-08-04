#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
void    ft_pushtoa(t_stack **stack_a, t_stack **stackb_);
void    ft_pushtob(t_stack **stack_a, t_stack **stack_b);

void	stack_a_maker(char **nbr);
void    list_getter_bash(int argc, char **argv);
void    list_getter_zsh(char *argv);
void    ft_parser(int argc, char **argv);

void	ft_error(char *msg);

void    valid_int_checker(char  *nbr);
void    duplicate_checker(char **nbr);
void    ft_checker(char *nbr);

void print_list(t_stack *stack);
void ft_stackadd_back(t_stack **stack, t_stack *node);

#endif
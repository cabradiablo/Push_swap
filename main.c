#include "pushswap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;

    stack_a = ft_parser(argc, argv);
    //ft_algorith(&stack_a);
    print_list(stack_a);
    return (EXIT_SUCCESS);
}
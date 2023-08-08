#include "pushswap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    stack_a = ft_parser(argc, argv);
    sort(&stack_a, &stack_b);
    print_stack(stack_a);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (EXIT_SUCCESS);
}

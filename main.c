#include "pushswap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    (void)stack_b;
    stack_a = ft_parser(argc, argv);
    weight_stack_a(&stack_a);
    //weight_calculator(&stack_a, &stack_b);
    //ft_algorithm(&stack_a);
    free_stack(&stack_a);
    return (EXIT_SUCCESS);
}
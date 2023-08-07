#include "pushswap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    (void)stack_b;
    stack_a = ft_parser(argc, argv);
    sort(&stack_a, &stack_b);
    //weight_calculator(&stack_a, &stack_b);
    //ft_algorithm(&stack_a);
    print_stack(stack_a);
    printf("\n\n");
    print_stack(stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (EXIT_SUCCESS);
}
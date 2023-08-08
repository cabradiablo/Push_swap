#include "pushswap.h"

void	do_move(t_stack **stack_a, t_stack **stack_b, int dst_a, int dst_b)
{
	if (dst_a < 0 && dst_b < 0)
	{
		while (dst_a < 0 && dst_b < 0)
		{
			dst_a++;
			dst_b++;
			ft_reverse_doublerotate(stack_a, stack_b);
		}
	}
	else if (dst_a > 0 && dst_b > 0)
	{
		while (dst_a > 0 && dst_b > 0)
		{
			dst_a--;
			dst_b--;
			ft_doublerotate(stack_a, stack_b);
		}
	}
	loop_rotate(stack_a, stack_b, dst_a, "a");
	loop_rotate(stack_a, stack_b, dst_b, "b");
	ft_pushtoa(stack_a, stack_b);
}

void	get_dst(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stacksize(tmp_a);
	size_b = ft_stacksize(tmp_b);
	while (tmp_b)
	{
		tmp_b->dst_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->dst_b = (size_b - tmp_b->pos) * -1;
		tmp_b->dst_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->dst_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		dst_a;
	int		dst_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_absolute_value(tmp->dst_a) + ft_absolute_value(tmp->dst_b) < ft_absolute_value(cheapest))
		{
			cheapest = ft_absolute_value(tmp->dst_b) + ft_absolute_value(tmp->dst_a);
			dst_a = tmp->dst_a;
			dst_b = tmp->dst_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, dst_a, dst_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:37:41 by itahri            #+#    #+#             */
/*   Updated: 2024/06/24 18:18:52 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa_o_ra(t_stack *stack_a)
{
	t_element	*first;
	t_element	*second;
	t_element	*third;

	first = stack_a->first;
	second = first->next;
	third = second->next;
	if (first->len > second->len && second->len < third->len
		&& first->len > third->len)
		rotate_a(stack_a);
	else if (first->len > second->len && second->len < third->len
		&& first->len < third->len)
		swap_a(stack_a);
}

int	for_three(t_stack *stack_a)
{
	t_element	*first;
	t_element	*second;
	t_element	*third;

	first = stack_a->first;
	second = first->next;
	third = second->next;
	if (!third)
	{
		if (!is_sorted(stack_a))
			rotate_a(stack_a);
	}
	else if (first->len > second->len && second->len > third->len)
		(swap_a(stack_a), reverse_rotate_a(stack_a));
	else if (first->len < second->len && second->len > third->len)
	{
		reverse_rotate_a(stack_a);
		if (!is_sorted(stack_a))
			swap_a(stack_a);
	}
	else
		sa_o_ra(stack_a);
	return (0);
}

int	sequencial_sort(t_stack *s_a, t_stack *s_b)
{
	int	init_len;

	init_len = stack_len(s_a);
	while (stack_len(s_a) != 3)
	{
		if (s_a->first->len == 1)
			push_b(s_b, s_a);
		else if (s_a->first->len == 2 && init_len == 5)
			push_b(s_b, s_a);
		else
			rotate_a(s_a);
	}
	for_three(s_a);
	if (init_len == 5)
	{
		if (s_b->first->len > s_b->first->next->len)
			(push_a(s_a, s_b), push_a(s_a, s_b));
		else
			(rotate_b(s_b), push_a(s_a, s_b), push_a(s_a, s_b));
	}
	else
		push_a(s_a, s_b);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = manage_args(argv, argc);
	stack_b = init_stack();
	if (!stack_b)
		return (free_stack(stack_a), 1);
	if (stack_len(stack_a) <= 3)
		return (for_three(stack_a));
	else if (stack_len(stack_a) <= 5)
		return (sequencial_sort(stack_a, stack_b));
	radix(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

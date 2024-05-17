/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:22:45 by itahri            #+#    #+#             */
/*   Updated: 2024/05/17 15:48:19 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	larger_to_top(t_stack *stacks, int larger)
{
	t_element	*current;

	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	if (is_top_or_bottom(stacks, larger) ==  1)
	{
		while (stacks->first->len != larger)
		{
			current = current->next;
			rotate_b(stacks);
		}
	}
	else
	{
		while (stacks->first->len != larger)
		{
			current = current->next;
			reverse_rotate_b(stacks);
		}
	}
}

void	sorting_by_compare_b(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*current;

	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	current = stack_b->first;
	while (stack_len(stack_b) > 0)
	{
		if (is_the_biggest(stack_b, current->len) || stack_a->first->len > current->len)
		{
			if (current->next)
				current = current->next;
			else
				current = stack_b->first;
			push_a(stack_a, stack_b);
		}
		else
		{
			if (current->next)
				current = current->next;
			else
				current = stack_b->first;
			larger_to_top(stack_b, find_the_bigger(stack_b));
		}
	}
}
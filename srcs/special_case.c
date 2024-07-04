/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:52:35 by itahri            #+#    #+#             */
/*   Updated: 2024/07/04 21:01:13 by itahri           ###   ########.fr       */
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

int	is_the_smallest(t_stack *stacks, int len)
{
	t_element	*current;

	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	while (current)
	{
		if (len > current->len)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_the_smallest_minus(t_stack *stacks, int len)
{
	t_element	*current;

	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	while (current)
	{
		if (current->len < 0)
		{
			if (-len < -current->len)
				return (0);
		}
		current = current->next;
	}
	return (1);
}

int	is_the_smallest_pos(t_stack *stacks, int len)
{
	t_element	*current;

	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	while (current)
	{
		if (len > current->len && current->len >= 0)
			return (0);
		current = current->next;
	}
	return (1);
}

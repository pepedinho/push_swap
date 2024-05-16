/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:23:49 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 15:13:40 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_top_or_bottom(t_stack *stacks, int to_find)
{
	t_element	*current;
	int			i;
	int			stack_median_len;

	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	i = 0;
	stack_median_len = stack_len(stacks) / 2;
	while (i <= stack_median_len)
	{
		if (current->len == to_find)
			return (1);
		current = current->next;
		i++;
	}
	
	return (-1);	
}

int	find_the_bigger(t_stack *stacks)
{
	t_element	*current;
	int			larger;

	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	larger = current->len;
	while (current)
	{
		if (current->len > larger)
			larger = current->len;
		current = current->next;
	}
	return (larger);
}

int	is_the_biggest(t_stack *stacks, int	len)
{
	t_element	*current;

	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	while (current)
	{
		if (len < current->len)
			return (0);
		current = current->next;
	}
	return (1);
}

void	swap_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*current;

	if (!stack_a || ! stack_b)
		exit(EXIT_FAILURE);
	current = stack_a->first;
	while (current)
	{
		current = current->next;
		push_b(stack_b, stack_a);
	}
}

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
		if (is_the_biggest(stack_b, current->len))
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:22:45 by itahri            #+#    #+#             */
/*   Updated: 2024/05/17 21:28:27 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	abso(int nb)
{
	if (nb == 0)
		return (1000);
	else if (nb < 0)
		return -nb;
	else
		return nb;
}

int	stack_len_n(t_stack *stacks, t_element *n)
{
	t_element	*current;
	int			i;

	i = 0;
	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	while (current != n && current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	find_next(t_stack *stack_a, int find_next)
{
	t_element	*current;
	t_element	*index;
	int			elem_len;
	
	if (!stack_a)
		exit(EXIT_FAILURE);
	current = stack_a->first;
	elem_len = current->len;
	while (current->next)
	{
		index = current;
		while (index->next)
		{
			if (abso(elem_len - find_next) > abso(index->next->len - find_next))
				elem_len = index->next->len;
			index = index->next;
		}
		current = current->next;
	}
	return (elem_len);
}

void	larger_to_top(t_stack *stacks, int larger, int cas)
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
			if (cas == 1)
				rotate_b(stacks);
			else
				rotate_a(stacks);
		}
	}
	else
	{
		while (stacks->first->len != larger)
		{
			current = current->next;
			if (cas == 1)
				reverse_rotate_b(stacks);
			else
				reverse_rotate_a(stacks);
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
			// larger_to_top(stack_a, find_next(stack_a, stack_b->first->len), 2);
			larger_to_top(stack_b, find_the_bigger(stack_b), 1);
		} 
	}
}

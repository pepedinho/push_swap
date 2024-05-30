/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:28:44 by itahri            #+#    #+#             */
/*   Updated: 2024/05/30 12:49:46 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	is_sorted(t_stack *stacks)
{
	t_element	*current;

	current = stacks->first;
	while (current)
	{
		if (current->next && (current->next->len < current->len))
			return (0);
		current = current->next;
	}
	return (1);
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->first)
		push_a(stack_a, stack_b);
}

void	remix(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	index;
	int	stack_size;

	index = 0;
	stack_size = stack_len(stack_b);
	if (is_sorted(stack_a))
	{
		b_to_a(stack_a, stack_b);
		return ;
	}
	while (index < stack_size)
	{
		if ((stack_b->first->len >> (i)) & 1)
			push_a(stack_a, stack_b);
		else
			rotate_b(stack_b);
		index++;
	}
}

int	binary_len(int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 2;
		i++;
	}
	return (i);
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int			reference_len;
	int			i;
	int			j;
	int			act_len;
	int			stack_size;

	reference_len = binary_len(find_the_bigger(stack_a));
	i = 0;
	while (i < reference_len)
	{
		j = 0;
		stack_size = stack_len(stack_a);
		while (j < stack_size && !is_sorted(stack_a))
		{
			act_len = stack_a->first->len;
			if ((act_len >> i) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_b, stack_a);
			j++;
		}
		if (i++ < reference_len - 1)
			remix(stack_a, stack_b, i);
	}
	b_to_a(stack_a, stack_b);
}

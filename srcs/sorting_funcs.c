/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:23:49 by itahri            #+#    #+#             */
/*   Updated: 2024/05/30 12:40:16 by itahri           ###   ########.fr       */
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

int	is_the_biggest(t_stack *stacks, int len)
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

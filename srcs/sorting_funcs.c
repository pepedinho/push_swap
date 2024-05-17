/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:23:49 by itahri            #+#    #+#             */
/*   Updated: 2024/05/17 15:24:39 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	find_median(t_stack *stacks)
{
	t_element	*current;
	int			*tab;
	int			i;
	int			j;
	int			temp;

	if (!stacks)
		exit(EXIT_FAILURE);	
	tab = malloc(sizeof(int) * stack_len(stacks));
	if (!tab)
		exit(EXIT_FAILURE);
	current = stacks->first;
	i = 0;
	while (current)
	{
		tab[i] = current->len;
		current = current->next;
		i++;
	}
	i = 0;
	while (i < stack_len(stacks) - 1)
	{
		j = 0;
		while (j < stack_len(stacks) - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return(tab[stack_len(stacks) / 2]);
}

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
	int			median;


	if (!stack_a || ! stack_b)
		exit(EXIT_FAILURE);
	median = find_median(stack_a);
	current = stack_a->first;
	while (current)
	{
		if (is_the_biggest(stack_a, current->len) && stack_len(stack_a) > 1)
		{
			current = current->next;
			rotate_a(stack_a);
		}
		else if (stack_len(stack_a) > 1)
		{
			current = current->next;
			push_b(stack_b, stack_a);
			if (stack_b->first->len < median)
				rotate_b(stack_b);
		}
		else
			current = current->next;
	}
    sorting_by_compare_b(stack_a, stack_b);
}

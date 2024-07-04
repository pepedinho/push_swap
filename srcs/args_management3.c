/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_managements3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:07:25 by itahri            #+#    #+#             */
/*   Updated: 2024/07/04 21:10:44 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_the_smallest_pos(t_stack *stacks)
{
	t_element	*current;

	current = stacks->first;
	while (current)
	{
		if (current->len >= 0 && is_the_smallest_pos(stacks, current->len))
			return (current->len);
		current = current->next;
	}
	return (-10);
}

void	step_up_all(t_stack *stacks)
{
	t_element	*current;

	current = stacks->first;
	while (current)
	{
		current->len++;
		current = current->next;
	}
}

int	minus_elem_cnt(t_stack *stacks)
{
	t_element	*current;
	int			cnt;

	cnt = 0;
	current = stacks->first;
	while (current)
	{
		if (current->len < 0)
			cnt++;
		current = current->next;
	}
	return (cnt);
}

int	abso(int nbr, t_stack *stacks)
{
	static int	cnt;
	static int	bol;
	int			i;

	i = 0;
	if (!bol)
	{
		bol = minus_elem_cnt(stacks);
		while (i++ < bol)
			step_up_all(stacks);
	}
	if (nbr < 0)
	{
		if (is_the_smallest_minus(stacks, nbr) && !cnt)
		{
			nbr = 0;
			cnt++;
		}
		else if (is_the_smallest_minus(stacks, nbr) && cnt)
		{
			nbr = find_the_smallest_pos(stacks) + cnt;
			cnt++;
		}
	}
	return (nbr);
}

void	abso_loop(t_stack *stacks)
{
	t_element	*current;

	while (minus_elem_cnt(stacks))
	{
		current = stacks->first;
		while (current)
		{
			if (current->len < 0)
				current->len = abso(current->len, stacks);
			current = current->next;
		}
	}
}

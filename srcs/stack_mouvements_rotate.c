/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvements_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:34:28 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 14:08:10 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack *stacks)
{
	t_element	*current;

	if (!stacks)
		exit(EXIT_FAILURE);
	else if (stack_len(stacks) <= 1)
		return ;
	current = stacks->first;
	while (current->next)
	{
		current = current->next;
	}
	current->next = stacks->first;
	stacks->first = stacks->first->next;
	current->next->next = NULL;
}

void	rotate_a(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

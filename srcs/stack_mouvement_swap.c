/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:43:15 by itahri            #+#    #+#             */
/*   Updated: 2024/06/28 17:53:11 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	swap(t_stack *stacks)
{
	t_element	*first;
	t_element	*second;

	if (!stacks || (stack_len(stacks) <= 1))
		exit(EXIT_FAILURE);
	first = malloc(sizeof(*first));
	second = malloc(sizeof(*second));
	if (!first || !second)
		exit(EXIT_FAILURE);
	first->len = stacks->first->len;
	unstack(stacks);
	second->len = stacks->first->len;
	unstack(stacks);
	if (stack(stacks, first->len))
		return (free(first), free(second), 0);
	if (stack(stacks, second->len))
		return (0);
	free(first);
	free(second);
	return (1);
}

int	swap_a(t_stack *stack_a)
{
	if (swap(stack_a))
		return (0);
	ft_printf("sa\n");
	return (1);
}

int	swap_b(t_stack *stack_b)
{
	if (swap(stack_b))
		return (0);
	ft_printf("sb\n");
	return (1);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

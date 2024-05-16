/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:43:15 by itahri            #+#    #+#             */
/*   Updated: 2024/05/15 18:08:13 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack *stacks)
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
	stack(stacks, first->len);
	stack(stacks, second->len);
	free(first);
	free(second);
}


void	swap_a(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvements_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:59:20 by itahri            #+#    #+#             */
/*   Updated: 2024/05/29 18:47:10 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack *stack_a, t_stack *stack_b)
{
	int	len;
	
	len = stack_b->first->len;
	unstack(stack_b);
	if (!stack(stack_a, len))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_FAILURE);
	}
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	else if ((stack_len(stack_b) < 1))
		return ;
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	push_b(t_stack *stack_b, t_stack *stack_a)
{
	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	else if ((stack_len(stack_a) < 1))
		return ;
	push(stack_b, stack_a);
	ft_printf("pb\n");
} 

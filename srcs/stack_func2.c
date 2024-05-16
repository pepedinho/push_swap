/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:55:41 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 11:15:42 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_func.h"

int	stack_len(t_stack *stack)
{
	t_element	*current;
	int			i;

	i = 0;
	if (!stack)
		exit(EXIT_FAILURE);
	current = stack->first;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	display_stack_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_element	*current_a;
	t_element	*current_b;

	if (!stack_a || !stack_b)
		exit(EXIT_FAILURE);
	current_a = stack_a->first;
	current_b = stack_b->first;
	ft_printf("stack a:			stack b:\n");
	while (current_a || current_b)
	{
		if (current_a && current_b)
			ft_printf("[%d]				[%d]", current_a->len, current_b->len);
		else if (current_a && !current_b)
			ft_printf("[%d]", current_a->len);
		else if (current_b && !current_a)
			ft_printf("					[%d]", current_b->len);
		ft_printf("\n");
		if (current_a)
			current_a = current_a->next;
		if (current_b)
			current_b = current_b->next;
	}
	ft_printf("\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:52:27 by itahri            #+#    #+#             */
/*   Updated: 2024/05/29 18:53:30 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_func.h"

t_stack	*init_stack()
{
	t_stack		*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	return (stack);
}

int	stack(t_stack *stack, int new_len)
{
	t_element	*new;

	if (!stack)
		return (0);
	new = malloc(sizeof(*new));
	if (!new)
			return (0);
	new->len = new_len;
	new->next = stack->first;
	stack->first = new;
	return (1);
}

int	unstack(t_stack *stack)
{
	int			stack_nb;
	t_element	*to_unstack;
	
	if (!stack)
		exit(EXIT_FAILURE);
	stack_nb = 0;
	to_unstack = stack->first;
	if (stack && stack->first)
	{
		stack_nb = to_unstack->len;
		stack->first = to_unstack->next;
		free(to_unstack);
	}
	return (stack_nb);
}

void	display_stack(t_stack *stack)
{
	t_element	*current;

	if (!stack)
		exit(EXIT_FAILURE);
	current = stack->first;
	while (current)
	{
		ft_printf("[%d]\n", current->len);
		current = current->next;
	}
	ft_printf("\n");
}

void	free_stack(t_stack *stack)
{
	t_element	*current;
	t_element	*next;

	if (!stack)
		exit(EXIT_FAILURE);
	current = stack->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

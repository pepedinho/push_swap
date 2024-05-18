/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:28:44 by itahri            #+#    #+#             */
/*   Updated: 2024/05/18 20:58:03 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static int	ft_strlen_free(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (free(str), i);
}

int	**sorting_tab(t_stack *stack_a)
{
	t_element	*current;
	int			**tab;
	char		*convert_elem;
	int			i;
	int			reference_len;
	int			j;
	
	if (!stack_a)
		exit(EXIT_FAILURE);
	tab = malloc(sizeof(int *) * stack_len(stack_a));
	if (!tab)
		exit(EXIT_FAILURE);
	i = 0;
	reference_len = ft_strlen_free(ft_convert_base(ft_itoa(find_the_bigger(stack_a)), "0123456789", "01"));
	while (i < stack_len(stack_a))
	{
		tab[i] = malloc(sizeof(int) * reference_len);
		if (!tab[i])
			exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	current = stack_a->first;
	while (current)
	{
		j = 0;
		reference_len = ft_strlen_free(ft_convert_base(ft_itoa(find_the_bigger(stack_a)), "0123456789", "01"));
		convert_elem = ft_convert_base(ft_itoa(current->len), "0123456789", "01");
		while (j < reference_len)
		{
			if (convert_elem[j])
			{
				if (convert_elem[j] == '0')
					tab[i][j] = 0;
				else
					tab[i][j] = 1;
			}
			else
				tab[i][j] = 0;
			j++;
		}
		i++;
		free(convert_elem);
		current = current->next;
	}
	return (tab);
}

void	remix(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	index;
	int	stack_size;

	index = 0;
	stack_size = stack_len(stack_b);
	while (index < stack_size)
	{
		if ((stack_b->first->len >> (i + 1)) & 1)
			push_a(stack_a, stack_b);
		else
			rotate_b(stack_b);
		index++;
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	
	while (stack_b->first)
		push_a(stack_a, stack_b);
}

int binary_len(int nb)
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
		while (j < stack_size)
		{
			act_len = stack_a->first->len;
			if ((act_len >> i) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_b, stack_a);
			j++;
		}
		if (i < reference_len - 1)
			remix(stack_a, stack_b, i);
		i++;
	}
	b_to_a(stack_a, stack_b);
}
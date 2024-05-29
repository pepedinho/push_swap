/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:59:58 by itahri            #+#    #+#             */
/*   Updated: 2024/05/29 14:06:35 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(int *tab1, int *tab2)
{
	int	buff;

	buff = *tab1;
	*tab1 = *tab2;
	*tab2 = buff;
}

static void  normalize_loop(t_stack *stacks, int *tab)
{
	int		  i;
	int		  j;
	int		  stacks_len;
	t_element *current;

	i = 0;
	current = stacks->first;
	stacks_len = stack_len(stacks);
	while (i < stacks_len)
	{
		if (dec_len(tab[i]) > dec_len(stacks_len))
		{
			j = 0;
			current = stacks->first;
			while (j < is_in_stack(stacks, tab[i]))
			{
				current = current->next;
				j++;
			}
			tab[i] = tab[i - 1] + 1;
			current->len = tab[i];
		}
		i++;
	}
	free (tab);
}

void  normalize_data_sort(t_stack *stacks)
{
	t_element *current;
	int		  *tab;
	int		  i;
	int		  j;
	int		  stacks_len;

	i = 0;
	current = stacks->first;
	tab = malloc(sizeof(int) * stack_len(stacks));
	if (!tab)
		exit(EXIT_FAILURE);
	while (current)
	{
		tab[i] = current->len;
		i++;
		current = current->next;
	}
	i = 0;
	stacks_len = stack_len(stacks);
	while (i < stacks_len)
	{
		j = 0;
		while (j < stacks_len - 1)
		{
			if (tab[j] > tab[j + 1])
				swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	normalize_loop(stacks, tab);
}

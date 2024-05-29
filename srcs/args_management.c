/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:45:36 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 17:09:30 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	check_repet(const char *argv[], int argc)
{
	int	i;
	int	j;
	int *tab;

	i = 1;
	tab = malloc(sizeof(int) * argc);
	if (!tab)
		exit(EXIT_FAILURE);
	while (i < argc)
	{
		j = 0;
		tab[i - 1] = ft_atoi(argv[i]);
		while (j < i - 1)
		{
			if (tab[j] == tab[i - 1])
				return 1;
			j++;
		}
		i++;
	}
	return (0);	
}

int	is_in_stack(t_stack *stacks, int to_find)
{
	t_element *current;
	int		  i;

	i = 0;
	current = stacks->first;
	while (current)
	{
		if (current->len ==  to_find)
			return (i);
		current = current->next;
		i++;
	}
	return (0);
}

void	swap(int *tab1, int *tab2)
{
	int	buff;

	buff = *tab1;
	*tab1 = *tab2;
	*tab2 = buff;
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
	i = 0;
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
}

t_stack	*manage_args(const char *argv[], int argc)
{
	int		i;
	t_stack	*stacks;

	stacks = init_stack();
	i = argc - 1;
	if (check_repet(argv, argc))
		exit(EXIT_FAILURE);
	while (i > 0)
	{
		stack(stacks, ft_atoi(argv[i]));
		i--;
	}
	normalize_data_sort(stacks);
	return (stacks);
}

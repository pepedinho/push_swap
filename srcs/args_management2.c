/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:59:58 by itahri            #+#    #+#             */
/*   Updated: 2024/07/04 19:24:21 by itahri           ###   ########.fr       */
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

int	abso(int nbr, t_stack *stacks)
{
	t_element	*current;

	if (nbr < 0)
	{
		nbr = -nbr;
		current = stacks->first;
		while (current)
		{
			if (current->len == nbr)
			{
				nbr = find_the_bigger(stacks) + 1;
				break ;
			}
			current = current->next;
		}
	}
	ft_printf("nbr : %d\n", nbr);
	return (nbr);
}

static void	normalize_loop(t_stack *stacks, int *tab)
{
	int			i;
	int			j;
	int			stacks_len;
	t_element	*current;

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
			if (i > 0)
				tab[i] = tab[i - 1] + 1;
			current->len = abso(tab[i], stacks);
		}
		i++;
	}
}

void	sorting_tab(int *tab, int stacks_len)
{
	int	i;
	int	j;

	i = 0;
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
}

void	normalize_data_sort(t_stack *stacks)
{
	t_element	*current;
	int			*tab;
	int			i;
	int			stacks_len;

	i = 0;
	if (!stacks)
		exit(EXIT_FAILURE);
	current = stacks->first;
	tab = malloc(sizeof(int) * stack_len(stacks));
	if (!tab)
	{
		free_stack(stacks);
		exit(EXIT_FAILURE);
	}
	while (current)
	{
		tab[i] = current->len;
		i++;
		current = current->next;
	}
	stacks_len = stack_len(stacks);
	sorting_tab(tab, stacks_len);
	(normalize_loop(stacks, tab), free(tab));
}

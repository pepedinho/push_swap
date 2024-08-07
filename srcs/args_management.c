/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:45:36 by itahri            #+#    #+#             */
/*   Updated: 2024/07/10 14:39:28 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_repet(const char *argv[], int argc)
{
	int	i;
	int	j;
	int	*tab;

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
				return (free(tab), ft_printf("Error\n"), 1);
			j++;
		}
		i++;
	}
	free(tab);
	return (0);
}

int	is_in_stack(t_stack *stacks, int to_find)
{
	t_element	*current;
	int			i;

	i = 0;
	current = stacks->first;
	while (current)
	{
		if (current->len == to_find)
			return (i);
		current = current->next;
		i++;
	}
	return (0);
}

int	check_validity(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		if (str[i] == ' ')
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		if (i > 0 && (str[i] == '-' || str[i] == '+'))
			(ft_printf("Error\n"), exit(EXIT_FAILURE));
		i++;
	}
	if (ft_atol(str) > 2147483647 || (ft_atol(str) < 0 && ft_atol(str)
			< -2147483648))
		(ft_printf("Error\n", ft_atol(str)), exit(EXIT_FAILURE));
	return (1);
}

void	check_args(const char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
		check_validity(argv[i++]);
}

t_stack	*manage_args(const char *argv[], int argc)
{
	int		i;
	t_stack	*stacks;

	check_args(argv, argc);
	if (check_repet(argv, argc))
		exit(EXIT_FAILURE);
	stacks = init_stack();
	i = argc - 1;
	while (i > 0)
	{
		stack(stacks, ft_atoi(argv[i]));
		i--;
	}
	normalize_data_sort(stacks);
	return (stacks);
}

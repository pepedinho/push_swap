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
	return (stacks);
}
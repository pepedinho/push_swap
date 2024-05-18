/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_all_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:38:03 by itahri            #+#    #+#             */
/*   Updated: 2024/05/18 17:46:20 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	sub_dec_nbr(int nbr, int i)
{
	int		result;
	char	*str_nbr;
	char	*buff;

	buff = ft_calloc(sizeof(char), 2);
	if (!buff)
		exit(EXIT_FAILURE);
	str_nbr = ft_itoa(nbr);
	buff[0] = str_nbr[i];
	result = ft_atoi(buff);
	return (free(str_nbr), free(buff), result);
}

int	**sorting_tab_all_star(t_stack *stack_a)
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
	reference_len = dec_len((find_the_bigger(stack_a)));
	while (i < stack_len(stack_a))
	{
		j = 0;
		tab[i] = malloc(sizeof(int) * reference_len);
		if (!tab[i])
			exit(EXIT_FAILURE);
		while (j < reference_len)
			tab[i][j++] = 0;
		i++;
	}
	i = 0;
	current = stack_a->first;
	while (current)
	{
		j = 0;
		reference_len = dec_len((find_the_bigger(stack_a)));
		convert_elem = ft_itoa(current->len);
		while (j < reference_len)
		{
			tab[i][reference_len - j] =  sub_dec_nbr(current->len, j);
			j++;
		}
		i++;
		free(convert_elem);
		current = current->next;
	}
	return (tab);
}

int	is_in(t_stack *stack_a, t_stack *stack_b)
{
	int	first_a;
	int	first_b;

	if (!stack_b->first)
		return -1;
	first_a = stack_a->first->len;
	first_b = stack_b->first->len;
	if (first_a - first_b == 0)
		return (1);
	else
		return (0);
}

void	to_find_elem(t_stack *stack_a, t_stack *stack_b, int sens)
{
	int	first_a;
	int	first_b;

	if (!stack_b->first)
		return ;
	first_a = stack_a->first->len;
	first_b = stack_b->first->len;
	if (first_a - first_b == sens)
		push_b(stack_b, stack_a);
	else
		rotate_a(stack_a);
}

void	remix_all_star(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->first)
		push_a(stack_a, stack_b);
}

void	radix_all_star(t_stack *stack_a, t_stack *stack_b)
{
	int			reference_len;
	int			i;
	int			j;
	int			**tab;
	int			act_len;
	int			stack_size;

	reference_len = dec_len(find_the_bigger(stack_a));
	i = 0;
	while (i < reference_len)
	{
		j = 0;
		tab = sorting_tab_all_star(stack_a);
		stack_size = stack_len(stack_a);
		while (j < stack_size)
		{
			act_len = stack_a->first->len;
			if (tab[j][i] == 0)
				push_b(stack_b, stack_a);
			else if (is_in(stack_a, stack_b) == 1)
				to_find_elem(stack_a, stack_b, 0);
			else if (is_in (stack_a, stack_b) == 0)
				to_find_elem(stack_a, stack_b, 1);
			j++;
		}
		remix_all_star(stack_a, stack_b);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:48:58 by itahri            #+#    #+#             */
/*   Updated: 2024/05/17 15:30:09 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_FUNC_H
# define SORTING_FUNC_H
# include "push_swap.h"

int		is_the_biggest(t_stack *stacks, int	len);
void	swap_stacks(t_stack *stack_a, t_stack *stack_b);
void	sorting_by_compare_b(t_stack *stack_a, t_stack *stack_b);
void	larger_to_top(t_stack *stacks, int larger);
int		is_top_or_bottom(t_stack *stacks, int to_find);
int		find_the_bigger(t_stack *stacks);

#endif
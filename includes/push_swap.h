/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:54:03 by itahri            #+#    #+#             */
/*   Updated: 2024/07/04 21:09:50 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "args_management.h"
# include "radix.h"
# include "sorting_func.h"
# include "stack_func.h"
# include "stack_mouvement.h"
# include "struct.h"

// special case
void	sa_o_ra(t_stack *stack_a);
int		for_three(t_stack *stack_a);
int		is_the_smallest(t_stack *stacks, int len);
int		is_the_smallest_pos(t_stack *stacks, int len);
int		is_the_smallest_minus(t_stack *stacks, int len);

// args_management3
int		find_the_smallest_pos(t_stack *stacks);
void	step_up_all(t_stack *stacks);
int		minus_elem_cnt(t_stack *stacks);
int		abso(int nbr, t_stack *stacks);
void	abso_loop(t_stack *stacks);

#endif

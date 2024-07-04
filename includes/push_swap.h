/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:54:03 by itahri            #+#    #+#             */
/*   Updated: 2024/07/04 18:54:47 by itahri           ###   ########.fr       */
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

#endif

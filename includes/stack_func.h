/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:53:05 by itahri            #+#    #+#             */
/*   Updated: 2024/05/30 12:45:53 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_FUNC_H
# define STACK_FUNC_H
# include "../libft/includes/libft.h"
# include "push_swap.h"
# include "struct.h"

t_stack	*init_stack(void);
void	display_stack(t_stack *stack);
void	display_stack_ab(t_stack *stack_a, t_stack *stack_b);
int		stack(t_stack *stack, int new_len);
int		unstack(t_stack *stack);
void	free_stack(t_stack *stack);

int		stack_len(t_stack *stack);

#endif

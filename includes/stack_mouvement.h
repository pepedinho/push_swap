/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mouvement.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:30:38 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 12:27:47 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MOUVEMENT_H
# define STACK_MOUVEMENT_H
# include "push_swap.h"
# include "struct.h"

//swap
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_ab(t_stack *stack_a, t_stack *stack_b);
//push
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_b, t_stack *stack_a);
//rotate
void	rotate_a(t_stack	*stack_a);
void	rotate_b(t_stack	*stack_b);
void	rotate_r(t_stack *stack_a, t_stack *stack_b);
//reverse rotate
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

#endif
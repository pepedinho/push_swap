/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:19:32 by itahri            #+#    #+#             */
/*   Updated: 2024/05/30 12:56:48 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_H
# define RADIX_H
# include "struct.h"

void	radix(t_stack *stack_a, t_stack *stack_b);
int	is_sorted(t_stack *stacks);

#endif

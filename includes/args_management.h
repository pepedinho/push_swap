/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_management.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:46:24 by itahri            #+#    #+#             */
/*   Updated: 2024/05/29 14:05:55 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_MANAGEMENT_H
# define ARGS_MANAGEMENT_H
# include "push_swap.h"

int	check_repet(const char *argv[], int argc);
t_stack	*manage_args(const char *argv[], int argc);
int	is_in_stack(t_stack *stacks, int to_find);

#endif

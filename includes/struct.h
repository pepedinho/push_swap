/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:02:56 by itahri            #+#    #+#             */
/*   Updated: 2024/05/30 12:55:09 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_element
{
	int					len;
	struct s_element	*next;
}						t_element;

typedef struct s_stack
{
	t_element			*first;
}						t_stack;

#endif
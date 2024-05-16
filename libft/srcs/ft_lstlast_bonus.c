/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:11:59 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 17:45:54 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst_testlast)
{
	if (!lst_testlast)
		return (NULL);
	while (lst_testlast->next)
	{
		lst_testlast = lst_testlast->next;
	}
	return (lst_testlast);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 00:42:43 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 17:45:54 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_toupper(int c)
{
	unsigned char	t_c;

	if (c == -1)
		return (c);
	t_c = (unsigned char)c;
	if (ft_isalpha(t_c))
	{
		if (t_c >= 'a' && t_c <= 'z')
			return (t_c - 32);
	}
	return (t_c);
}

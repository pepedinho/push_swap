/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:21:20 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 17:45:54 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size * nmeb);
	if (ptr == NULL)
		return (NULL);
	if (nmeb == 0 || size == 0)
		return (NULL);
	i = 0;
	while (i < nmeb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

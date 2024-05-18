/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:57:35 by itahri            #+#    #+#             */
/*   Updated: 2024/05/18 14:32:11 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_legal(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] <= 32 || base[i] > 126)
			return (0);
		else if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static char	*re_order(char *result)
{
	char	buff1;
	char	buff2;
	int		i;
	int		size;
	int		p_one;

	size = ft_strlen(result);
	i = 0;
	p_one = 1;
	if (result[i] == '-')
	{
		p_one = 0;
		i++;
	}
	else
		size --;
	while (i < (size + 1) / 2)
	{
		buff1 = result[i];
		buff2 = result[size - i];
		result[size - i] = buff1;
		result[i] = buff2;
		i++;
	}
	return (result);
}

static int	ft_dest_size(int nbr, char *base)
{
	int				i;
	unsigned int	temp;

	i = 1;
	temp = nbr;
	while (temp >= ft_strlen(base))
	{
		i++;
		temp = temp / ft_strlen(base);
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		in_int;
	char	*result;
	int		i;
	int		p_one;

	i = 0;
	p_one = 0;
	if (!is_legal(base_from) || !is_legal(base_to))
		return (NULL);
	in_int = ft_atoi_base(nbr, base_from);
	if (in_int < 0)
		p_one = 1;
	result = malloc(sizeof(char) * ft_dest_size(in_int, base_to) + p_one);
	if (result == NULL)
		return (NULL);
	result = ft_putnbr_base_str(in_int, base_to, result, i);
	result = re_order(result);
	free(nbr);
	return (result);
}

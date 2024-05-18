/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:30:03 by itahri            #+#    #+#             */
/*   Updated: 2024/05/18 14:31:56 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	is_in_base(char *base, char nb)
{
	int	i;
	int	is_in;

	i = 0;
	is_in = 0;
	while (base[i] != '\0')
	{
		if (base[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	is_negativ;

	i = 0;
	is_negativ = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i ++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negativ ++;
		i++;
	}	
	while (is_in_base(base, str[i]) >= 0)
	{
		result *= ft_strlen(base);
		result += is_in_base(base, str[i]);
		i ++;
	}
	if (is_negativ % 2 != 0)
		result = -result;
	return (result);
}

char	*ft_putnbr_base_str(int nbr, char *base, char *result, int i)
{
	char	char_nb;

	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
		i++;
	}
	if ((unsigned int)nbr >= ft_strlen(base))
	{
		result = ft_putnbr_base_str(nbr / ft_strlen(base), base, result, i + 1);
	}
	char_nb = base[nbr % ft_strlen(base)];
	result[i] = char_nb;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:59:19 by itahri            #+#    #+#             */
/*   Updated: 2024/05/16 17:46:51 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			i += check_flags(&format[i], args);
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (1);
}

// int main()
// {
// 	// int	e;
// 	// int	i;
// 	unsigned int j;
// 	int hex;
// 	char str[] = "je m'appel";
// 	// char car;

// 	// e = 010;
// 	// i = +214748364;
// 	j = 214748348;
// 	hex = 214748364;
// 	// car = 't';
// 	// Utilisation de printf
// 	printf("original :\n");
// 	// printf("Variable 1 : %s\n", str);
// 	// printf("Variable 2 : %d\n", i);
// 	// printf("Variable 3 : %i\n", e);
// 	// printf("Variable 4 : %c\n", car);
// 	// printf("Variable 5 : %u\n", j);
// 	// printf("Variable 6 : %x\n", hex);
// 	// printf("Variable 6 Maj : %X%%\n", hex);
// 	// printf("Address de (i) : %p\n", &i);
// 	printf("Bonus 0   (i) : %010i\n", 10);
// 	printf("Bonus 0   (d) : %09d\n", -10);
// 	printf("Bonus 0   (u) : %010u\n", j);
// 	printf("Bonus 0   (x) : %010x\n", hex);
// 	printf("Bonus 0   (X) : %010X\n", hex);
// 	printf("Bonus +       : %+d\n", 1000000);
// 	printf("Bonus +       : %-d\n", 1000000);
// 	printf("Bonus #   (x) : %#x\n", hex);
// 	printf("Bonus ' ' (d) : % d\n", -15425);
// 	printf("Bonus ' ' (i) : % i\n", -15425);
// 	printf("Bonus def (s) : |%10s|\n", str);
// 	printf("Bonus def (d) : |%10d|\n", 15425);
// 	printf("Bonus def (i) : |%10i|\n", 15425);
// 	printf("Bonus def (x) : |%10x|\n", 15425);
// 	printf("Bonus -   (s) : |%-10s|\n", str);
// 	printf("Bonus -   (d) : |%-10d|\n", 15425);
// 	printf("Bonus -   (i) : |%-10i|\n", 15425);
// 	printf("Bonus -   (x) : |%-10x|\n", 15425);

// ft_printf("-------------------------------\n");
// 	// Utilisation de ft_printf
// 	ft_printf("ft :\n");
// 	// ft_printf("Variable 1 : %s\n", str);
// 	// ft_printf("Variable 2 : %d\n", i);
// 	// ft_printf("Variable 3 : %i\n", e);
// 	// ft_printf("Variable 4 : %c\n", car);
// 	// ft_printf("Variable 5 : %u\n", j);
// 	// ft_printf("Variable 6 : %x\n", hex);
// 	// ft_printf("Variable 6 Maj : %X%%\n", hex);
// 	// ft_printf("Address de (i) : %p\n", &i);
// 	ft_printf("Bonus 0   (i) : %010i\n", 10);
// 	ft_printf("Bonus 0   (d) : %09d\n", -10);
// 	ft_printf("Bonus 0   (u) : %010u\n", j);
// 	ft_printf("Bonus 0   (x) : %010x\n", hex);
// 	ft_printf("Bonus 0   (X) : %010X\n", hex);
// 	ft_printf("Bonus +       : %+d\n", 1000000);
// 	ft_printf("Bonus #   (x) : %#x\n", hex);
// 	ft_printf("Bonus ' ' (d) : % d\n", -15425);
// 	ft_printf("Bonus ' ' (i) : % i\n", -15425);
// 	ft_printf("Bonus def (s) : |%10s|\n", str);
// 	ft_printf("Bonus def (d) : |%10d|\n", 15425);
// 	ft_printf("Bonus def (i) : |%10i|\n", 15425);
// 	ft_printf("Bonus def (x) : |%10x|\n", 15425);
// 	ft_printf("Bonus -   (s) : |%-10s|\n", str);
// 	ft_printf("Bonus -   (d) : |%-10d|\n", 15425);
// 	ft_printf("Bonus -   (i) : |%-10i|\n", 15425);
// 	ft_printf("Bonus -   (x) : |%-10x|\n", 15425);

// 	return 0;
// }

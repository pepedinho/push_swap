/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:37:41 by itahri            #+#    #+#             */
/*   Updated: 2024/05/29 18:02:20 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char const *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = manage_args(argv, argc);
    stack_b = init_stack();
    //display_stack_ab(stack_a, stack_b);
    radix(stack_a, stack_b);
    // ft_printf("swap a to b : \n");
    // display_stack_ab(stack_a, stack_b);
    // ft_printf("sorting by compare : \n");
    // display_stack_ab(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
    return 0;
}

// int main()
// {
//     t_stack *stack_a;
//     t_stack *stack_b;

// 	stack_a = init_stack();
// 	stack_b = init_stack();

//     stack(stack_a, 4);
//     stack(stack_a, 8);
//     stack(stack_a, 15);
//     stack(stack_a, 16);
//     stack(stack_a, 23);
//     stack(stack_a, 42);

//     stack(stack_b, 0);
//     stack(stack_b, 0);
//     stack(stack_b, 0);
//     stack(stack_b, 0);
//     stack(stack_b, 0);
//     stack(stack_b, 0);

//     display_stack_ab(stack_a, stack_b);

//     ft_printf("Je depile %d\n", unstack(stack_a));
//     ft_printf("Je depile %d\n", unstack(stack_a));

//     ft_printf("Je depile %d\n", unstack(stack_b));
//     ft_printf("Je depile %d\n", unstack(stack_b));

//     ft_printf("\nEtat de la pile A:\n");
//     display_stack(stack_a);

//     ft_printf("\nEtat de la pile B:\n");
//     display_stack(stack_b);

//     ft_printf("sa/sb :\n");
//     swap_ab(stack_a, stack_b);
//     display_stack_ab(stack_a, stack_b);
//     ft_printf("pa :\n");
//     push_a(stack_a, stack_b);
//     display_stack_ab(stack_a, stack_b);
//     ft_printf("len of stack A : %d\n", stack_len(stack_a));
//     ft_printf("ra :\n");
//     rotate_a(stack_a);
//     display_stack(stack_a);
//     ft_printf("reverse_rotate: \n");
//     reverse_rotate_a(stack_a);
//     display_stack(stack_a);
//     free_stack(stack_a);
//     free_stack(stack_b);

//     return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:47:44 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/26 21:47:44 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = split(argv[1], ' ');
    start_stack_a(&a, argv + 1);
    if (!is_sorted(a))
    {
        if (list_len(a) == 2)
            sa(&a, false);
        else if (list_len(a) == 3)
            small_sort(&a);
        else
            sort_big(&a, &b);
    }
    stack_free(&a);
    return (0);
}

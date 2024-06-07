/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnd_b_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:55:11 by baguiar-          #+#    #+#             */
/*   Updated: 2024/05/18 00:55:11 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void     target_b(t_stack *a, t_stack *b)
{
    t_stack     *curr_a;
    t_stack     *target;
    long            match_value;

    while (b)
    {
        match_value = LONG_MAX;
        curr_a = a;
        while (curr_a)
        {
            if (curr_a->num > b->num && curr_a->num < match_value)
            {
                match_value = curr_a->num;
                target = curr_a;
            }
            curr_a = curr_a->next;
        }
        if (match_value == LONG_MAX)
            b->target = find_smallest(a);
        else
            b->target = target;
        b = b->next;
    }
}

void    init_b(t_stack *a, t_stack *b)
{
    cur_index(a);
    cur_index(b);
    target_b(a, b);
}
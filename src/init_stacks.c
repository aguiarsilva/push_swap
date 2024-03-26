/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:24:00 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/24 22:24:00 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void     cost_analysis(t_stack *a, t_stack *b)
{
    int len_stack_a;
    int len_stack_b;

    len_stack_a = list_len(a);
    len_stack_b = list_len(b);
    while (a)
    {
        a->cost = a->i;
        if (!(a->over_med))
            a->cost = len_stack_a - (a->i);
        if (a->target->over_med)
            a->cost += a->target->i;
        else
            a->cost += len_stack_b - (a->target->i);
        a = a->next;
    }
}

static void     target_a(t_stack *a, t_stack *b)
{
    t_stack *curr_b;
    t_stack *target_node;
    long        match_value;

    while (a)
    {
        match_value = LONG_MIN;
        curr_b = b;
        while (curr_b)
        {
            if (curr_b->num < a->num && curr_b->num > match_value)
            {
                match_value = curr_b->num;
                target_node = curr_b;
            }
            curr_b = curr_b->next;
        }
        if (match_value == LONG_MIN)
            a->target = find_biggest(b);
        else
            a->target = target_node;
        a = a->next;
    }
}

static void     target_b(t_stack *a, t_stack *b)
{
    t_stack     *curr_a;
    t_stack     *target_node;
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
                target_node = curr_a;
            }
            curr_a = curr_a->next;
        }
        if (match_value == LONG_MAX)
            b->target = find_smallest(a);
        else
            b->target = target_node;
        b = b->next;
    }
}

void    init_a(t_stack *a, t_stack *b)
{
    cur_index(a);
    cur_index(b);
    target_a(a, b);
    cost_analysis(a, b);
    set_cheapest(a);
}

void    init_b(t_stack *a, t_stack *b)
{
    cur_index(a);
    cur_index(b);
    target_b(a, b);
}
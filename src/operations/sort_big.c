/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:04:02 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/21 08:04:02 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void     rot_both(t_stack **a, t_stack **b, t_stack *cheap_node)
{
    while (*b != cheap_node->target && *a != cheap_node)
        rr(a, b, false);
    cur_index(*a);
    cur_index(*b);
}

static void     rev_rot_both(t_stack **a, t_stack **b, t_stack *cheap_node)
{
    while (*b != cheap_node->target && *a != cheap_node)
        rrr(a, b, false);
    cur_index(*a);
    cur_index(*b);
}

static void     push_a_b(t_stack **a, t_stack **b)
{
    t_stack *cheap_node;

    cheap_node = get_cheapest(*a);
    if (cheap_node->over_med && cheap_node->target->over_med)
        rot_both(a, b, cheap_node);
    else if (!(cheap_node->over_med) && !(cheap_node->target->over_med))
        rev_rot_both(a, b, cheap_node);
    set_to_push(a, cheap_node, 'a');
    set_to_push(b, cheap_node->target, 'b');
    pb(b, a, false);
}

static void     push_b_a(t_stack **a, t_stack **b)
{
    set_to_push(a, (*b)->target, 'a');
    pa(a, b, false);
}

static void     small_on_top(t_stack **a)
{
    while ((*a)->num != find_smallest(*a)->num)
    {
        if (find_smallest(*a)->over_med)
            ra(a, false);
        else
            rra(a, false);
    }
}

void    sort_big(t_stack **a, t_stack **b)
{
    int len_stack_a;

    len_stack_a = list_len(*a);
    if (len_stack_a-- > 3 && !is_sorted(*a))
        pb(b, a, false);
    if (len_stack_a-- > 3 && !is_sorted(*a))
        pb(b, a, false);
    while (len_stack_a-- > 3 && !is_sorted(*a))
    {
        init_a(*a, *b);
        push_a_b(a, b);
    }
    small_sort(a);
    while (*b)
    {
        init_b(*a, *b);
        push_b_a(a, b);
    }
    cur_index(*a);
    small_on_top(a);
}
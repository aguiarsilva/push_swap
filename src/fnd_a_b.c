/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnd_a_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:55:16 by baguiar-          #+#    #+#             */
/*   Updated: 2024/05/18 00:55:16 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    cur_index(t_stack *pile)
{
    int idx;
    int median;

    idx = 0;
    if (!pile)
        return ;
    median = list_len(pile) / 2;
    while (pile)
    {
        pile->i = idx;
        if (idx <= median)
            pile->over_med = true;     
        else
            pile->over_med = false;
        pile = pile->next;
        idx++;
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

void    set_cheapest(t_stack *pile)
{
    // need variable to store the value of the cheapest node found on the iteration
    long    cheapest;
    // need variable to store pointer to the cheapest node so far
    t_stack     *cheapest_node;
    // need to check if the stack is empty and return in case of empty stack
    if  (!pile)
        return ;
    // assign the biggest long number as the cheapest to begin
    cheapest = LONG_MAX;
    // iterate through the stack until its end
    while (pile)
    {
        // Check if the current push cost is cheaper than the cheapest value
        if (pile->cost < cheapest)
        {
            //if so, update the current node
            cheapest = pile->cost;
            //assign the current value to the cheapest value so far  
            cheapest_node = pile;
        } 
        // move to next node to compare it
        pile = pile->next;
    }           
    // if no cheapest node than the current is found, set the cheapest node attribute to true
    cheapest_node->cheap = true;
}

void    init_a(t_stack *a, t_stack *b)
{
    cur_index(a);
    cur_index(b);
    target_a(a, b);
    cost_analysis(a, b);
    set_cheapest(a);
}

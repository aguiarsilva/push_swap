/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:20:47 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/17 22:20:47 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int list_len(t_stack *stack)
{
    int count;

    count = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}

t_stack *search_last(t_stack  *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

bool    is_sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->num > stack->next->num)
            return (false);
        stack = stack->next;
    }
    return (true);
}

t_stack *find_smallest(t_stack   *stack)
{
    long    min;
    t_stack *smallest_node;

    smallest_node = NULL;
    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->num < min)
        {
            min = stack->num;
            smallest_node = stack;
        }
        stack = stack->next;
    }
    return (smallest_node);
}

t_stack *find_biggest(t_stack  *stack)
{
    long    max;
    t_stack *biggest_node;

    if (!stack)
        return (NULL);
    max = LONG_MIN;
    while (stack)
    {
        if (stack->num > max)
        {
            max = stack->num;
            biggest_node = stack;
        }
        stack = stack->next;
    }
    return (biggest_node);
}

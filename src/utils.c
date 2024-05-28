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

#include "../include/push_swap.h"

int list_len(t_stack *pile)
{
    int count;

    count = 0;
    if (!pile)
        return (0);
    while (pile)
    {
        pile = pile->next;
        count++;
    }
    return (count);
}

t_stack *search_last(t_stack  *pile)
{
    if (!pile)
        return (NULL);
    while (pile->next)
        pile = pile->next;
    return (pile);
}

bool    is_sorted(t_stack *pile)
{
    if (!pile)
        return (1);
    while (pile->next)
    {
        if (pile->num > pile->next->num)
            return (false);
        pile = pile->next;
    }
    return (true);
}

t_stack *find_smallest(t_stack   *pile)
{
    long    min;
    t_stack *smallest_node;

    smallest_node = NULL;
    if (!pile)
        return (NULL);
    min = LONG_MAX;
    while (pile)
    {
        if (pile->num < min)
        {
            min = pile->num;
            smallest_node = pile;
        }
        pile = pile->next;
    }
    return (smallest_node);
}

t_stack *find_biggest(t_stack  *pile)
{
    long    max;
    t_stack *biggest_node;

    if (!pile)
        return (NULL);
    max = LONG_MIN;
    while (pile)
    {
        if (pile->num > max)
        {
            max = pile->num;
            biggest_node = pile;
        }
        pile = pile->next;
    }
    return (biggest_node);
}

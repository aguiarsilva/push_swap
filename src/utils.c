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

int list_len(t_stack *pile) //Function to calculate and return lenght of pile
{
    int count;

    if(!pile)
        return (0);
    count = 0;
    while (pile) //loop until the end of the pile is reached
    {
        pile = pile->next; //Move to next node
        count++;
    }
    return (count);
}

t_stack *search_last(t_stack  *pile) //function to find last node
{
    if(!pile)
        return (NULL);
    while (pile->next) //loop to the end of the pile
        pile = pile->next;
    return(pile);
}

bool    is_sorted(t_stack *pile) //function to check if pile is already sorted
{
    if(!pile)
        return (1);
    while (pile->next)
    {
        if (pile->num > pile->next->num) //check if current value is larger than next value
            return (false);
        pile = pile->next; //if not, move to next node and test it
    } 
    return (true);
}

t_stack *find_smallest(t_stack   *pile)
{
    long    min;
    t_stack *smallest_node;

    if(!pile)
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
    while(pile)
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

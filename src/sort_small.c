/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:41:27 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/17 22:41:27 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    small_sort(t_stack **a)
{
    t_stack *highest;

    //attribute the biggest node to the new node;
    highest = find_biggest(*a);
    //check if the current node is the biggest
    if (highest == *a)
    //if so, rotate the top node to the bottom node of the stack
        ra(a, false);
    //check if second node is the biggest
    else if ((*a)->next == highest)
    //if so, rotate reverse the bottom node to the top of the stack
        rra(a, false);
    //check if bottom node is biggest, but top node is higher than second node
    if ((*a)->num > (*a)->next->num)
    //if so, simply swap the top and second nodes
        sa(a, false);
}
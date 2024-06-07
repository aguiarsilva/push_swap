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

#include "../../include/push_swap.h"

void    small_sort(t_stack **a)
{
    t_stack *highest;

    highest = find_biggest(*a);
    if (highest == *a)
        ra(a, false);
    else if ((*a)->next == highest)
        rra(a, false);
    if ((*a)->num > (*a)->next->num)
        sa(a, false);
}
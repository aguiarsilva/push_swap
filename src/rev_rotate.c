/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:47:39 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/17 22:47:39 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void rev_rotate(t_stack **node)
{
    t_stack *end;

    if (!(*node) || (!(*node)->next))
        return ;
    end = search_last(*node);
    end->prev->next = NULL;
    end->next = *node;
    end->prev = NULL;
    *node = end;
    end->next->prev = end;
}

void    rra(t_stack **a, bool flag)
{
    rev_rotate(a);
    if (!flag)
        ft_printf("rra\n");
}

void    rrb(t_stack **b, bool flag)
{
    rev_rotate(b);
    if(!flag)
        ft_printf("rrb\n");
}

void    rrr(t_stack **a, t_stack **b, bool flag)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!flag)
        ft_printf("rrr\n");
}

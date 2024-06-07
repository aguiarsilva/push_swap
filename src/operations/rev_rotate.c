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

#include "../../include/push_swap.h"

static void rev_rotate(t_stack **stack)
{
    t_stack *end;

    if (!*stack || !(*stack)->next)
        return ;
    end = search_last(*stack);
    end->prev->next = NULL;
    end->next = *stack;
    end->prev = NULL;
    *stack = end;
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
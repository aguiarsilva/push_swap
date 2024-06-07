/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:42:11 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/18 11:42:11 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void     rotate(t_stack  **stack)
{
    t_stack *end_node;

    if (!*stack || !(*stack)->next) 
        return ;
    end_node = search_last(*stack);
    end_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    end_node->next->prev = end_node;
    end_node->next->next = NULL;
}

void    ra(t_stack **a, bool flag)
{
    rotate(a);
    if (!flag)
        ft_printf("ra\n");
}

void    rb(t_stack **b, bool flag)
{
    rotate(b);
    if (!flag)
        ft_printf("rb\n");
}

void    rr(t_stack **a, t_stack **b, bool flag)
{
    rotate(a);
    rotate(b);
    if (!flag)
        ft_printf("rr\n");
}
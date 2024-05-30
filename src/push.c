/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:45:29 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/18 11:45:29 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void     push(t_stack **dest, t_stack **src)
{
    t_stack *to_push;

    if (!*src)
        return ;
    to_push = (*src);
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    to_push->prev = NULL;
    if(!*dest)
    {
        *dest = to_push;
        to_push->next = NULL;
    }
    else
    {
        to_push->next = *dest;
        to_push->next->prev = to_push;
        *dest = to_push;
    }
}

void    pa(t_stack **a, t_stack **b, bool flag)
{
    push(a, b);
    if(!flag)
        ft_printf("pa\n");
}

void    pb(t_stack **b, t_stack **a, bool flag)
{
    push(b, a);
    if(!flag)
        ft_printf("pb\n");
}

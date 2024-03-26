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
    //create variable to receive the node to be pushed
    t_stack *to_push;
    //check if there is no source, return;
    if (!*src)
        return;
    //Attribute source to node to push variable
    to_push = *src;
    //Move the pointer to the next node, which will become next 'top node' after node before is popped off
    *src = (*src)->next;
    //Check if current node exists
    if (*src)
    //if so, set it to NULL as head of stack
        (*src)->prev = NULL;
    //Detach the node to push it from its stack
    to_push->prev = NULL;
    //Check if the destination stack is empty
    if(!*dest)
    //if it is empty, assing the first node to the stack, the node we want pushed
    {
        *dest = to_push;
        //set it as the last node (set to null)
        to_push->next = NULL;
    } //if not empty the dest stack
    else
    {
    //assign node to push to the top of the current node of the stack
        to_push->next = *dest;
    //assign to the second node 'prev' attribute, the pushed node as the current top node
        to_push->next->prev = to_push;
    //complete appending the node. The pointer to the top node of the stack is now pointing to our recently pushed node
        *dest = to_push;
    }
}

void    pa(t_stack **a, t_stack **b, bool flag)
{
    push(a, b);
    if(!flag)
        ft_printf("pa\n");
}

void    pb(t_stack **a, t_stack **b, bool flag)
{
    push(b, a);
    if(!flag)
        ft_printf("pb\n");
}
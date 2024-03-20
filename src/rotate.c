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

#include "../include/push_swap.h"

static void     rotate(t_stack  **node)
{
    t_stack *end_node; //create variable with the last node

    if (node == NULL || *node == NULL) //check if stacks exists or the pointer to the node exists
        return;
    end_node = search_last(*node); //use seach last node function to attribute the last node to the variable
    //assign the last node to its next attribute as the top node effectively setting the current node to top node as last node
    end_node->next = *node;
    //assign to the pointer of the top node, the node after it (second from the top)
    *node = (*node)->next;
    //Complete setting the current top node by detaching it from its previous top node
    (*node)->prev = NULL;
    //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
    end_node->next->prev = end_node;
    //Assign tho the next attribute of the current last node 'NULL' effectively setting it as the current last node and properly null terminating the stack
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
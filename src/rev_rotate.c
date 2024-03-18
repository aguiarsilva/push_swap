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

    if ( *node == NULL || (*node)->next == NULL)
        return ;
    end = search_last(*node);
    //Assign to the 'next' attribute of the node to node before it, and set as the current node (NULL)
    end->prev->next = NULL;
    //Assign to its own 'next' attribute as the top node of the stack
    end->next = *node;
    //Remove itself from the node before it
    end->prev = NULL;
    //append itself to the top of the stack and now holds the pointer to the top node
    *node = end;
    //update the current last node of the stack
    end->next->prev = end;
}

void    rra(t_stack **a, bool flag)
{
    rev_rotate(a);
    if (flag == NULL)
        ft_printf("rra\n");
}

void    rrb(t_stack **b, bool flag)
{
    rev_rotate(b);
    if(flag == NULL)
        ft_printf("rrb\n");
}

void    rrr(t_stack **a, t_stack **b, bool flag)
{
    rev_rotate(a);
    rev_rotate(b);
    if (flag == NULL)
        ft_printf("rrr\n");
}
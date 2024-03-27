/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:20:38 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/17 22:20:38 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void    swap(t_stack **head)
{
    //Check if no head or if no next node to head, return
    if (*head == NULL || (*head)->next == NULL)
        return;
    //Update head to point to the next node swapping first and second nodes
    *head = (*head)->next;
    //update the previous pointer of the node before the new head to skip old head and point directly to the new head
    (*head)->prev->prev = *head;
    //check if there is a next node after new head
    if ((*head)->next)
        //if so, update the prev pointer to point to new head
        (*head)->next->prev = (*head)->prev;
    //update the next pointer of new head to the old head, reversing their positions
    (*head)->next = (*head)->prev;
    //set the prev pointer of new head to null, completing the swap
    (*head)->prev = NULL;
}

void    sa(t_stack **a, bool flag)
{
    swap(a);
    if (!flag)
        ft_printf("sa\n");
}

void    sb(t_stack **b, bool flag)
{
    swap(b);
    if (!flag)
        ft_printf("sb\n");
}

void    ss(t_stack **a, t_stack **b, bool flag)
{
    swap(a);
    swap(b);
    if (!flag)
        ft_printf("ss\n");
}
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
    if (*head || (*head)->next)
        return;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
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
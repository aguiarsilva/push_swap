/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:29:02 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/25 13:29:02 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void     add_node(t_stack **pile, int n)
{
    t_stack *new_node;
    t_stack *last_node;

    if (!pile)
        return;
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return;
    new_node->next = NULL;
    new_node->num = n;
    if (!(*pile))
    {
        *pile = new_node;
        new_node->prev = NULL;
    }
    else 
    {
        last_node = search_last(*pile);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

void    start_stack_a(t_stack **a, char **argv)
{
    long    n;
    int     i;

    i = 0;
    while (argv[i])
    {
        if (syntax_error(argv[i]))
            err_free(a);
        n = ft_atoll(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            err_free(a);
        if (dup_error(*a, (int)n))
            err_free(a);
        add_node(a, (int)n);
        i++;
    }
}
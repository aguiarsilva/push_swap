/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:20:34 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/17 22:20:34 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    stack_free(t_stack  **node)
{
    t_stack *temp;
    t_stack *curr;

    //check for an empty stack and return
    if (!node)
        return;
    //atrtribute the stack to the current variable
    curr = *node;
    //loop the current stack for as long as it exists
    while (curr)    
    {
        //assign to temp, the pointer to next node
        temp = curr->next;
        //assign the node to '0' before freeing, not currently necessaire, but it can help to catch potential bugs such as memory leaks and improve debugging
        curr->num = 0;
        //free the current node
        free(curr);
        //assign temp as the current first node
        curr = temp;
    }
    //set stack to null
    *node = NULL;
}

void    err_free(t_stack **a)
{
    stack_free(a);
    ft_printf("Error\n");
    exit (1);
}
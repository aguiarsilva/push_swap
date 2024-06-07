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

#include "../../include/push_swap.h"

int     syntax_error(char *str)
{
    if (!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
        return (1);
    if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (*++str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (1);
    }
    return (0);    
}

int     dup_error(t_stack *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->num == n)
            return (1);
        a = a->next;
    }
    return (0);
}
       

void    stack_free(t_stack  **stack)
{
    t_stack *temp;
    t_stack *curr;

    if (!stack)
        return ;
    curr = *stack;
    while (curr)    
    {
        temp = curr->next;
        curr->num = 0;
        free(curr);
        curr = temp;
    }
    *stack = NULL;
}

void    err_free(t_stack **a)
{
    stack_free(a);
    ft_printf("Error\n");
    exit(1);
}
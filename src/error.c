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

int     syntax_error(char *str)
{
    //check if the first character of the input string does not contain a sign or a digit
    if (!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
        return (1);
    //check if the first character of the input string contains a sign, but the second character does not contain a digit
    if (*str == '+' || *str == '-' || !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    //pre increment the string adn loop until its end
    while (*++str)
    {
        //check if the next character is not a digit
        if (!(*str >= '0' && *str <= '9'))
            return (1);
    }
    return (0);    
}

int     dup_error(t_stack *a, int n)
{
    //check if stack is empty
    if (!a)
        return (1);
    //Loop until the endo of the stack a reached
    while (a)
    {
        //check if the current node value is = to n (refer to init_stack_a())
        if (a->num == n)
            return (1);
        //move to the next node to check for duplicates
        a = a->next;
    }
    return (0);
}
       

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
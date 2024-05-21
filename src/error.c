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

/*void    exit_error(t_pile **a, char **argv, bool flag_argc)
{
    stack_free(a);
    if (flag_argc)
        free_split_argv(argv);
    ft_printf("Error\n");
    exit(1);
}*/

int     syntax_error(char *str)
{
    int i;

    i = 0;
    //check if the first character of the input string does not contain a sign or a digit
    if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
        return (1);
    //check if the first character of the input string contains a sign, but the second character does not contain a digit
    if (str[i] == '+' || str[i] == '-')
        i++;
    //pre increment the string adn loop until its end
    while (str[i])
    {
        //check if the next character is not a digit
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);    
}

int     dup_error(t_stack *a, int n)
{
    //check if stack is empty
    if (!a)
        return (0);
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
    if (!node || !*node)
        return ;
    //atrtribute the stack to the current variable
    curr = *node;
    //loop the current stack for as long as it exists
    while (curr)    
    {
        //assign to temp, the pointer to next node
        temp = curr->next;
        //free the current node
        free(curr);
        //assign temp as the current first node
        curr = temp;
    }
    //set stack to null
    *node = NULL;
}

/*void    free_split(char **argv)
{
    int idx;

    if (!argv || !*argv)
        return ;
    idx = -1;
    while (argv[idx])
        free(argv[idx++]);
    free (argv - 1);
}*/

void    err_free(t_stack **a)
{
    stack_free(a);
    ft_printf("Error\n");
    exit (1);
}
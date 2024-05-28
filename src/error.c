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
    if (!(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')))
        return (1);
    if ((str[i] == '+' || str[i] == '-') && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (str[++i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
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
       

void    stack_free(t_stack  **node)
{
    t_stack *temp;
    t_stack *curr;

    if (!node)
        return ;
    curr = *node;
    while (curr)    
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
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
    exit(1);
}
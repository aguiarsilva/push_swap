/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:24:00 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/24 22:24:00 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static long   ft_atoll(const char *str)
{
    long        res;
    int         sign;

    res = 0;
    sign = 1;
    while((*str == 32) || (*str >= 9 && *str <= 13))
        str++;
    if ((*str == '-') || (*str == '+'))
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (ft_isdigit(*str))
        res = res * 10 + (*str++ - '0');
    return (res * sign);
}

static void     add_node(t_stack **stack, int n)
{
    t_stack *node_to_add;
    t_stack *end_node;

    if (!stack)
        return ;
    node_to_add = malloc(sizeof(t_stack));
    if (!node_to_add)
        return ;
    node_to_add->next = NULL;
    node_to_add->num = n;
    if (!(*stack))
    {
        *stack = node_to_add;
        node_to_add->prev = NULL;
    }
    else
    {
        end_node = search_last(*stack);
        end_node->next = node_to_add;
        node_to_add->prev = end_node;
    }
}

void    start_stack_a(t_stack **a, char **argv, bool flag_argc)
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
    if (flag_argc)
        free_split(argv);
}

t_stack *get_cheapest(t_stack *stack)
{
    if (!stack)
        	return (NULL);
    while (stack)
    {
        if (stack->cheap)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void    set_to_push(t_stack **stack, t_stack *top_node, char stack_id)
{
 while (*stack != top_node)
 {
    if (stack_id == 'a')
    {
        if (top_node->over_med)
            ra(stack, false);
        else
            rra(stack, false);
    }        
    else if (stack_id == 'b')
    {
        if (top_node->over_med)
            rb(stack, false);
        else
            rrb(stack, false);
    }            
 }
}

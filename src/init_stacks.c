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

#include "../include/push_swap.h"

static void     add_node(t_stack **stack, int n)
{
    t_stack *node_to_add;
    t_stack *end_node;

    if (!stack)
        return ;
    node_to_add = (t_stack *)malloc(sizeof(t_stack));
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

void    start_stack_a(t_stack **a, char **argv)
{
    long    n;
    int     i;

    i = 0;
    while (argv[i])
    {
        if (syntax_error(argv[i]))
            err_free(a);
        n = ft_atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            err_free(a);
        if (dup_error(*a, (int)n))
            err_free(a);
        add_node(a, (int)n);
        i++;
    }
}

t_stack *get_cheapest(t_stack *node)
{
    // check if the stack is empty and return null in case of it is
    if (!node)
        	return (NULL);
    // iterate through the stack until its end
    while (node)
    {
        // check if the attribute cheapest of the data is true
        if (node->cheap)
            // if so, return the stack
            return (node);
        // move the stack to the next node;
        node = node->next;
    }
    // if there is no iteration to be made anymore, return NULL
    return (NULL);
}

void    set_to_push(t_stack **pile, t_stack *top_node, char stack_id)
{
 // iterate through the stack checking if the required node is not already the first node
 while (*pile != top_node)
 {
    // if not, and it is stack a, do
    if (stack_id == 'a')
    {
        //check if top node is above the median,
        if (top_node->over_med) 
            // if so, rotate a
            ra(pile, false);
        // if not
        else
            // reverse rotate a
            rra(pile, false);
    }        
    // else if the stack is b
    else if (stack_id == 'b')
    {
        // check if top node is above the median
        if (top_node->over_med)
            // if so, rotate b
            rb(pile, false);
        // if not
        else
            // reverse rotate b
            rrb(pile, false);
    }            
 }
}
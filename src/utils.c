/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:20:47 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/17 22:20:47 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int list_len(t_stack *pile) //Function to calculate and return lenght of pile
{
    int count;

    if(!pile)
        return (0);
    count = 0;
    while (pile) //loop until the end of the pile is reached
    {
        pile = pile->next; //Move to next node
        count++;
    }
    return (count);
}

t_stack *search_last(t_stack  *pile) //function to find last node
{
    if(!pile)
        return (NULL);
    while (pile->next) //loop to the end of the pile
        pile = pile->next;
    return(pile);
}

bool    is_sorted(t_stack *pile) //function to check if pile is already sorted
{
    if(!pile)
        return (1);
    while (pile->next)
    {
        if (pile->num > pile->next->num) //check if current value is larger than next value
            return (false);
        pile = pile->next; //if not, move to next node and test it
    } 
    return (true);
}

t_stack *find_smallest(t_stack   *pile)
{
    long    min;
    t_stack *smallest_node;

    if(!pile)
        return (NULL);
    min = LONG_MAX;
    while (pile)
    {
        if (pile->num < min)
        {
            min = pile->num;
            smallest_node = pile;
        }
        pile = pile->next;
    }
    return (smallest_node);
}

t_stack *find_biggest(t_stack  *pile)
{
    long    max;
    t_stack *biggest_node;

    if (!pile)
        return (NULL);
    max = LONG_MIN;
    while(pile)
    {
        if (pile->num > max)
        {
            max = pile->num;
            biggest_node = pile;
        }
        pile = pile->next;
    }
    return (biggest_node);
}

void    set_cheapest(t_stack *pile)
{
    // need variable to store the value of the cheapest node found on the iteration
    long    cheapest;
    // need variable to store pointer to the cheapest node so far
    t_stack     *cheapest_node;
    // need to check if the stack is empty and return in case of empty stack
    if  (!pile)
        return;
    // assign the biggest long number as the cheapest to begin
    cheapest = LONG_MAX;
    // iterate through the stack until its end
    while (pile)
    {
        // Check if the current push cost is cheaper than the cheapest value
        if (pile->cost < cheapest)
        {
            //if so, update the current node
            cheapest = pile->cost;
            //assign the current value to the cheapest value so far  
            cheapest_node = pile;
        } 
        // move to next node to compare it
        pile = pile->next;
    }           
    // if no cheapest node than the current is found, set the cheapest node attribute to true
    cheapest_node->cheap = true;
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

void    cur_index(t_stack *pile)
{
    // need variable to store the index of current node
    int idx;
    // need variable to store the position of the median of stack
    int median;
    // set the first index to '0' as it is the first index number
    idx = 0;
    // check if the stack is empty, if so, return
    if (!pile)
        return;
    // the median needs to be calculated by dividing the lenght of the stack by 2
    median = list_len(pile) / 2;
    // iterate through the stack until its end
    while (pile)
    {
        //assign the current index value to the current node
        pile->i = idx;
        //if index is less or equal median
        if (idx <= median)
            // set the above_median attribute of the structure to true
            pile->over_med = true;     
        else
        // else set it to false
            pile->over_med = false;
        // move to the next node to continue the iteration
        pile = pile->next;
        // increment the index value to set the next node with its index number
        ++idx;
    }
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

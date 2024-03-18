/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:21:02 by baguiar-          #+#    #+#             */
/*   Updated: 2024/03/17 22:21:02 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

//create the struct of a doubly linked list

typedef struct s_stack
{
    int     num;
    int     i;
    int     cost;
    bool    over_med;
    bool    cheap;
    struct  s_stack *target;
    struct  s_stack *next;
    struct  s_stack *prev;
} t_stack;

//Error Handling

// Start Stack

// Start nodes

// utils

int list_len(t_stack *pile);
t_stack *search_last(t_stack  *pile);
bool    is_sorted(t_stack *pile);

// Commands

static void    swap(t_stack **head);
void    rra(t_stack **a, bool flag);
void    sb(t_stack **b, bool flag);
void    ss(t_stack **a, t_stack **b, bool flag);
static void rev_rotate(t_stack **node);
void    rra(t_stack **a, bool flag);
void    rrb(t_stack **b, bool flag);
void    rrr(t_stack **a, t_stack **b, bool flag);

// Algorithms used

#endif
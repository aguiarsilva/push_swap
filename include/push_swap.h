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
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

//create the struct of a linked list

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

/*
typedef struct s_pile
{
    t_stack  *top;
} t_pile;
*/

//Error Handling

void    exit_error(t_pile **a, char **argv, bool flag_argc);
void    stack_free(t_pile  **node);
void    err_free(t_stack **a);
int     syntax_error(char *str);
int     dup_error(t_stack *a, int n);
//void    free_split(char **argv);

// Start Stack

void    start_stack_a(t_stack **a, char **argv);
void     add_node(t_stack **pile, int n);

// Start nodes

void    init_a(t_stack *a, t_stack *b);
void    init_b(t_stack *a, t_stack *b);

// utils

char    **split(char *str, char c);
int list_len(t_stack *pile);
t_stack *search_last(t_stack  *pile);
bool    is_sorted(t_stack *pile);
t_stack *find_smallest(t_stack   *pile);
t_stack *find_biggest(t_stack  *pile);
void    set_cheapest(t_stack *node);
t_stack *get_cheapest(t_stack *node);
void    cur_index(t_stack *node);
void    set_to_push(t_stack **node, t_stack *top_node, char stack_id);

// Commands

void    sa(t_stack **a, bool flag);
void    sb(t_stack **b, bool flag);
void    ss(t_stack **a, t_stack **b, bool flag);
void    rra(t_stack **a, bool flag);
void    rrb(t_stack **b, bool flag);
void    rrr(t_stack **a, t_stack **b, bool flag);
void    ra(t_stack **a, bool flag);
void    rb(t_stack **b, bool flag);
void    rr(t_stack **a, t_stack **b, bool flag);
void    pa(t_stack **a, t_stack **b, bool flag);
void    pb(t_stack **a, t_stack **b, bool flag);

// Algorithms used

void    small_sort(t_stack **a);
void    sort_big(t_stack **a, t_stack **b);
void     small_on_top(t_stack **a);

#endif
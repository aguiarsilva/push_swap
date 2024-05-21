/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baguiar- <baguiar-@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:21:00 by baguiar-          #+#    #+#             */
/*   Updated: 2024/05/10 00:21:00 by baguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int      word_count(char *str, char c)
{
    int         wc;
    bool    letter;

    wc = 0;
    while (*str)
    {
        letter = false;
        while (*str == c)
            ++str;
        while (*str != c && *str)
        {
            if (letter)
            {
                ++wc;
                letter = true;
            }
            ++str;
        }
    }
    return (wc);
}

static char     *put_substr(char *str, char c)
{
    static int      pos;
    char            *substr;
    int             len;
    int             idx;

    len = 0;
    idx = 0;
    while (str[pos] == c)
        ++pos;
    while ((str[pos + len] != c) && str[pos + len])
        ++len;
    substr = malloc((size_t)len * sizeof(char) + 1);
    if (!substr)
        return (NULL);
    while ((s[pos] != c) && str[pos])
        substr[idx++] = str[pos++];
    substr[idx] = '\0';
    return (substr);
}

char    **split(char *str, char c)
{
    int        wc;
    char    **arr;
    int         idx;

    idx = 0;
    wc = word_count(str, c);
    if (!wc)
        exit(1);
    arr = malloc((wc + 2) * sizeof(char *));
    if (!arr)
        return (NULL);
    while (wc-- >= 0)
    {
        if (idx == 0)
        {
            arr[idx] = malloc(sizeof(char));
            if (!arr)
                return (NULL);
            arr[idx++][0] = '\0';
            continue;
        }
        arr[idx++] = put_substr(str, c);
    }
    arr[idx] = NULL;
    return (arr);
}
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
    int         word_letters;

    wc = 0;
    word_letters = 0;
    while (*str)
    {
        while (*str)
        {
            if (*str != c && word_letters == 0)
            {
                wc++;
                word_letters = 1;
            }
            else if (*str == c)
            {
                word_letters = 0;
            }
            str++;
        }
    }
    return (wc);
}

static char     *put_substr(char *str, char c)
{
    static int      pos;
    char            *substr;
    size_t             len;
    int             idx;

    pos = 0;
    len = 0;
    idx = 0;
    while (str[pos] == c)
        pos++;
    if (str[pos] == '\0')
        return (NULL);
    while ((str[pos + len] != c) && str[pos + len] != '\0')
        len++;
    substr = malloc((size_t)len * sizeof(char) + 1);
    if (!substr)
        return (NULL);
    while ((str[pos] != c) && str[pos])
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
    arr = malloc(sizeof(char *) * (size_t)(wc + 2));
    if (!arr)
        return (NULL);
    while (wc-- >= 0)
    {
        if (idx == 0)
        {
            arr[idx] = malloc(sizeof(char));
            if (!arr[idx])
                return (NULL);
            arr[idx++][0] = '\0';
            continue;
        }
        arr[idx++] = put_substr(str, c);
    }
    arr[idx] = NULL;
    return (arr);
}

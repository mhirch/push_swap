/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:41:43 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/11 13:47:44 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_stack
{
	int		*arr;
	int size;
	int capacity;
	char **tab;
} t_stack;


void push_back(t_stack *s, int b);
void pop_back(t_stack *s);
t_stack *create_stack(int a);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 08:50:52 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/20 16:00:13 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(char *m);
long	ft_atoi(char *str);
int		ft_intcmp(int a, int b);
char	*ft_strjoinn(char *s1, char *s2);
char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);

int		make_operation(char *x, t_list **a, t_list **b);
void	sorted_or_not(t_list *stack_a);
int		length(t_list *stack);
void	store_and_check(t_list **stack_a, int argc, char **argv);
int		push_a(t_list **a, t_list **b);
int		push_b(t_list **a, t_list **b);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);
int		swap(t_list **a);

#endif

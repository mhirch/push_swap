/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:41:43 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/31 15:29:25 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>

// typedef struct s_stack
// {
// 	int		*arr;
// 	int size;
// 	int capacity;
// } t_stack;
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_info
{
	int		*arr;
	int		size;
	int		capacity;
	t_node	head;
}	t_info;

// void	push_back(t_stack *s, int b);
// void	pop_back(t_stack *s);
t_info	*create_info(int a);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(char *str);
int		ft_isdigit(char *m);
int		ft_strlen(char *str);
char	**ft_split(char *s, char c);
t_node	*store_and_check(int argc, char **argv);
int		ft_strcmp(int str1, int str2);
void	printList(t_node* head);

#endif
/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:34:33 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/01 12:44:51 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
// # include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# define INT_MIN  -2147483648
# define INT_MAX  2147483647

typedef struct s_info
{
	int		*arr;
	int		size;
	int		capacity;
}	t_info;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

typedef struct s_lis_info
{
	int *length;
	int *index_of_lis;
	int length_lis;
	int max_lis_index;
	int *lis;
}	t_lis_info;

/*libft*/
int		ft_strlen(char *str);
int		ft_isdigit(char *m);
long	ft_atoi(char *str);
int		ft_strcmp(int str1, int str2);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *s, char c);
/*just for that*/
void	store_and_check(t_info **info, t_list **stack_a,int argc, char **argv);
t_info *initialize_info(int a);

void bubblesort(int *arr, int n);


#endif
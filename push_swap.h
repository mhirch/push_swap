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
# include <unistd.h>
# include <stdbool.h>
# define INT_MIN  -2147483648
# define INT_MAX  2147483647

typedef struct s_info
{
	int		*arr;
	int		capacity;
}	t_info;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

typedef struct s_lis_info
{
	int	*length;
	int	*index_of_lis;
	int	length_lis;
	int	max_lis_index;
	int	*lis;
}	t_lis_info;

/*libft*/
int			ft_strlen(char *str);
int			ft_isdigit(char *m);
long		ft_atoi(char *str);
int			ft_intcmp(int a, int b);
char		*ft_strjoinn(char *s1, char *s2);
char		**ft_split(char *s, char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *s1);

/*store_check*/
void		store_and_check(t_info **i, t_list **a, int argc, char **argv);

/*lis*/
t_lis_info	*initialize_lis(int a);
void		get_index(t_lis_info *lis, t_info *a);
void		get_lis(t_lis_info *lis, t_info *a);
int			is_lis_in_stack(t_list *a, t_lis_info *lis);
void		out_of_lis_in_b(t_list **a, t_list **b, t_lis_info *lis, int c);
void		free_lis_info(t_lis_info *lis);

/*sort*/
void		main_sort(t_info **info, t_list **a);
void		better_call_saul(t_list **a, t_list **b, int *moves);
void		sort(t_info **info, t_list **a, t_list **b);
void		simple_sort(t_list **a, t_list **b);
void		magic(t_list **b, t_list **a);
void		sort_three(t_list **a, t_list **b);
int			is_sorted(t_list *a);
void		akhir_sort(t_list **a, t_list **b);

/*utils*/
int			biggest_one(t_list *a);
int			ft_abs(int x);
int			length(t_list *stack);
int			check_moves(t_list *a, t_list *b, int **moves);
int			*calcul_moves(t_list *a, t_list *b, int data);
int			best_one(int **moves, int i);
int			find_position(t_list *stack, int number);
int			data_is_biggest(t_list *a, int data);
int			calculate(int a, int b);
int			moves_stack_b(t_list *b, int position);
int			moves_stack_a(t_list *a, int data);
int			small_one(int a, int b);
int			small_in_top(t_list **a, t_list **b, int capacity, int small_num);
int			smallest_in_stack(t_list *a);
int			to_be_replaced(t_list *a, int data);
int			bigger_than_data(t_list *a, int data, int i);
void		case4(t_list **a, t_list **b, int *move_a, int *move_b);
void		case5(t_list **a, t_list **b, int *move_a, int *move_b);
void		case6(t_list **a, t_list **b, int *move_a, int *move_b);

/*operations*/
int			double_operattion(char *x, t_list **a, t_list **b);
void		make_operation(char *x, t_list **a, t_list **b);
int			rotate(t_list **stack);
int			reverse_rotate(t_list **stack);
int			swap(t_list **a);
int			push_a(t_list **a, t_list **b);
int			push_b(t_list **a, t_list **b);



void printList(t_list *head);

#endif
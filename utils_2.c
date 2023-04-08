/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:37:35 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/08 15:04:50 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info *initialize_info(int a)
{
	t_info *s = malloc(sizeof(t_info));
	s->capacity = a;
	s->size = 0;
	s->arr = malloc(sizeof(int) * a);
	return s;
}

void	check(char **tab)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > INT_MAX || ft_atoi(tab[i]) < INT_MIN || ft_isdigit(tab[i]) == 0)
		{
			printf("erreur\n");
			exit(1);
		}
		j = i + 1;
		while (tab[j])
		{
			if (ft_intcmp(ft_atoi(tab[i]), ft_atoi(tab[j++])) == 0)
			{
				printf("erreur\n");
				exit(1);
			}
		}
		i++;
	}
}
// void printList(t_list *head)
// {
// 	t_list* temp;
	
// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// }

t_list *newnode(int data)
{
	t_list *newNode ;
	newNode = (t_list*)malloc(sizeof(t_list));
	if (!newNode)
		exit (1);
	newNode->data = data;
	newNode->next = NULL;
	return (newNode);
}

void add_node(t_list **head, int data) 
{
	t_list *temp;
    if (*head == NULL) 
        *head = newnode(data);
    else
    {
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode(data);
    }
}
void	store_and_check(t_info **info,t_list **stack_a, int argc, char **argv)
{
	int		i;
	char	*args;
	char	**tab;
	

	args = NULL;
	i = 1;
	while (i < argc)
		args = ft_strjoin(args, argv[i++]);
	tab = ft_split(args, ' ');
	check(tab);
	i = 0;
	while (tab[i])
		i++;
	(*info) = initialize_info(i);
	i = -1;
	while (tab[++i])
	{
		(*info)->arr[i] = ft_atoi(tab[i]);
		add_node(stack_a,(*info)->arr[i]);
	}
	// printList(*stack_a);
}

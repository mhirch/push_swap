/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:29:51 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/29 15:29:39 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *newnode(int data)
{
	t_node *newNode ;
	newNode = (t_node*)malloc(sizeof(t_node));
	if (!newNode)
		exit (1);
	newNode->data = data;
    newNode->next = NULL;
	return (newNode);
}

void addnode(t_node **head, int data) 
{
	t_node* temp;
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

void printList(t_node *head)
{
    t_node* temp;
	
	temp = head;
    while (temp != NULL)
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void	check(char **tab)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while(tab[i])
	{
		if (ft_atoi(tab[i]) > INT_MAX || ft_atoi(tab[i]) < INT_MIN)
		{
			printf("erreur-out_of_int\n");
            exit(1);
		}
		if (ft_isdigit(tab[i]) == 0)
		{
            printf("erreur-not number\n");
            exit(1);
        }
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(ft_atoi(tab[i]), ft_atoi(tab[j++])) == 0)
			{
                printf("erreur-duplicated\n");
                exit(1);
            }
		}
		i++;
	}
}

t_stack	*store_and_check(int argc, char **argv)
{
	int		i;
	char	*args;
	char	**tab;
	t_stack	*a;
	t_node *head;

	head = NULL;
	args = NULL;
	i = 1;
	while (i < argc)
		args = ft_strjoin(args, argv[i++]);
	tab = ft_split(args, ' ');
	i = 0;
	check(tab);
	while (tab[i])
		i++;
	a = create_stack(i);
	i = -1;
	while (tab[++i])
		a->arr[i] = ft_atoi(tab[i]);
	// i = -1;
	// while (++i < a->capacity)
	// 	addnode(&head,a->arr[i]);
	// return(head);
	return(a);
}

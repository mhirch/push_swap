/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 08:54:17 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/19 11:50:52 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*newnode(int data)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		exit (1);
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}

void	add_node(t_list **head, int data)
{
	t_list	*temp;

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

void	check(char **tab)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > INT_MAX || ft_atoi(tab[i])
			< INT_MIN || ft_isdigit(tab[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		j = i + 1;
		while (tab[j])
		{
			if (ft_intcmp(ft_atoi(tab[i]), ft_atoi(tab[j++])) == 0)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		i++;
	}
}

void	store_and_check(t_list **stack_a, int argc, char **argv)
{
	int		i;
	char	*args;
	char	**tab;

	args = NULL;
	i = 1;
	while (i < argc)
		args = ft_strjoinn(args, argv[i++]);
	tab = ft_split(args, ' ');
	check(tab);
	free(args);
	i = -1;
	while (tab[++i])
	{
		add_node(stack_a, ft_atoi(tab[i]));
		free(tab[i]);
	}
	free(tab);
}

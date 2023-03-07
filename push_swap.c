/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:44:05 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/07 15:10:57 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int m)
{
	if (m >= 48 && m <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	r;
	int	sign;

	i = 0;
	r = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * sign);
}

#define MAX_ARGS 100

int store_arguments(int argc, char *argv[], int args[])
{
	int i;
	
    if (argc > MAX_ARGS) {
        printf("Too many arguments.\n");
        return -1;
    }
	i = 0;
	while(i < argc)
	{
		args[i] = ft_atoi(argv[i]);
		i++;
	}

    return argc;
}

int main(int argc, char *argv[])
{
    int args[MAX_ARGS];
	int i;
    int num_args;
	
	num_args = store_arguments(argc, argv, args);

    if (num_args == -1)
        return 1;
	i = 1;
    printf("all Arguments: %d\n", num_args - 1);
	while (i < num_args)
	{
		printf("%d\n", args[i++]);
	}
    return 0;
}
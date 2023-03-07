/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:44:05 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/07 14:32:00 by mhirch           ###   ########.fr       */
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

int	ft_atoi(char str)
{
	int	r;

	r = 0;
    if (str >= 48 && str <= 57)
	{
		r = r * 10 + (str - 48);
	}
	return (r );
}

// int	ft_atoi(char str)
// {
// 	int	i;
// 	int	r;
// 	int	sign;

// 	i = 0;
// 	r = 0;
// 	sign = 1;
// 	while ((str >= 9 && str <= 13) || str == 32)
// 		i++;
// 	if (str == '-' || str == '+')
// 	{
// 		if (str == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str >= 48 && str <= 57)
// 	{
// 		r = r * 10 + (str - 48);
// 		i++;
// 	}
// 	return (r * sign);
// }

#define MAX_ARGS 100

int store_arguments(int argc, char *argv[], char **args)
{
	int i;
	
    // if (argc > MAX_ARGS) {
    //     printf("Too many arguments.\n");
    //     return -1;
    // }
	i = 0;
	while(i < argc)
	{
		// j = 0;
		// while(!ft_isdigit(ft_atoi(argv[i][j++])))
		// {
		// 	if(!argv[i++])
		// 		break ;
		// 	printf("erreur\n");
		// 	return 0;
		// }
		args[i] = (char *)malloc(ft_strlen(argv[i])+ 1);
		// ft_strcpy(args[i], argv[i]);
		args[i] = argv[i];
		i++;
	}

    return argc;
}

int main(int argc, char *argv[])
{
    char *args[MAX_ARGS];
	int i;
    int num_args;
	
	num_args = store_arguments(argc, argv, args);

    if (num_args == -1)
        return 1;
	i = 1;
    printf("all Arguments: %d\n", num_args - 1);
	while (i < num_args)
	{
		printf("%s\n", args[i++]);
	}
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:51:42 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/18 18:14:50 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(char *m)
{
	int	isdigit;
	int	j;

	isdigit = 1;
	j = 0;
	if (!m)
		return (0);
	if ((m[j] == '-' || m[j] == '+'))
	{
		isdigit = 1;
		j++;
		if (!m[j])
			return (0);
	}
	while (m[j] && isdigit == 1)
	{
		if ((m[j] >= 48 && m[j] <= 57))
			isdigit = 1;
		else
			isdigit = 0;
		j++;
	}
	return (isdigit);
}

long	ft_atoi(char *str)
{
	int		i;
	long	r;
	int		sign;

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

int	ft_intcmp(int a, int b)
{
	int	j;

	if (a == b)
		j = 0;
	else
		j = 1;
	return (j);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	z;
	char	*s3;

	z = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	i = ft_strlen(s1) + ft_strlen(s2) + 2;
	s3 = (char *)malloc(sizeof(char) * i);
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
		s3[z++] = s1[i++];
	s3[z++] = ' ';
	i = 0;
	while (s2[i])
		s3[z++] = s2[i++];
	s3[z] = '\0';
	free(s1);
	return (s3);
}

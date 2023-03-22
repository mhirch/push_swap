/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:44:05 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/22 12:44:48 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substring = malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	if (start >= (unsigned int)ft_strlen((char *)s))
	{
		*substring = '\0' ;
		return (substring);
	}
	while (i < len && s[start])
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

//////////////////////////////////////////////////////////////////////////////


static	int	count_str(const char *str, char c)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (str == NULL)
		return (0);
	if (str[i] != c)
		z++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			z++;
		i++;
	}
	i = 0;
	return (z);
}

static	void	f_free(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
}

static	void	skip(char const *s, int *i, int *index, char c)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
	*index = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		index;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (i <= (int)ft_strlen(s))
	{
		skip(s, &i, &index, c);
		if (index < i)
		{
			tab[j] = ft_substr(&s[index], 0, i - index);
			if (!tab[j])
				f_free(tab, j);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
//////////////////////////////////////////////////////////////////////////////




int	ft_isdigit(char *m)
{
	int isDigit;
	int j;
	
	isDigit = 1;
	j = 0;
	if (!m)
		return 0;
	if ((m[j] == '-' || m[j] == '+'))
	{
			isDigit = 1;
			j++;
			if (!m[j])
				return(0);
	}
	while (m[j] && isDigit == 1)
	{
		if ((m[j] >= 48 && m[j] <= 57))
		  isDigit = 1;
 		else
		  isDigit = 0;
		j++;
	}
	return(isDigit);
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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if(!s)
		return s;
	while (s[i])
	{
		if (s[i] == (char)c)
			s[i] = ' ';
		i++;
	}
	return(s);
	// if (s[i] == (char)c)
	// 	return ((char *)&s[i]);
	// return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	z;
	char	*s3;

	i = 0;
	z = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	if (!s1)
		return ((char *)s2);
	s3 = (char *)malloc(sizeof(char)* ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);
	if (!s3)
		return (NULL);
	while (s1[i])
		s3[z++] = s1[i++];
	s3[z++] = ' ';
	i = 0;
	while (s2[i])
		s3[z++] = s2[i++];
	s3[z] = '\0';
	return (s3);
}

// void push_back(t_stack *s, int b) {
// 	if (s->size < s->capacity) {	
// 		s->arr[s->size] = b;
// 		s->size++;
// 	}
// }

void pop_back(t_stack *s) {
	if (s->size > 0)
 		s->size--;
}

t_stack *create_stack(int a) {
	t_stack *s = malloc(sizeof(t_stack));
	s->capacity = a;
	s->size = 0;
	s->arr = malloc(sizeof(int) * a);
	// s->node = NULL;
	return s;
}

int	ft_strcmp(int str1, int str2)
{
	int j;
	
	if (!str2 || !str1)
		j = 1337;
	else if (str1 == str2)
		j = 0;
	else
		j = 1;
	return (j);
}

void store_arguments(int argc, char *argv[], t_stack *s)
{
	int i, j;
	char *all;
	// t_stack *s = create_stack(1);
	char **tab;
	i = 1;
	while(i < argc)
	{
		if (ft_isdigit(argv[i]) == 0)
		{
            printf("erreur-not number\n");
            exit(1);
        }
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(ft_atoi(argv[i]), ft_atoi(argv[j++])) == 0)
			{
				printf("%s\n",argv[i]);
                printf("erreur-duplicated\n");
                exit(1);
            }
			// else 
			// {
			// 	write(1, "erreur\n", 8);
			// 	exit(1);
			// }
		}
		all = ft_strjoin(all,argv[i]);
		i++; 
	}
	s->capacity = 0;
	tab = ft_split(all, ' ');
	while (tab[s->capacity])
		s->capacity++;
	s->arr = malloc(s->capacity * sizeof(int));
	i = 0;
	while (tab[i])
	{
		s->arr[i] = ft_atoi(tab[i]);
		i++;
	}
	i = 0;
	printf("number of Arguments: %d\n", argc - 1);
	// while(i < s->capacity)
	// 	printf("%d\n", s->arr[i++]);
	// return s->arr;
}

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
        {
            temp = temp->next;
        }
        temp->next = newnode(data);
    }
}

void printList(t_node* head)
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

void	check_and_store(int argc, char **argv)
{
	int i, j, a;
	char **tab;
	char *all_args;
	// t_stack *a;
	i = 0;
	j = 1;
	while(argv[j])
	{
		while(argv[j][i])
			i++;
		j++;
	}
	all_args = malloc(argc);
	printf("%d  %d ", j , i);
	while(i < argc)
		all_args = ft_strjoin(all_args,argv[i++]);
	printf("%s", all_args);
	tab = ft_split(all_args, ' ');
	i = 0;
	while(tab[i])
		printf("%s \n", tab[i++]);
	i = 0;
	// while(tab[i])
	// {
	// 	if (ft_isdigit(tab[i]) == 0)
	// 	{
    //         printf("erreur-not number\n");
    //         exit(1);
    //     }
	// 	j = i + 1;
	// 	while (tab[j])
	// 	{
	// 		if (ft_strcmp(ft_atoi(tab[i]), ft_atoi(tab[j++])) == 0)
	// 		{
    //             printf("erreur-duplicated\n");
    //             exit(1);
    //         }
	// 	}
	// 	i++;
	// }
	// a = create_stack(i - 1);
	// a->capacity = i - 1;
	// a->arr = malloc(a->capacity * sizeof(int));
	// a->capacity = 0;
	// while(tab[a->capacity])
	// {
	// 	a->arr[a->capacity] = ft_atoi(tab[a->capacity]);
	// 	a->capacity++;
	// }
	// a->capacity = 0;
	// while(a->arr[a->capacity])
	// 	printf("%d \n", a->arr[a->capacity++]);
}
void	check(char **tab)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while(tab[i])
	{
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

void	store_and_check(int argc, char **argv)
{
	int		i;
	int		j;
	char	*args;
	char	**tab;
	t_stack	*s;
	t_node *head;
	int len;

	head = NULL;
	i = 1;
	while (i < argc)
		j += ft_strlen(argv[i++]);
	args = (char*) malloc(j * sizeof(char));
	args = NULL;
	i = 1;
	while (i < argc)
		args = ft_strjoin(args, argv[i++]);
	tab = ft_split(args, ' ');
	i = 0;
	check(tab);
	while (tab[i])
		i++;
	s = create_stack(i);
	i = 0;
	while (tab[i])
	{
		s->arr[i] = ft_atoi(tab[i]);
		i++;
	}
	len = i;
	i = -1;
	while (++i < len)
		addnode(&head,s->arr[i]);
	printList(head);
}

int	main(int argc, char **argv)
{
	store_and_check(argc, argv);
    return 0;
}

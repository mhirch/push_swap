/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:40:39 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/11 13:19:04 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// int[100];
// count = 0;

// void push()
// {
    
// }

int main () {
    t_stack *s = create_stack(1000);
    int i = -1;
    while (++i < s->capacity)
    {
        push_back(s,i);
    }
    i = -1;
    // pop_back(s);
    
    while (++i < s->size)
         printf("%d\n", s->arr[i]);
}

int	ft_isdigit(char *m)
{
	int isDigit = 1;
	int j=0;
	
    if(!m[j])
        isDigit = 0;
	while(m[j] && isDigit == 1)
	{
  		if( m[j] >= 48 && m[j] <= 57)
  		  isDigit = 1;
 		else
  		  isDigit = 0;
  		j++;
	}
	return(isDigit);
}
int main()
{
    int i = ft_isdigit("9");
    printf( " %d \n", i);
}
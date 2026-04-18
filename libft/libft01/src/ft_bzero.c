/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:24:03 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 18:58:44 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	count;

	ptr = s;
	count = 0;
	while (count < n)
	{
		ptr[count] = 0;
		count++;
	}
}

/* str - pointer to the block of memory to fill
c - second parameter of type integer and 
converts it to an unsigned char before using it to fill a block of memory
n - number of bytes to be set to the value */

/* #include <stdio.h>
#include <string.h>

int main()
{
    char s1[50] = "GeeksForGeeks is for programming geeks.";
    char s2[50] = "GeeksForGeeks is for programming geeks.";
    int n = 10;
    int arr[n];

    printf("Orginal str: %s\n", s1);

    printf("\n");
	bzero(s1, 1);
    printf("bzero: %s\n", s1);
	ft_bzero(s1, 1);
    printf("ft_bzero: %s\n", s1);

    printf("\n");
    printf("s2 + 13\n");
    printf("Orginal str: %s\n", s2);
    bzero(s2 + 10, 8*sizeof(char));
    printf("bzero: %s\n", s2);
    ft_bzero(s2 + 10, 8*sizeof(char));
    printf("ft_bzero: %s\n", s2);

    // TODO: Check arrays - seems fine
    printf("\n");
    ft_bzero(arr, 2*sizeof(arr[0]));
    printf("Array after bzero()\n");
    for (int i=0; i<n; i++)
      printf("%d ", arr[i]);

    return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 09:39:26 by pang              #+#    #+#             */
/*   Updated: 2025/05/09 09:44:44 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;
	size_t	count;

	ptr = str;
	count = 0;
	while (count < n)
	{
		*ptr = (unsigned char) c;
		ptr++;
		count++;
	}
	return (str);
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
    printf("memset: %s\n", (char *)memset(s1, '-', 8));
    printf("ft_memset: %s\n", (char *)ft_memset(s1, '-', 8));

    printf("\n");
    printf("s2 + 13\n");
    printf("Orginal str: %s\n", s2);
    printf("\n");

    memset(s2 + 13, '.', 8*sizeof(char));
    printf("memset: %s\n", s2);
    ft_memset(s2 + 13, '.', 8*sizeof(char));
    printf("ft_memset: %s\n", s2);

    // TODO: Check arrays - seems fine
    printf("\n");
    ft_memset(arr, 0, n*sizeof(arr[0]));
    printf("Array after memset()\n");
    for (int i=0; i<n; i++)
      printf("%d ", arr[i]);

    return (0);
}
 */
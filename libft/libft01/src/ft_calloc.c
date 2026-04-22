/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:12:06 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 18:58:55 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			count;
	size_t			limits;

	count = 0;
	limits = -1;
	if (num == 0 || size == 0)
		return (malloc(0));
	if (size > limits / num)
		return (NULL);
	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	while (count < (num * size))
	{
		ptr[count] = 0;
		count++;
	}
	return (ptr);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>


int main() {
    // Zero size tests
    void *a = ft_calloc(0, 10);
    void *b = ft_calloc(10, 0);
    assert(a == NULL || a != NULL); // Must not crash
    assert(b == NULL || b != NULL);
    free(a);
    free(b);

    // Overflow test
    size_t huge = SIZE_MAX / 2 + 1;
    void *c = ft_calloc(huge, 3);
    assert(c == NULL);

    // Zero initialization test
    int *arr = (int *)ft_calloc(5, sizeof(int));
    assert(arr != NULL);
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == 0);
    }
    free(arr);

    printf("All edge case tests passed.\n");
    return 0;
} */

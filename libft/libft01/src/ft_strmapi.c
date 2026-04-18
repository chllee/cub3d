/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:40:27 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 17:50:17 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*new_str;
	int		count;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	count = 0;
	while (count < len)
	{
		new_str[count] = f(count, s[count]);
		count++;
	}
	new_str[count] = '\0';
	return (new_str);
}

/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sample transform functions:
char to_upper(unsigned int i, char c)
{
    (void)i; // ignore index
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return c;
}

char shift_char(unsigned int i, char c)
{
    return c + i; // shift character by index
}

int main(void)
{
    char *result;

    // Normal case 1: uppercase conversion
    result = ft_strmapi("hello", to_upper);
    if (result)
    {
        printf("Uppercase: %s\n", result);
        free(result);
    }

    // Normal case 2: shift characters by index
    result = ft_strmapi("abc", shift_char);
    if (result)
    {
        printf("Shifted chars: %s\n", result);
        free(result);
    }

    // Edge case: empty string
    result = ft_strmapi("", to_upper);
    if (result)
    {
        printf("Empty string: \"%s\"\n", result);
        free(result);
    }

    // Edge case: NULL string input
    result = ft_strmapi(NULL, to_upper);
    printf("NULL input string: %s\n", result == NULL ? 
	"NULL (expected)" : "Unexpected result");

    // Edge case: NULL function pointer
    result = ft_strmapi("test", NULL);
    printf("NULL function pointer: %s\n", result == NULL ? 
	"NULL (expected)" : "Unexpected result");

    // Simulated malloc failure - try large string (may or 
	may not fail depending on system)
    size_t large_size = 100000000; // 100 million chars ~100MB
    char *large_str = malloc(large_size + 1);
    if (large_str)
    {
        memset(large_str, 'a', large_size);
        large_str[large_size] = '\0';
        result = ft_strmapi(large_str, to_upper);
        if (result)
        {
            printf("Large input test: success\n");
            free(result);
        }
        else
        {
            printf("Large input test: malloc failed inside ft_strmapi or 
			returned NULL\n");
        }
        free(large_str);
    }
    else
    {
        printf("Failed to allocate large string to test malloc failure.\n");
    }

    return 0;
} */

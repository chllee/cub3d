/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:45:43 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 20:01:42 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *str, char c)
{
	int	word;
	int	count;

	word = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*str == c)
			word = 0;
		str++;
	}
	return (count);
}

char	*malloc_word(char *start, int len)
{
	char	*word;
	int		count;

	count = 0;
	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	while (count < len)
	{
		word[count] = start[count];
		count++;
	}
	word[count] = '\0';
	return (word);
}

void	free_all(char **arr, int count)
{
	while (count--)
	{
		free(arr[count]);
	}
	free(arr);
}

int	add_words(char **arr, const char *s, char c, int word_count)
{
	int		count;
	int		len;
	char	*word_start;

	count = 0;
	len = 0;
	while (*s && count < word_count)
	{
		if (*s != c && len++ == 0)
			word_start = (char *)s;
		if (((*s == c) || !*(s +1)) && len > 0)
		{
			arr[count] = malloc_word(word_start, len);
			if (!arr[count])
			{
				free_all(arr, count);
				return (0);
			}
			count++;
			len = 0;
		}
		s++;
	}
	arr[count] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**arr;

	if (!s)
		return (NULL);
	word_count = count_words((char *)s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!add_words(arr, s, c, word_count))
		return (NULL);
	return (arr);
}

/* #include <stdio.h>

int main()
{
    char **result;
    int i;

    // Test case: String with multiple separators
    char str[] = "++Hello,Wor+++ld! This-is +a test.+++";
    // char charset[] = ",-!. ";

    result = ft_split(str, '+');

    // Print each word in the result array
    printf("Splitting: \"%s\" using charset: \"%c\"\n\n", str, '+');
    i = 0;
    while (result[i])
    {
        printf("Word %d: %s\n", i + 1, result[i]);
        free(result[i]); // Free each word after printing
        i++;
    }
    free(result); // Free the main array

    return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:46:54 by pang              #+#    #+#             */
/*   Updated: 2025/05/20 17:50:00 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_isget(const char c, const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (c == str[count])
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		count;
	char	*dest;

	start = 0;
	count = -1;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && ft_isget(s1[start], set))
	{
		start++;
	}
	end = ft_strlen((char *)s1);
	while (end > start && ft_isget(s1[end - 1], set))
		end--;
	dest = malloc((end - start) + 1);
	if (!dest)
		return (NULL);
	while (++count < (end - start))
	{
		dest[count] = s1[start + count];
	}
	dest[count] = '\0';
	return (dest);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Helper to test and print results
void test_trim(const char *s1, const char *set, 
const char *expected, int test_num)
{
    char *result = ft_strtrim(s1, set);
    if ((result == NULL && expected == NULL) || 
	(result && expected && strcmp(result, expected) == 0))
    {
        printf("✅ Test %d passed: ft_strtrim(\"%s\", \"%s\") 
		= \"%s\"\n", test_num, s1 ? s1 : "NULL", set ? set : "
		NULL", result ? result : "NULL");
    }
    else
    {
        printf("❌ Test %d failed: ft_strtrim(\"%s\", \"%s\")\n", 
		test_num, s1 ? s1 : "NULL", set ? set : "NULL");
        printf("   Expected: \"%s\"\n", expected ? expected : "NULL");
        printf("   Got     : \"%s\"\n", result ? result : "NULL");
    }
    free(result);
}
int main(void)
{
    printf("=== ft_strtrim Edge Case Tests ===\n");

    test_trim("", "abc", "", 1);                     // Empty input
    test_trim("hello", "", "hello", 2);              // Empty set
    test_trim("aaaa", "a", "", 3);                   // Set trims all
    test_trim("  hello  ", " ", "hello", 4);         // Leading and 
	//trailing spaces
    test_trim("test", "xyz", "test", 5);             // No overlap
    test_trim(NULL, "abc", NULL, 6);                 // NULL input
    test_trim("hello", NULL, NULL, 7);               // NULL set
    test_trim("xx42xxx", "x", "42", 8);              // Trims part
    test_trim("   abc   ", " ", "abc", 9);           // Spaces around
    test_trim("xyabxy", "xy", "ab", 10);             // Complex trim
    test_trim("42", "42", "", 11);                   // Full match
    test_trim("trimme", "trim", "e", 12);          // Trim selective
    test_trim("edge", "eg", "d", 13);                // One char left

    return 0;
} */

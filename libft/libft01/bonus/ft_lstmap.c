/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:27:58 by pang              #+#    #+#             */
/*   Updated: 2025/09/02 18:02:09 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Example function to uppercase a string
void *to_uppercase(void *content)
{
    char *str = (char *)content;
    char *new_str = strdup(str);
    if (!new_str)
        return NULL;
    for (int i = 0; new_str[i]; i++)
        new_str[i] = toupper(new_str[i]);
    return new_str;
}

// Simple free function
void del(void *content)
{
    free(content);
}

// Print list contents
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    // Original list
    t_list *original = ft_lstnew(strdup("hello"));
    ft_lstadd_back(&original, ft_lstnew(strdup("world")));
    ft_lstadd_back(&original, ft_lstnew(strdup("libft")));

    // Apply map
    t_list *mapped = ft_lstmap(original, to_uppercase, del);

    // Print both lists
    printf("Original list:\n");
    print_list(original);
    printf("Mapped list:\n");
    print_list(mapped);

    // Clean up
    ft_lstclear(&original, del);
    ft_lstclear(&mapped, del);

    return 0;
}
 */

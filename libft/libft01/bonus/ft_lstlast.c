/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:32:55 by pang              #+#    #+#             */
/*   Updated: 2025/08/06 16:57:09 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/* #include <stdio.h>

// Helper function to create a new node
t_list *create_node(void *content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return node;
}

int main(void)
{
    t_list *node1 = create_node("First");
    t_list *node2 = create_node("Second");
    t_list *node3 = create_node("Third");

    // Link the nodes
    node1->next = node2;
    node2->next = node3;

    // Get the last node
    t_list *last = ft_lstlast(node1);

    if (last && last->content)
        printf("Last node content: %s\n", (char *)last->content);
    else
        printf("List is empty or last node has no content.\n");

    // Free memory (optional in small test but good practice)
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
 */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:22:55 by pang              #+#    #+#             */
/*   Updated: 2025/08/06 16:57:23 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/* #include <stdio.h>
#include <stdlib.h>

// Helper: create a new node
t_list *create_node(void *content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

int main(void)
{
    t_list *n1 = create_node("Node 1");
    t_list *n2 = create_node("Node 2");
    t_list *n3 = create_node("Node 3");
	t_list *n4 = create_node("Node 4");

    // Link nodes
    n1->next = n2;
    n2->next = n3;
	n3->next = n4;

    // Test ft_lstsize
    int size = ft_lstsize(n1);
    printf("List size: %d\n", size);  // Expected output: 3

    // Free memory
    free(n1);
    free(n2);
    free(n3);

    return 0;
}
 */

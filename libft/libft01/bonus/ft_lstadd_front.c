/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:17:33 by pang              #+#    #+#             */
/*   Updated: 2025/09/02 18:01:49 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int main(void)
{
	t_list *head = ft_lstnew("World");
	t_list *new_node = ft_lstnew("Hello");

	printf("Before:\n");
	printf("Head address:    %p\n", (void *)head);
	printf("New node address: %p\n\n", (void *)new_node);

	ft_lstadd_front(&head, new_node);

	printf("After:\n");
	printf("Head content: %s\n", (char *)head->content);
	printf("Head address: %p\n", (void *)head);
	printf("Next node:    %s\n", (char *)head->next->content);
}
 */

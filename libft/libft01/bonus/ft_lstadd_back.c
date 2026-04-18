/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:37:58 by pang              #+#    #+#             */
/*   Updated: 2025/09/03 14:29:38 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	curr = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new;
}

/* #include <stdio.h>
#include <stdlib.h>

// Helper: create a new node
t_list *create_node(char *content)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->content = content;
	node->next = NULL;
	return node;
}

// Helper: print list
void print_list(t_list *head)
{
	while (head)
	{
		printf("%s -> ", (char *)head->content);
		head = head->next;
	}
	printf("NULL\n");
}

int main(void)
{
	t_list *head = NULL;

	t_list *node1 = create_node("Node 1");
	t_list *node2 = create_node("Node 2");
	t_list *node3 = create_node("Node 3");

	// Add nodes to the back
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	// Print final list
	printf("Final list:\n");
	print_list(head);

	// Free memory
	while (head)
	{
		t_list *tmp = head;
		head = head->next;
		free(tmp);
	}

	return 0;
} */

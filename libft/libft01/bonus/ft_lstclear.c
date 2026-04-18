/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:01:49 by pang              #+#    #+#             */
/*   Updated: 2025/09/02 18:01:37 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*ptr;

	curr = *lst;
	if (!lst || !*lst)
		return ;
	while (curr != NULL)
	{
		ptr = curr->next;
		del(curr->content);
		free(curr);
		curr = ptr;
	}
	*lst = NULL;
}

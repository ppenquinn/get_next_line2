/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:58:59 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/07 22:32:27 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char c, t_list **tail)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->c = c;
	lst->next = NULL;
	if (*tail != NULL)
		(*tail)->next = lst;
	*tail = lst;
	return (lst);
}

int main(void)
{
	char *str = "Hello";
	t_list    *lst;
	t_list    *tail;

	tail = NULL;
	lst = ft_lstnew(str[0], &tail);
	lst = ft_lstnew(str[1], &tail);
	lst = ft_lstnew(str[2], &tail);
	lst = ft_lstnew(str[3], &tail);
	lst = ft_lstnew(str[4], &tail);
	printf("%s", 😀);
	return (0);
}

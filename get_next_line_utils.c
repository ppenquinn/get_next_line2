/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 02:43:58 by nappalav          #+#    #+#             */
/*   Updated: 2024/01/05 01:13:16 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	count_nl(char *str, ssize_t *mode)
{
	ssize_t	cnt;
	size_t	idx;
	size_t	pos;

	cnt = 0;
	idx = 0;
	pos = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
		{
			if (cnt == 0)
				pos = idx;
			cnt++;
		}
		idx++;
	}
	*mode = cnt;
	if (cnt > 0)
		return (pos);
	return (idx);
}

size_t	ft_lstlast(t_list *lst, t_list **tail)
{
	size_t	cnt;

	cnt = 0;
	if (!lst)
	{
		*tail = NULL;
		return (0);
	}
	else
	{
		if (tail)
			cnt++;
		while (lst->next != NULL && lst->c != '\n')
		{
			lst = lst->next;
			cnt++;
		}
		if (tail)
			*tail = lst;
	}
	return (cnt);
}

ssize_t	ft_free(char **str, t_list ***lst, ssize_t *mode)
{
	t_list	*temp;

	if (str)
		free(*str);
	*mode = 0;
	if (**lst)
	{
		while (**lst)
		{
			temp = **lst;
			**lst = (**lst)->next;
			free(temp);
		}
	}
	return (-1);
}

// size_t	ft_lstlast(t_list *lst, t_list **tail)
// {
// 	size_t	cnt;

// 	if (!lst)
// 	{
// 		*tail = NULL;
// 		return (0);
// 	}
// 	else
// 	{
// 		cnt = 1;
// 		while (lst->next != NULL)
// 		{
// 			lst = lst->next;
// 			cnt++;
// 		}
// 		*tail = lst;
// 	}
// 	return (cnt);
// }

// size_t	find_nl(t_list *lst)
// {
// 	size_t	pos;

// 	pos = 0;
// 	while (lst->next != NULL && lst->c != '\n')
// 	{
// 		lst = lst->next;
// 		pos++;
// 	}
// 	return (pos);
// }

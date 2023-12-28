/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 02:43:58 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/27 18:12:19 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_nl(t_list **lst, size_t pos)
{
	char	*str;
	t_list	*temp;
	size_t	i;

	i = 0;
	if (!*lst)
		return (NULL);
	str = malloc((pos + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < pos)
	{
		temp = *lst;
		str[i] = temp->c;
		*lst = (*lst)->next;
		free(temp);
		i++;
	}
	str[i] = '\0';
	return (str);
}

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
	// if (BUFFER_SIZE == 1)
	// 	return (idx);
	// else
	// 	return (idx - 1);
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

ssize_t	ft_free(char **str)
{
	free(*str);
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

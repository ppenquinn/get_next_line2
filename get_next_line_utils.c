/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 02:43:58 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/26 02:44:44 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:58:59 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/26 02:57:33 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	*ft_lstnew(char *str, t_list **tail, t_list ***head)
{
	t_list	*lst;
	size_t	i;

	i = 0;
	while (str[i])
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			return (0);
		lst->c = str[i];
		lst->next = NULL;
		if (**head == NULL)
			**head = lst;
		if (*tail != NULL)
			(*tail)->next = lst;
		*tail = lst;
		i++;
	}
	return (1);
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
	return (pos);
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

ssize_t	ft_readfile(int fd, t_list	**lst, ssize_t *mode)
{
	char	*buf;
	int		rd;
	t_list	*tail;
	size_t	pos;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	rd = BUFFER_SIZE;
	pos = ft_lstlast(*lst, &tail);
	while (*mode == 0 && rd == BUFFER_SIZE)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == 0 || rd == -1)
			return (-1);
		buf[rd] = 0;
		pos += count_nl(buf, mode) + BUFFER_SIZE;
		if (ft_lstnew(buf, &tail, &lst) == 0)
			return (-1);
	}
	return (pos - BUFFER_SIZE);
}

char	*put_nl(t_list **lst, size_t pos)
{
	char	*str;
	t_list	*temp;
	size_t	i;

	i = 0;
	str = malloc((pos + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i <= pos)
	{
		temp = *lst;
		str[i] = temp->c;
		*lst = (*lst)->next;
		free(temp);
		i++;
	}
	return (str);
}

// char	*get_next_line(int fd)
// {
// 	static ssize_t	mode;
// 	static t_list	*lst;
// 	ssize_t			pos;
// 	char			*str;

// 	if (!mode)
// 		mode = 0;
// 	if (mode == 0)
// 	{
// 		pos = ft_readfile(fd, &lst, &mode);
// 		if (pos == -1)
// 			return (NULL);
// 	}
// 	else
// 		pos = find_nl(lst);
// 	str = put_nl(&lst, pos);
// 	mode--;
// 	return (str);
// }
char	*get_next_line(int fd)
{
	static ssize_t	mode;
	static t_list	*lst;
	ssize_t			pos;
	char			*str;

	if (!mode)
		mode = 0;
	if (mode == 0)
	{
		pos = ft_readfile(fd, &lst, &mode);
		if (pos == -1)
			return (NULL);
		printf("status : READFILE\n");
		printf("position = %zu\n", pos);
		printf("-----------------------------\n");
	}
	else
	{
		//pos = find_nl(lst);
		pos = ft_lstlast(lst, NULL);
		printf("status : FIND NEW LINE\n");
		printf("position = %zu\n", pos);
		printf("-----------------------------\n");
	}
	str = put_nl(&lst, pos);
	printf("status : PUT NEW LINE\n");
	printf("string is %s\n", str);
	printf("-----------------------------\n");
	mode--;
	printf("nl is %zu left\n", mode);
	return (str);
}

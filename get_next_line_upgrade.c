/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_upgrade.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:58:59 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/23 22:47:26 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *str, t_list **tail, t_list ***head)
{
	t_list	*lst;
	size_t	i;

	i = 0;
	while (str[i])
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			return (NULL);
		lst->c = str[i];
		lst->next = NULL;
		if (**head == NULL)
			**head = lst;
		if (*tail != NULL)
			(*tail)->next = lst;
		*tail = lst;
		i++;
	}
	return (lst);
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

size_t	ft_readfile(int fd, t_list	**lst, ssize_t *mode)
{
	char	*buf;
	int		rd;
	t_list	*tail;
	size_t	pos;
	size_t	cnt;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = BUFFER_SIZE;
	tail = NULL;
	cnt = 0;
	//check error
	while (*mode == 0 && rd == BUFFER_SIZE)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		//check error
		buf[rd] = 0;
		pos = count_nl(buf, mode);
		ft_lstnew(buf, &tail, &lst);
		cnt++;
	}
	pos += (cnt - 1) * BUFFER_SIZE ;
	printf("position is %zu\n", pos);
	return (pos);
}

size_t	find_nl(t_list *lst)
{
	size_t	pos;

	while (lst->next != NULL && lst->c != '\n')
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}

char	*put_nl(t_list **lst, size_t pos)
{
	char	*str;
	t_list	*temp;
	size_t	i;

	i = 0;
	str = malloc((pos + 1) * sizeof(char));
	//check error
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
char	*get_next_line(int fd)
{
	static ssize_t	mode;
	static t_list	*lst;
	size_t			pos;
	char			*str;

	if (!mode)
		mode = 0;
	if (mode == 0)
	{
		pos = ft_readfile(fd, &lst, &mode);
		printf("status : READFILE\n");
	}
	else
		pos = find_nl(lst);
	printf("status : found pos\n");
	str = put_nl(&lst, pos);
	mode--;
	printf("line is %s\n", str);
	printf("nl is %zu left\n", mode);
	return (0);
}

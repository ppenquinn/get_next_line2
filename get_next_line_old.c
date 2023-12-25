/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:58:59 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/23 21:59:34 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *str, t_list **tail, t_list **head)
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
		if (*head == NULL)
			*head = lst;
		if (*tail != NULL)
			(*tail)->next = lst;
		*tail = lst;
		i++;
	}
	return (lst);
}

ssize_t	count_nl(char *str)
{
	ssize_t	cnt;
	size_t	idx;

	cnt = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			cnt++;
		idx++;
	}
	return (cnt);
}

t_list	*ft_readfile(int fd, t_list	*lst, ssize_t *nl)
{
	char	*buf;
	int		rd;
	t_list	*tail;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = BUFFER_SIZE;
	//check error
	while (*nl == 0 && rd == BUFFER_SIZE)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		//check error
		buf[rd] = 0;
		*nl = count_nl(buf);
		ft_lstnew(buf, &tail, &lst);
	}
	return (lst);
}

char	*get_next_line(int fd)
{
	static ssize_t	mode;
	static t_list	*lst;

	if (!mode)
		mode = 0;
	if (mode == 0)
		lst = ft_readfile(fd, lst, &mode);

	while (lst->next != NULL)
	{
		printf("%c", lst->c);
		lst = lst->next;
	}
	printf("%c\n", lst->c);
	printf("mode is %zu\n", mode);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:30:57 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/23 22:47:56 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//main test
int	main(void)
{
	int	fd;

	fd = open("text", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}

//test newlst function
// int	main(void)
// {
// 	char	*s1 = "he";
// 	char	*s2 = "LLO";
// 	t_list	*lst;
// 	t_list	*tail;

// 	lst = NULL;
// 	tail = NULL;
// 	ft_lstnew(s1, &tail, &lst);
// 	ft_lstnew(s2, &tail, &lst);
// 	while (lst->next != NULL)
// 	{
// 		printf("%c", lst->c);
// 		lst = lst->next;
// 	}
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:30:57 by nappalav          #+#    #+#             */
/*   Updated: 2023/12/28 12:07:54 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//main test
int	main(void)
{
	int	fd;
	char *str;

	fd = open("read_error.txt", O_RDONLY);
 	str = get_next_line(fd);
	while (str)
	{
		printf("RESULT is \n>>>%s",str);
		str = get_next_line(fd);
	}
	printf("%s", str);
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

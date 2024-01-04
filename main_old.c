/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:09:30 by nappalav          #+#    #+#             */
/*   Updated: 2024/01/05 01:18:49 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_test (char **str)
{
	if (str == NULL)
		printf("1");
	else
		printf("2");
}

int	main(void)
{
	char *a = "Hello";

	ft_test(&a);
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
// 		{
// 			//printf("Here\n");
// 			lst = ft_free_list(lst);
// 			mode = 0;
// 			// if (error == 2)
// 			// 	exit(0);
// 			return (NULL);
// 		}
// 	}
// 	else
// 		pos = ft_lstlast(lst, NULL);
// 	if (mode > 0)
// 		pos++;
// 	str = put_nl(&lst, pos);
// 	if (!str)
// 	{
// 		lst = ft_free_list(lst);
// 		mode = 0;
// 		return (NULL);
// 	}
// 	mode--;
// 	if (mode == -1)
// 		mode = 0;
// 	return (str);
// }

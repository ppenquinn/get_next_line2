/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nappalav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:16:51 by nappalav          #+#    #+#             */
/*   Updated: 2024/01/05 00:47:04 by nappalav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
//not use actually
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	char			c;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
ssize_t	count_nl(char *str, ssize_t *mode);
size_t	ft_lstlast(t_list *lst, t_list **tail);
ssize_t	ft_free(char **str, t_list ***lst, ssize_t *mode);

#endif

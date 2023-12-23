#include "get_next_line.h"

t_list	*ft_lstnew(char c, t_list **tail)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->c = c;
	lst->next = NULL;
	if (*tail != NULL)
		(*tail)->next = lst;
	*tail = lst;
	return (lst);
}

int main(void)
{
	char *str = "Hello";
	t_list    *lst;
	t_list    *tail;

	tail = NULL;
	lst = ft_lstnew(str[0], &tail);
	ft_lstnew(str[1], &tail);
	ft_lstnew(str[2], &tail);
	ft_lstnew(str[3], &tail);
	ft_lstnew(str[4], &tail);
	while (lst->next != NULL)
	{
		printf("%c", lst->c);
		lst = lst->next;
	}
	printf("%c", lst->c);
	return (0);
}


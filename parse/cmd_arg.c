/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 03:22:22 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/09 23:39:32 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cmd_arg(char *line, int i, t_parse *head)
{
	int		j;
	char	*nextw;

	j = i;
	nextw = nextword(line + i, &j);
	if (head->first == 0)
	{
		head->cmd = nextw;
		head->first++;
	}
	else
	{
		head->arg = ft_realloc2char(head->arg, len_envp(head->arg) + 1, 0);
		head->arg[len_envp(head->arg)] = nextw;
	}
	return (j);
}

char	**ft_realloc2char(char **src, int size, int start)
{
	char	**dest;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	dest = ft_calloc(sizeof(char *), size - start + 1);
	while (start < size)
	{
		dest[i] = ft_strdup(src[start]);
		i++;
		start++;
	}
	free_tab(src);
	return (dest);
}

t_parse	*ft_pipe(t_parse *head, int *i, t_global *global)
{
	*i += 1;
	if (head->sfile == NULL || !head->sfile)
		head->sfile = ft_strdup("NOinfile");
	ft_lstadd_back_parse(&(global->parse), ft_new_parse(global));
	head = head->next;
	return (head);
}

t_parse	*ft_parselast(t_parse *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_parse(t_parse **alst, t_parse *new)
{
	t_parse	*tmp;

	if (!*alst)
		*alst = new;
	else
	{
		tmp = ft_parselast(*alst);
		tmp->next = new;
	}
}

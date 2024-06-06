/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:31:22 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/04 19:45:07 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_slash(char *str)
{
	if (str[ft_strlen(str)] == '/')
		return (1);
	return (0);
}

char	**enov(t_list *lst)
{
	t_list	*list;
	int		size;
	char	**env;

	list = lst;
	size = ft_lstsize(list);
	env = malloc(sizeof(char *) * (size + 1));
	size = 0;
	while (lst)
	{
		env[size] = ft_concatenate(lst->name, "=");
		env[size] = ft_concatenate(env[size], lst->content);
		size++;
		lst = lst->next;
	}
	env[size] = NULL;
	return (env);
}

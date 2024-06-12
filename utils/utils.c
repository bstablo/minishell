/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:31:22 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 06:34:24 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	len_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp && envp[i] != NULL)
		i++;
	return (i);
}

int	ft_slash(char *str)
{
	if (str[ft_strlen(str)] == '/')
		return (1);
	return (0);
}

char	**enov(t_lst *lst)
{
	t_lst	*list;
	int		size;
	char	*tmp;
	char	**env;

	list = lst;
	size = ft_lstsize2(list);
	env = malloc(sizeof(char *) * (size + 1));
	size = 0;
	while (lst)
	{
		tmp = ft_concatenate(lst->name, "=");
		env[size] = ft_concatenate(tmp, lst->content);
		free(tmp);
		size++;
		lst = lst->next;
	}
	env[size] = NULL;
	return (env);
}

int	ft_lstsize2(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char	*tolower2(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd || cmd == NULL)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] >= 'A' && cmd[i] <= 'Z')
			cmd[i] += 32;
		i++;
	}
	return (cmd);
}

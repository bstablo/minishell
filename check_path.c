/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:00:34 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 06:37:31 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

char	*check_path_access(t_global *global, t_lst *lst, char *cmd)
{
	char	**tab_path;
	char	*path;
	char	*test;
	int		i;

	i = -1;
	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	tab_path = NULL;
	tab_path = split_path(lst, tab_path);
	while (tab_path && tab_path[++i])
	{
		if (!ft_slash(tab_path[i]))
		{
			test = ft_strjoin(tab_path[i], "/");
			path = ft_strjoin(test, cmd);
		}
		if (!access(path, F_OK))
			return (check_path2(tab_path, test, path));
		free(test);
		free(path);
	}
	free_tab(tab_path);
	global->status = 127;
	return (ft_strdup(""));
}

char	*check_path2(char **tab_path, char *test, char *path)
{
	free_tab(tab_path);
	free(test);
	return (path);
}

char	**split_path(t_lst *lst, char **tab_path)
{
	while (lst != NULL)
	{
		if (!strcmp(lst->name, "PATH"))
		{
			tab_path = ft_split(lst->content, ':');
			break ;
		}
		lst = lst->next;
	}
	return (tab_path);
}

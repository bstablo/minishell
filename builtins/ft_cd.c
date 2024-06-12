/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:09:10 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/11 11:32:12 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd_only(t_global *global, t_lst *lst)
{
	t_lst	*tete;
	int		i;

	tete = lst;
	i = 0;
	while (tete)
	{
		if (!ft_strcmp(tete->name, "HOME"))
		{
			i = chdir(tete->content);
			return (i);
		}
		tete = tete->next;
	}
	ft_perror(global, "cd", ": HOME not set\n", 1);
	return (i);
}

char	*findpwd(t_lst	*lst)
{
	t_lst	*list;

	list = lst;
	while (list)
	{
		if (!ft_strcmp(list->name, "PWD"))
			return (list->content);
		list = list->next;
	}
	return (ft_strdup(""));
}

static void	old_pwd(char *oldpwd, t_lst *list, t_lst *lst)
{
	free(list->content);
	if (oldpwd == NULL)
			list->content = findpwd(lst);
	else
		list->content = (oldpwd);
}

void	update_env(t_lst *lst)
{
	t_lst	*list;
	char	*oldpwd;
	char	*pwd;

	list = lst;
	oldpwd = NULL;
	pwd = getcwd(NULL, 0);
	while (list)
	{
		if (!ft_strcmp(list->name, "PWD"))
		{
			if (oldpwd == NULL)
				oldpwd = list->content;
			list->content = ft_strdup(pwd);
		}
		if (!ft_strcmp(list->name, "OLDPWD"))
			old_pwd(oldpwd, list, lst);
		list = list->next;
	}
	free(pwd);
}

void	ft_cd(t_global *global, t_parse *parse, t_lst *lst)
{
	int		res;

	res = 0;
	if (!parse->arg[0])
		res = (cd_only(global, lst));
	else if (ft_strlen(parse->flag) > 1)
		ft_perror(global, "cd", "options are not handled\n", 1);
	else
	{
		res = chdir(parse->arg[0]);
	}
	if (res == -1)
	{
		ft_perror(global, "cd:", parse->arg[0], 1);
		ft_perror(global, ": ", "no such file or directory\n", 1);
	}
	update_env(lst);
	return ;
}

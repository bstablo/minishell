/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:23:58 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/12 05:42:07 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

void	insert_env(char **envp, t_lst **lst)
{
	t_lst	*new;
	char	**tab;
	int		i;

	i = -1;
	while (envp[++i])
	{
		tab = ft_split(envp[i], '=');
		new = ft_lstnew2(tab[1], tab[0]);
		ft_lstadd_back2(lst, new);
		free(tab);
	}
	if (envp[0] == NULL)
	{
		new = ft_lstnew2(getcwd(NULL, 0), "PWD=");
		ft_lstadd_back2(lst, new);
	}
}

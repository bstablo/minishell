/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:09:10 by bstablo           #+#    #+#             */
/*   Updated: 2024/06/06 13:08:27 by bstablo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char **cmd, t_global *global)
{
	char	*home;

	home = NULL;
	if (!cmd || !cmd[0] || !cmd[1])
	{
		home = getenv("HOME");
		if (!home || !*home)
		{
			ft_putstr_fd("cd: $HOME not set \n", 2);
			global->status = 1;
			return ;
		}
		global->status = 0;
		chdir(home);
	}
	else
	{
		if (chdir(cmd[1]) < 0)
		{
			printf("cd: %s: No such file or directory\n", cmd[1]);
			global->status = 1;
			return ;
		}
	}
}

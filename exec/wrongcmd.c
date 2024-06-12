/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarenou <dcarenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:59:59 by dcarenou          #+#    #+#             */
/*   Updated: 2024/06/10 11:11:13 by dcarenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	isbuiltin(char *str)
{
	if (!ft_strcmp(str, "exit"))
		return (1);
	else if (!ft_strcmp(tolower2(str), "env"))
		return (1);
	else if (!ft_strcmp(tolower2(str), "echo"))
		return (1);
	else if (!ft_strcmp(tolower2(str), "pwd"))
		return (1);
	else if (!ft_strcmp(str, "cd"))
		return (1);
	else if (!ft_strcmp(str, "unset"))
		return (1);
	else if (!ft_strcmp(str, "export"))
		return (1);
	return (0);
}

void	wronglastcmd(t_global *global, t_parse *parse, t_lst *lst)
{
	char	*lab;
	t_parse	*temp;

	temp = parse;
	while (temp)
	{
		if (temp->indice == len_parse(global))
		{
			if (!temp->cmd || temp->cmd == NULL || temp->cmd[0] == '\0')
				return ;
			if (isbuiltin(temp->cmd) == 1)
				return ;
			lab = check_path_access(global, lst, temp->cmd);
			if (lab == NULL)
				global->status = 127;
			else
			{
				if (global->status == 127)
					global->status = 0;
				free(lab);
			}
			return ;
		}
		temp = temp->next;
	}
}
